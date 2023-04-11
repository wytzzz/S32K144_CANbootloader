/*****************************************************************************
*
* @file can.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of CAN Module
*
******************************************************************************/


#ifndef  __CAN_H__
#define  __CAN_H__


/*The amount of MB used*/
#define  MAXMB 16
/*Message buffer size: each MB size is 16 byte when payload sizes is 8 byte*/
/*Message buffer size(u32) = frame header(u32*2) + payload(u8*8 = u32*2)*/
#define MB_SZIE 4
/*MB's data field size : each MB can select for 8/16/32/64 byte data field,but capcity of all MBS's maintain constant*/
#define PAYLOAD 8  //reset default 8 byte
/*BIT timing : 7 + 4 + 4 + 1= 16  baudrate: 8M/16 = 500kb/s*/
#define  PRESDIV  0          /*CAN Bit frequency prescale*/
#define  PROPSEG  6	         /*Propagation Segment Time = (PROPSEG + 1) ¡Á Time-Quanta.*/
#define  PSEG1	  3	         /*Phase Buffer Segment 1 = (PSEG1 + 1) ¡Á Time-Quanta.*/
#define  PSEG2	  3	   		 /*Phase Buffer Segment 2 = (PSEG2 + 1) ¡Á Time-Quanta.*/
#define  RJW      3          /*Resync Jump Width = RJW + 1*/


/***********************structer******************/
/*1. CAN bit timing config structure*/
typedef struct
{
	uint32_t propseg; //PROPSEG
	uint32_t pseg1;   //PSEG1
	uint32_t pseg2;   //PSEG2
	uint32_t rjw;  	  //RJW
}BitTime_Config_t;


/*Tx data frame structure*/
typedef struct
{
	uint32_t ID;    //frame ID : standard_frame 11 bitwide/ extend_frame 29 bitwide
	uint8_t *data;  //date to transmit :mux 8 byte
	uint8_t DLC;    /* DLC: the data count to transmission*/
	uint8_t RTR;	//0 : data frame   1:remote frame
}CAN_TxFrameInfo_t;


/*Tx code*/
typedef enum
{
	MB_Tx_INACTIVE  = 0b1000, //MB does not participate in arbitration process.
	MB_Tx_ABORT     = 0b1001, //MB does not participate in arbitration process.
	MB_Tx_DATA      = 0b1100, //Transmit data frameunconditionally once
	MB_Tx_REMOTE    = 0b1100, //Transmit remote request frame unconditionally once
	MB_Tx_TANSEER   = 0b1110, //Transmit remote response frame ,CAN controller will auto change to MB_Tx_TANSEER
}CAN_TxCode_t;

/*Rx code*/
typedef enum
{
	MB_Rx_INACTIVE = 0b0000,  //MB does not participate in th ematching process
	MB_Rx_EMPTY    = 0b0100,  //MB is empty,and ready to recive data
	MB_Rx_FULL     = 0b0010,  //MB is full
	MB_Rx_OVERRUN  = 0b0110,  //MB is overrun
	MB_Rx_RANSWER  = 0B1010   //MB Waits to receive remote frames
}CAN_RxCode_t;


/*freeze mode enable*/
typedef enum
{
	CAN_FRZ_DISABLE = 0U,
	CAN_FRZ_ENABLE  = 1U
}CAN_FrzEnable_t;


/*Rx FIFO enable*/
typedef enum
{
	CAN_Rx_FIFO_DISABLE = 0U,
	CAN_Rx_FIFO_ENABLE = 1U
}CAN_RxFifoEnable_t;


/*CAN access mode*/
typedef enum
{
	CAN_USER_MODE= 0U,
	CAN_SUP_MODE = 1U
}CAN_AccessMode_t;

/*Warning Interrupt enable*/
typedef enum
{
	CAN_WARNING_IRQ_DISABLE= 0U,
	CAN_WARNING_IRQ_ENABLE = 1U
}CAN_WarnIrqEnable_t;


/*Self Reception enable*/
typedef enum
{
	CAN_SELF_RECEPT_ENABLE= 0U,
	CAN_SELF_RECEPT_DISABLE = 1U
}CAN_SelfReceptEnable_t;

/*Individual Rx Masking And Queue Enable*/
typedef enum
{
	CAN_INDIV_MASK_DISABLE= 0U,
	CAN_INDIV_MASK_ENABLE = 1U
}CAN_IndivMaskEnable_t;

/*DMA Enable*/
typedef enum
{
	CAN_DMA_DISABLE= 0U,
	CAN_DMA_ENABLE = 1U
}CAN_DMAEnable_t;

/*Local Priority Enable*/
typedef enum
{
	CAN_LOCAL_PRIOR_DISABLE= 0U,
	CAN_LOCAL_PRIOR_ENABLE = 1U
}CAN_LocalPriorEnable_t;


/*Abort Enable*/
typedef enum
{
	CAN_ABORT_DISABLE= 0U,
	CAN_ABORT_ENABLE = 1U
}CAN_AbortEnable_t;


/*Bus Off Interrupt Mask*/
typedef enum
{
	CAN_BUSOFF_IRQ_DISABLE = 0U,
	CAN_BUSOFF_IRQ_ENABLE  = 1U
}CAN_BusoffIrqEnable_t;


/*Error Interrupt Mask*/
typedef enum
{
	CAN_ERROR_IRQ_DISABLE = 0U,
	CAN_ERROR_IRQ_ENABLE  = 1U
}CAN_ErrorIrqEnable_t;

/*CAN Clock Source*/
typedef enum
{
	CAN_OSC_CLK    = 0U,
	CAN_PERPHERAL_CLK = 1U
}CAN_ClkSource_t;


/*Loop Back Mode*/
typedef enum
{
	CAN_LOOP_MODE_DISABLE = 0U,
	CAN_LOOP_MODE_ENABLE  = 1U
}CAN_LoopModeEnable_t;


/*Tx Warning Interrupt Mask*/
typedef enum
{
	CAN_TxWARN_IRQ_DISABLE = 0U,
	CAN_TxWARN_IRQ_ENABLE  = 1U
}CAN_TxWarnIrqEnable_t;


/*Rx Warning Interrupt Mask*/
typedef enum
{
	CAN_RxWARN_IRQ_DISABLE = 0U,
	CAN_RxWARN_IRQ_ENABLE  = 1U
}CAN_RxWarnIrqEnable_t;


/*Selects the time tick source used for incrementing the Free Running Timer counter*/
typedef enum
{
	CAN_BIT_CLK = 0U,
	CAN_EXTERAL_CLK  = 1U
}CAN_FreerunTimSrc_t;



void CAN_Init(CAN_Type *CAN);
void CAN_RxFrameInit(CAN_Type *CAN, uint8_t MBn, uint32_t ID);
void CAN_TxFrameInit(CAN_Type *CAN, uint8_t MBn, CAN_TxFrameInfo_t info);
void CAN_IntoFreezeMode(CAN_Type *CAN);
void CAN_ExitFreezeMode(CAN_Type *CAN);
void CAN_BitTimingSet(CAN_Type *CAN, BitTime_Config_t *config);



#endif












