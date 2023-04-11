/***************************************************************************//*!
*
* @file lpit.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of lowpower interrupt timer
*
******************************************************************************/

#include "s32k144.h"
#include "devassert.h"
#include "S32K144_features.h"
#include "nvic.h"
#include "gpio.h"
#include "clock.h"
#include "pit.h"


/***********************************************************************************************
*
* @brief    initial the pit module
*
* @note     1.the function clk source is SPLL2_DIV2_CLK (40Mhz)
*
* @param 	ChnNum : 0 - 3
*			timeout: timeout value
*
* @return   none
*
************************************************************************************************/
void PIT_Init(uint8_t ChnNum, uint32_t TimeOut)
{
	/*1.enable the clock*/
	FuncCLK_Enable(PCC_LPIT_INDEX, SPLLDIV_CLK);  /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
	CLK_Enable(PCC_LPIT_INDEX);
	LPIT0->MCR |=  LPIT_MCR_M_CEN(1);

	/*2.wait mini 4 clock for clk sync*/
	Delay(4);

	/*3.timer mode*/
	LPIT0->TMR[ChnNum].TCTRL = ( LPIT0->TMR[ChnNum].TCTRL & ~LPIT_TMR_TCTRL_MODE_MASK)
							   | LPIT_TMR_TCTRL_MODE(BIT32_COUNT);

	/*4.set the timer timeout value*/
	LPIT0->TMR[ChnNum].TVAL = TimeOut;

	/*5.enable the interrupt*/
	LPIT0->MIER |= 1u << ChnNum;
	IRQ_Enable(LPIT0_Ch0_IRQn + ChnNum);

	/*6.enable the channel*/
	LPIT0->TMR[ChnNum].TCTRL |= LPIT_TMR_TCTRL_T_EN(1);
}




/*****************************************************************************//*!
*
* @brief  set the timeout value
*
* @note: the timer count down until the timer reaches 0, then the timer will
* 		  generate an interrupt and load the Timer Value register (TVALn) value again.
*
* @param  ChnNum: 0-3
*
* @return none
*****************************************************************************/
void PIT_SetLoadVal(uint8_t ChnNum, uint32_t TimeOut)
{
	LPIT0->TMR[ChnNum].TVAL = TimeOut;
}


/*****************************************************************************//*!
* @brief clear the irq_flag for the ChnNum's irq
*
* @param ChnNum :0 - 3
*
* @return none
*****************************************************************************/
void PIT_IrqClear(uint8_t ChnNum)
{
	LPIT0->MSR |= 1 << ChnNum;
}




/***********************************************************************************************
*
* @brief    config the pit module
*
* @note     the function clk source is SPLL2_DIV2_CLK (40Mhz)
*
* @param    PitCfg : pit config structure
*			ChnNum :  0 - 3
*
* @return   none
*
************************************************************************************************/
void Pit_Config(uint8_t ChnNum, LPIT_Config_t *PitCfg)
{
	/*config the channel register*/
	/*timer mode*/
	LPIT0->TMR[ChnNum].TCTRL = ( LPIT0->TMR[ChnNum].TCTRL & ~LPIT_TMR_TCTRL_MODE_MASK)
									| LPIT_TMR_TCTRL_MODE(PitCfg->TimerMode);

	/*trigger source config*/
	LPIT0->TMR[ChnNum].TCTRL = ( LPIT0->TMR[ChnNum].TCTRL & ~LPIT_TMR_TCTRL_TRG_SRC_MASK)
									| LPIT_TMR_TCTRL_TRG_SRC(PitCfg->TrgSrc);
	LPIT0->TMR[ChnNum].TCTRL = ( LPIT0->TMR[ChnNum].TCTRL & ~LPIT_TMR_TCTRL_TRG_SEL_MASK)
									| LPIT_TMR_TCTRL_TRG_SEL(PitCfg->TrgSelect);

	/*trigger control TROT TOSI TSOT*/
	LPIT0->TMR[ChnNum].TCTRL &= ~( LPIT_TMR_TCTRL_TROT_MASK
									  | LPIT_TMR_TCTRL_TSOI_MASK
									  | LPIT_TMR_TCTRL_TSOT_MASK);

	LPIT0->TMR[ChnNum].TCTRL |=   LPIT_TMR_TCTRL_TROT(PitCfg->ReloadEnable)
									 | LPIT_TMR_TCTRL_TSOI(PitCfg->StopCfg)
									 | LPIT_TMR_TCTRL_TSOT(PitCfg->StartCfg);


	/*set the timer timeout value*/
	 LPIT0->TMR[ChnNum].TVAL = PitCfg->timeout;

	/*config the interrupt*/
	if(PitCfg->IrqEnable)
	{
		LPIT0->MIER |= 1u << ChnNum;
		IRQ_Enable(LPIT0_Ch0_IRQn + ChnNum);
	}
	else
		IRQ_Disable(LPIT0_Ch0_IRQn + ChnNum);

	/*enable the channel*/
	LPIT0->TMR[ChnNum].TCTRL |= LPIT_TMR_TCTRL_T_EN(1);
}


/*****************************************************************************//*!
*
* @brief pit module channel 0  interrupt service routine
*
* @param none
*
* @return none
*****************************************************************************/
void LPIT0_Ch0_IRQHandler(void)
{
	uint32_t RegValue;

   /*clear the irq flag*/
	PIT_IrqClear(0);

   /*irq function*/
	RegValue = GPIO_GetData(PTD, 0);
	RegValue = !RegValue;
	GPIO_SetData(PTD, 0, RegValue);
}

void LPIT0_Ch1_IRQHandler(void)
{;}
void LPIT0_Ch2_IRQHandler(void)
{;}
void LPIT0_Ch3_IRQHandler(void)
{;}





