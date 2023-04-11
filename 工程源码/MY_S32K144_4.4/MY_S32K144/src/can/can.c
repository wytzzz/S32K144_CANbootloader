/*****************************************************************************
*
* @file can.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of CAN Module
*
******************************************************************************/

#include "s32k144.h"
#include "devassert.h"
#include "nvic.h"
#include "uart.h"
#include "clock.h"
#include "can.h"
#include "gpio.h"


/*To record MBS those are used to receive data, in order to distinguish irq source*/
uint32_t mbs_recept_flag = 0;

/*received frame info*/
uint32_t  RxCODE;              /* Received message buffer code */
uint32_t  RxID;                /* Received message ID */
uint32_t  RxLENGTH;            /* Recieved message number of data bytes */
uint32_t  RxDATA[2];           /* Received message data (2 words) */
uint32_t  RxTIMESTAMP;         /* Received message time */


extern uint32_t CanBuf[5*1024];
extern uint32_t CanRevCount;
/***********************************************************************
*
* @brief Init the CAN module
*
* @param[in] CAN : CAN(0-2)
*
* @return none.
*
*************************************************************************/
void CAN_Init(CAN_Type *CAN)
{
	uint32_t i = 0;

	/*1. init clk */
	if(CAN == CAN0)
		CLK_Enable(PCC_FlexCAN0_INDEX); //enable sys_bus for can module
	else
		CLK_Enable(PCC_FlexCAN1_INDEX);
	CAN->MCR |= CAN_MCR_MDIS(1); 			//disable CAN module before init
	CAN->CTRL1 |= CAN_CTRL1_CLKSRC(CAN_OSC_CLK);  //select OSC clok 8M

	/*2. enable CAN*/
	CAN->MCR &= ~CAN_MCR_MDIS_MASK;
	CAN_IntoFreezeMode(CAN);  //set CAN into freeze mode
	//while(!(CAN0->MCR & CAN_MCR_FRZACK_MASK)); //wait CAN into freeze mode

	/*3. CAN_MCR init*/
	/*3.1 enable the abort mechanism*/
	CAN->MCR |= CAN_MCR_AEN(1);

	/*3.2 set the mux MB num : 15*/
	CAN->MCR = (CAN->MCR & ~CAN_MCR_MAXMB_MASK) | CAN_MCR_MAXMB(MAXMB-1);

	/*3.4 Enable individual Rx mask register*/
	CAN->MCR |= CAN_MCR_IRMQ(1);

	/*4. CAN_CTRL init*/
	/*4.1 CAN Bit Sample :Sample 3 times each CAN bit*/
	CAN->CTRL1 |= CAN_CTRL1_SMP(1);

	/*4.2 CAN Bit frequency : 8M /PRESDIV(1)+0 = 8M*/
	CAN->CTRL1 = (CAN0->CTRL1 & ~CAN_CTRL1_PRESDIV_MASK) | CAN_CTRL1_PRESDIV(PRESDIV);

	/*4.3  CAN bit timing param config*/
	/*RJW = 3, PSEG1 = 3, PSEG2 = 3, PROPSEG = 6,*/
	/*note : really SEG shoud Add 1 to these param*/
	BitTime_Config_t bit_config = {PROPSEG ,PSEG1, PSEG2, RJW};
	CAN_BitTimingSet(CAN, &bit_config);

	/*5. Initialize the Message buffer*/
	/*5.1 clear the message buffer*/
	for(i = 0; i < 128; i++)
	{
		CAN->RAMn[i] = 0;
	}

	/*5.2 set the Rx individual mask Register : just match ID during filter match*/
	for(i = 0; i < MAXMB ; i++)
	{
		CAN->RXIMR[i] = 0x1FFFFFFF; //just match ID
	}

	/*6.enable interrutp */
	CAN->IMASK1 = 0xFFFF; //MB[0-15] Rx and Tx IRQ enable.
	IRQ_Enable(CAN0_ORed_0_15_MB_IRQn);

	/*7.exit freeze mode*/
	CAN_ExitFreezeMode(CAN);

}


