
/****************************************************************************
*
* @file watchdog.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of watchdog
*
******************************************************************************/

#include "S32K144.h"
#include "devassert.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"



/*****************************************************************************//*!
*
* @brief enable watchdog
*
* @note	 1.need to unlock the wdog before update wdog
*		 2.write to register must within 16 crycle
*		 3.clk source is LPO_CLOCK(fq¡¡:¡¡128khz)
*
* @param  timeout : wdog timeout value
*
* @return none
*
*****************************************************************************/
void WODG_Init(uint16_t timeout)
{
	/*unlock sequence*/
	WDOG->CNT = 0xD928C520;

	/*wait the unlock*/
	while(!(WDOG->CS & WDOG_CS_ULK_MASK));

	/*set the CSm,must finish within 16 crycle*/
	WDOG->CS =  ( 1 << WDOG_CS_UPDATE_SHIFT //allow update
				  | 1 << WDOG_CS_INT_SHIFT  //irq enable
				  | 1 << WDOG_CS_EN_SHIFT   //wdog enable
				  | LPO_CLOCK << WDOG_CS_CLK_SHIFT //select LPO_CLOCK as clk source
				  | 1 << WDOG_CS_CMD32EN_SHIFT);  //32bit cmd enable

	/*set the TOVAL*/
	WDOG->TOVAL = timeout;

	/*enable wdog interrupt*/
	IRQ_Enable(WDOG_EWM_IRQn);

	/*wait for the configuration valid*/
	while(!(WDOG->CS & WDOG_CS_RCS_MASK));
}

/*****************************************************************************//*!
*
* @brief config the watchdog based on parameters
*
* @note	 1.need to unlock the wdog
*		 2.write to register must within 16 crycle
*
* @param  wdog_config : watchdog config structure
*
* @return none
*
*****************************************************************************/
void WODG_Config(WDOG_Config_t *wdog_config)
{

	/*unlock sequence*/
	 WDOG->CNT = 0xD928C520;

	/*wait the unlock*/
	while(!(WDOG->CS & WDOG_CS_ULK_MASK));

	/*set the CSm,must finish within 16 crycle*/
	WDOG->CS =  ( wdog_config->stopmode_config << WDOG_CS_STOP_SHIFT
				| wdog_config->waitmode_config << WDOG_CS_WAIT_SHIFT
				| wdog_config->debug_enble << WDOG_CS_DBG_SHIFT
				| wdog_config->test_enable << WDOG_CS_TST_SHIFT
				| wdog_config->update_allow << WDOG_CS_UPDATE_SHIFT
				| wdog_config->irq_config << WDOG_CS_INT_SHIFT
				| wdog_config->wdog_enable << WDOG_CS_EN_SHIFT
				| wdog_config->clk_source << WDOG_CS_CLK_SHIFT
				| wdog_config->prescaler_enable << WDOG_CS_PRES_SHIFT
				| wdog_config->dword_enable << WDOG_CS_CMD32EN_SHIFT
				| wdog_config->winmode_enable << WDOG_CS_WIN_SHIFT);

	/*set the TOVAL*/
	WDOG->TOVAL = wdog_config->toval_value;

	/*set the WIN*/
	if(wdog_config->winmode_enable == WDOG_WINMODE_ENABLE)
	{
		/*ensure the toval > window*/
		DEV_ASSERT(wdog_config->window_value >= wdog_config->toval_value);
		WDOG->WIN = wdog_config->window_value;
	}

	/*assert open the wdog interrupt*/
	if(wdog_config->irq_config)
	{
		IRQ_Enable(WDOG_EWM_IRQn);
	}

	/*wait for the configuration valid*/
	while(!(WDOG->CS & WDOG_CS_RCS_MASK));
}





/*****************************************************************************//*!
*
* @brief Watchdog timer disable routine.
*
* @note	 1.need to unlock the wdog except for the first time
* 		 2.first time configure wdog in file starup_s32k144.S.
*
* @param  none
*
* @return none
*
*****************************************************************************/
void WDOG_Disable()
{
	/*unlock sequence*/
	WDOG->CNT = 0xD928C520;

	/*wait for unlock*/
	while((WDOG->CS & WDOG_CS_ULK_MASK) >> WDOG_CS_ULK_SHIFT  == 0);

	/*configure the watchdog*/
	WDOG->CS &= ~WDOG_CS_EN_MASK; //disable watchdog
	WDOG->CS |=	 WDOG_CS_DBG_MASK;

	/*wait for the watdog lock*/
	while((WDOG->CS & WDOG_CS_ULK_MASK) >> WDOG_CS_ULK_SHIFT  == 1);
}


/*****************************************************************************//*!
*
* @brief Watchdog timer disable routine at the first time.
*
* @note	 1.do not need to unlock the wdog at the first time.
*		 2.need to write the value to all register to ensure
*		   the new configurition valid.
* @param  none
*
* @return none
*
*****************************************************************************/
void WDOG_ResetDisable()
{
	/*write to the CS register*/
	WDOG->CS &= ~WDOG_CS_EN_MASK;

	/*write to the TOVAL*/
	WDOG->TOVAL = 0xFFFF;

	/*wait for the watdog lock*/
	while((WDOG->CS & WDOG_CS_ULK_MASK) >> WDOG_CS_ULK_SHIFT  == 1);

	/*wait for the configuration valid */
	while((WDOG->CS & WDOG_CS_RCS_MASK) >> WDOG_CS_RCS_SHIFT == 0);
}


/*****************************************************************************//*!
*
* @brief refresh the wdog CNT.
*
* @param none
*
* @return none
*
*****************************************************************************/
void WDOG_Feed()
 {
	 WDOG->CNT = 0xB480A602; // refresh watchdog
 }


/*****************************************************************************//*!
*
* @brief set window value for wdog.
*
* @note WIN is 16bit wide
*
* @param Window window value to WIN register.
*
* @return none
*
*****************************************************************************/

void WDOG_SetWindow(uint16_t Window)
{
	/*unlock watchdog*/
	WDOG->CNT = 0xD928C520;

	/*wait the unlock*/
	while(!(WDOG->CS & WDOG_CS_ULK_MASK));

	/*set the Window to WIN*/
    WDOG->WIN = Window;
}



/*****************************************************************************//*!
*
* @brief set time out value for wdog.
*
* @note TOVAL is 16bit wide
*
* @param[in] Timeout  value to TOVAL register.
*
* @return none
*
*****************************************************************************/

void WDOG_SetTimeout(uint16_t Timeout)
{

	/*unlock watchdog*/
	WDOG->CNT = 0xD928C520;

	/*wait the unlock*/
	while(!(WDOG->CS & WDOG_CS_ULK_MASK));

	/*set the Timeout to TOVAL*/
    WDOG->TOVAL  = Timeout;
}


/*****************************************************************************//*!
*
* @brief wodg module interrupt service routine
*
* @note when into the wdog interrupt service routine,the cpu will reset after 128 bus_clock
*
* @param none
*
* @return none
*****************************************************************************/

void WDOG_EWM_IRQHandler(void)
{
	/*unlock watchdog*/
	WDOG->CNT = 0xD928C520;

	/*wait the unlock*/
	while(!(WDOG->CS & WDOG_CS_ULK_MASK));

	/*clear the irq flag*/
	WDOG->CS |= WDOG_CS_FLG(1);

	/*open the green led*/
	GPIO_SetData(PTD, 16, 0);

}








