
/***************************************************************************//*!
*
* @file wdog.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of watchdog
*

******************************************************************************/

#ifndef __WDOG_H__
#define __WDOG_H__

/*windows mode enale*/
typedef enum
{
	WDOG_WINMODE_DISABLE = 0U,
	WDOG_WINMODE_ENABLE = 1U
}WDOG_WinmodeEnable_t;


/*32bit refresh/unlock commod write ennable */
typedef enum
{
	WDOG_DWORD_DISABLE = 0u,
	WDOG_DWORD_ENABLE = 1u
}WDOG_32bitcmdEnable_t;

/*watchdog prescaler*/
typedef enum
{
	WDOG_PRESC_DISABLE = 0u,
	WDOG_PRESC_ENABLE = 1u
}WDOG_PrescalerEnable_t;


/*watchdog clock*/
typedef enum
{
	BUS_CLOCK = 0x0u,
	LPO_CLOCK = 0x1u,  //default 128k
	INTERNEL_CLOCK = 0x2u,
	EXTERNAL_CLOCK = 0x3u
}WDOG_CLKSource_t;

/*watchdog enable*/
typedef enum
{
	WDOG_DISABALE = 0u,
	WDOG_ENABLE = 1u
}WODG_Enable_t;

/*Watchdog Interrupt*/
typedef enum
{
	WDOG_IRQ_DISABLE = 0u,
	WDOG_IRQ_ENABLE = 1u
}WDOG_IRQEnable_t;


/*Allow updates*/
typedef enum
{
	WDOG_UPDATA_NOT_ALLOW = 0u,
	WDOG_UPDATA_ALLOW = 1u
}WDOG_Update_Allow_t;

/*Watchdog Test*/
typedef enum
{
	TEST_MODE_DISABLE = 0x0u,
	USER_MODE_ENABLE = 0x1u,
	LOWBIT_TEST_MODE_ENABLE = 0x2u,
	HIGHBIT_TEST_MODE_ENABLE = 0x3u,
}WDOG_TestEnable_t;

/*watchdag enbale in debug*/
typedef enum
{
	WDOG_DEBUG_DISABLE = 0u,
	WDOG_DEBUG_ENABLE = 1u
}WDOG_DebugEnable_t;

/*watchdag enbale in MCU wait mode*/
typedef enum
{
	WDOG_WAIT_DISABLE = 0u,
	WDOG_WAIT_ENABLE = 1u
}WDOG_WaitmodeEnable_t;

/*watchdag enbale in MCU stop mode*/
typedef enum
{
	WDOG_STOP_MODE_DISABLE = 0u,
	WDOG_STOP_MODE_ENBALE = 1u
}WDOG_StopmodeConfig_t;


/*wdog_config struct, the whole config of the watchdog*/
typedef struct
{
	WDOG_StopmodeConfig_t  		stopmode_config;	/*watchdag enbale in MCU stop mode*/
	WDOG_WaitmodeEnable_t		waitmode_config;	/*watchdag enbale in MCU wait mode*/
	WDOG_DebugEnable_t 			debug_enble;		/*watchdag enbale in debug*/
	WDOG_TestEnable_t			test_enable;		/*Watchdog Test*/
	WDOG_Update_Allow_t			update_allow;		/*Allow updates*/
	WDOG_IRQEnable_t			irq_config;			/*Watchdog Interrupt enable*/
	WODG_Enable_t				wdog_enable;		/*watchdog enable*/
	WDOG_CLKSource_t			clk_source;			/*watchdog clock source select*/
	WDOG_PrescalerEnable_t		prescaler_enable;	/*watchdog prescaler enable*/
	WDOG_32bitcmdEnable_t		dword_enable;		/*32bit refresh/unlock commod write ennable */
	WDOG_WinmodeEnable_t		winmode_enable;  	/*windows mode enale*/
	uint16_t					toval_value;        /*the watchdog timeout value*/
	uint16_t					window_value;		/*the minivalue to fresh the CNT in windows mode*/
}WDOG_Config_t;

void WODG_Init(uint16_t timeout);
void WODG_Config(WDOG_Config_t *wdog_config);
void WDOG_Disable(void);
void WDOG_ResetDisable(void);
void WDOG_Feed(void);
void WDOG_SetWindow(uint16_t Window);
void WDOG_SetTimeout(uint16_t Timeout);

#endif
