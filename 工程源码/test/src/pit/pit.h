/***************************************************************************//*!
*
* @file lpit.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of lowpower interrupt timer
*
******************************************************************************/


#ifndef __LPIT_H__
#define __LPIT_H__

/*******************************TIMER GLOBEL MODULE***********************************/

/*pit enbale in DEBUG mode*/
typedef enum
{
	PIT_DEBUG_DISABLE = 0u,
	PIT_DEBUG_ENABLE = 1u
}PIT_DebugEnable_t;


/*pit enbale in DOZE mode*/
typedef enum
{
	PIT_DOZE_DISABLE = 0u,
	PIT_DOZE_ENABLE = 1u
}PIT_DozeEnable_t;

/********************************CHANNEL********************************************/

/*Channel Timer Interrupt Enable*/
typedef enum
{
	PIT_IRQ_DISABLE = 0u,
	PIT_IRQ_ENABLE = 1u
}PIT_IRQEnable_t;


/*Trigger Source*/
typedef enum
{
	PIT_EXT_TRG = 0u,
	PIT_INTER_TRG = 1u
}PIT_TrgSource_t;

/*Trigger select*/
typedef enum
{
	LPIT_CHAN0 = 0u,
	LPIT_CHAN1 = 1u,
	LPIT_CHAN2 = 2u,
	LPIT_CHAN3 = 3u
}PIT_TrgSelect_t;

/*Timer Reload On Trigger TROT*/
typedef enum
{
	PIT_NOTRELOAD_ON_TRG = 0u,
	PIT_RELOAD_ON_TRG = 1u
}PIT_ReloadEnable_t;


/*Timer Stop On Interrupt TSOI*/
typedef enum
{
	PIT_NOTSTOP_ON_INT = 0u,
	PIT_STOP_ON_INT = 1u
}PIT_StopCfg_t;

/*Timer Start On Trigger TSOT*/
typedef enum
{
	PIT_START_IMMEDIATE = 0u,
	PIT_START_BASEON_TRG= 1u
}PIT_StartCfg_t;


/*Timer Operation Mode*/
typedef enum
{
	BIT32_COUNT= 0x0u,
	DUAL_BIT16_COUNT = 0x1u,
	TRG_ACCMULATE = 0x2u,
	TRG_INPUT_CAPTURE = 0x3u
}PIT_TimerMode_t;


/*Chain Channel mode*/
typedef enum
{
	PIT_CHAIN_DISABLE = 0u,
	PIT_CHAIN_ENABLE = 1u
}PIT_ChainEnable_t;





/***************************************************************/

typedef struct
{
	PIT_IRQEnable_t				IrqEnable;		/*Channel Timer Interrupt Enable*/
	PIT_TrgSelect_t				TrgSelect;		/*select which channe's trig out as the channle's trigger in*/
	PIT_TrgSource_t				TrgSrc;         /*Trigger Source exter or inter*/
	PIT_ReloadEnable_t			ReloadEnable;	/*Timer Reload enable*/
	PIT_StopCfg_t				StopCfg;		/*Timer timeout config*/
	PIT_StartCfg_t				StartCfg;		/*Timer Start config*/
	PIT_TimerMode_t				TimerMode;		/*Timer Operation Mode*/
	uint32_t					timeout;
}LPIT_Config_t;


void PIT_Init(uint8_t ChnNum, uint32_t TimeOut);
void PIT_SetLoadVal(uint8_t ChnNum, uint32_t TimeOut);
void PIT_IrqClear(uint8_t ChnNum);
void PIT_Config(uint8_t ChnNum, LPIT_Config_t *pit_config);
void LPIT0_Ch0_IRQHandler(void);
#endif





