/***********************************************************************
*
* @brief  receive frame,Set the corresponding MB to receive mode
*
* @note  1.CAN0 MBS range is 0~31,CAN(1~2) MBS range is 0~15
*		 2.The standard frame ID is 11 bits and the extended frame ID is 29 bits

* @param[in]  CAN : CAN(0-2)
* 			  MBn : 0~15
* 			  ID  : ID of the message that want to be recieved.
*

* @return none.
*
*************************************************************************/
void CAN_RxFrameInit(CAN_Type *CAN, uint8_t MBn, uint32_t ID)
{

	/*Sets the message ID that want to be received*/
	CAN->RAMn[MBn*MB_SZIE + 1] = (uint32_t)(ID << 18);

	/*set MBS to reception empty*/
	CAN->RAMn[MBn*MB_SZIE + 0] = MB_Rx_EMPTY << 24;

	/*updata the MB use flag*/
	mbs_recept_flag |= 1 << MBn;

	/* Msg Buf MBn, word 0: Enable for reception */
	/* EDL,BRS,ESI=0: not used */
	/* CODE=4: MB set to RX empty */
	/* IDE=0: Standard ID */
	/* SRR, RTR, TIME STAMP = 0: not applicable */
	/* DLC: don't need to set,auto copy form received frame*/
    /* Node receives msg with the std ID */
}




/***********************************************************************
*
* @brief  MBS transmission init.
*
* @note  1.CAN0 MBS range is 0~31,CAN(1~2) MBS range is 0~15
*		 2.The standard frame ID is 11 bits and the extended frame ID is 29 bits
*
* @param[in]  CAN : CAN(0-2)
* 			  MBn : 0~15
*			  info : Tx frame information.
*
* @return none.
*
*************************************************************************/


void CAN_TxFrameInit(CAN_Type *CAN, uint8_t MBn, CAN_TxFrameInfo_t info)
{

	uint8_t i = 0;
	uint32_t temp_data = 0;
	uint8_t *pdata = info.data;
	uint8_t count = info.DLC;

	/*load the data*/
	if(count <= 4) //count 1-4  (小端转大端,低字节高位)
	{
		i = 0;
		while(i < 4) //load data
		{
			if(i < count) //actual data
			{
				temp_data |= pdata[i] << (8*(3-i));
			}
			else //fill 0
			{
				temp_data |= 0 <<(8*(3-i));
			}
			i++;
		}
		CAN->RAMn[MBn*MB_SZIE + 2] = temp_data;
	}
	else  //count 5-8  (小端转大端,低字节高位)
	{
		CAN->RAMn[MBn*MB_SZIE + 2] = (pdata[0] << 24) | (pdata[1] << 16) | (pdata[2] << 8) |  pdata[3];
		i = 4;
		uint8_t j = 0;
		while(i < 8) //load data
		{
			if(i < count)
			{
				temp_data |= pdata[i] << (8*(3-j));//actual data
			}
			else //fill 0
			{
				temp_data |= 0 <<(8*(3-j));
			}
			i++;
			j++;
		}
		CAN->RAMn[MBn*MB_SZIE + 3] = temp_data;
	}

	/*Set the message ID that  to transmission*/
	CAN->RAMn[MBn*MB_SZIE + 1] = (uint32_t)(info.ID << 18);

	/*Set MBS to transmission data frame*/
	CAN->RAMn[MBn*MB_SZIE + 0] = (1 << 22)  /* SRR=1:  It must be set to one by the user for transmission (Tx Buffers)*/
								 | (info.RTR << 20) /*remote frame flag*/
								 | (MB_Tx_DATA << 24) /* CODE=0XC: Activate msg buf to transmit */
								 | (count << 16);/*data count*/
	/* IDE = 0 : standard frame */
	/* EDL,BRS,ESI=0:  not used */
	/*TIME STAMP = 0: not applicable*/


}



/***********************************************************************
*
* @brief Change CAN mode into freeze mode
*
* @note most of register can write onlt in freeze mode,
* 		so if want to write these register, need into freeze mode
*
* @param[in]  CAN : CAN(0-2)
*
* @return none.
*
*************************************************************************/
void CAN_IntoFreezeMode(CAN_Type *CAN)
{
	/*enable freeze mode*/
	CAN->MCR |= CAN_MCR_FRZ(1);

	/*Halt FlexCAN*/
	CAN->MCR |= CAN_MCR_HALT(1);

	/*wait for into freeze mode*/
	while(!(CAN->MCR & CAN_MCR_FRZACK_MASK));
}


/***********************************************************************
*
* @brief Change CAN mode exit freeze mode
*
* @param[in]  CAN : CAN(0-2)
*
* @return none.
*
*************************************************************************/
void CAN_ExitFreezeMode(CAN_Type *CAN)
{
	CAN->MCR &= ~(0xF << CAN_MCR_HALT_SHIFT);
	while(CAN->MCR & CAN_MCR_FRZACK_MASK); //wait CAN exit freeze mode
	while(CAN->MCR & CAN_MCR_NOTRDY_MASK); //wait CAN into normal mode
}


/***********************************************************************
*
* @brief Set the CAN BIt Timing
*
* @note : these field in CTRL1 register can be written only in Freeze mode
          because it is blocked by hardware in other modes.

* @param[in]  CAN    : CAN(0-2)
*			  config : BIT_TIM structure
*
* @return none.
*
*************************************************************************/
void CAN_BitTimingSet(CAN_Type *CAN, BitTime_Config_t *config)
{
	CAN->CTRL1 = (CAN->CTRL1 & ~CAN_CTRL1_RJW_MASK)     | CAN_CTRL1_RJW(config->rjw);
	CAN->CTRL1 = (CAN->CTRL1 & ~CAN_CTRL1_PSEG1_MASK)   | CAN_CTRL1_PSEG1(config->pseg1);
	CAN->CTRL1 = (CAN->CTRL1 & ~CAN_CTRL1_PSEG2_MASK)   | CAN_CTRL1_PSEG2(config->pseg2);
	CAN->CTRL1 = (CAN->CTRL1 & ~CAN_CTRL1_PROPSEG_MASK) | CAN_CTRL1_PROPSEG(config->propseg);
}


/*****************************************************************************//*!
*
* @brief CAN0 module Tx and Rx interrupt service routine.
*
* @param none
*
* @return none
*****************************************************************************/
void CAN0_ORed_0_15_MB_IRQHandler()
{
	uint32_t irq_flag = 0;
	uint8_t count = 0;
	uint8_t free_timer = 0;
	irq_flag = CAN0->IFLAG1; //

	/*find irq source among MB(0~15)*/
	while(irq_flag >>= 1)
	{
		count++; //the num of the MBS which product irq
	}

	/* processing irq*/
	if(mbs_recept_flag & (1 << count))
	{

		/*reception data*/
		RxCODE      = (CAN0->RAMn[count * MB_SZIE + 0] & 0xF000000u) >> 24;
		RxLENGTH    = (CAN0->RAMn[count * MB_SZIE + 0] & 0xF0000u) >> 16;
		RxID        = (CAN0->RAMn[count * MB_SZIE + 1] & 0x1FFFFFFF) >> 0;
		CanBuf[CanRevCount]   = CAN0->RAMn[count * MB_SZIE + 2];
		CanBuf[CanRevCount+1]   = CAN0->RAMn[count * MB_SZIE + 3];
		CanRevCount += 2;
		RxTIMESTAMP = CAN0->RAMn[count * MB_SZIE + 0] & 0xFFFF;
		//UART_TransmitString((char *)RxDATA);
		/* Read TIMER to unlock message buffers */
		free_timer = CAN0->TIMER;
	}
	else
	{
		//UART_TransmitString("transfer data success!\n");
		/*do nothing*/
	}

	/*clear the IFLAG1 : write 1 to clear the flag ,and 0 has no effect*/
	CAN0->IFLAG1 = 0b1 << count;

}



















