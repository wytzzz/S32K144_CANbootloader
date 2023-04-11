/*****************************************************************************
*
* @file ftm.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of FlexTimer Module
*
******************************************************************************/

#ifndef __FTM_H__
#define __FTM_H__



#include "s32k144.h"
#include "devassert.h"
#include "S32K144_features.h"
#include "nvic.h"
#include "gpio.h"
#include "clock.h"
#include "pit.h"


/*calculate the input frequency*/
uint16_t prior_value;
uint16_t current_value;
uint16_t input_frequency;


/********************************MODULE CONFIG *****************************/


/*Filter Prescaler*/
typedef enum
{
	FTM_FILT_DEVIDE_1 = 0X0u,
	FTM_FILT_DEVIDE_2 = 0X1U,
	FTM_FILT_DEVIDE_3 = 0X2U,
	FTM_FILT_DEVIDE_4 = 0X3U,
	FTM_FILT_DEVIDE_5 = 0X4U,
	FTM_FILT_DEVIDE_6 = 0X5U,
	FTM_FILT_DEVIDE_7 = 0X6U,
	FTM_FILT_DEVIDE_8 = 0X7U,
	FTM_FILT_DEVIDE_9 = 0X8U,
	FTM_FILT_DEVIDE_10 = 0X9U,
	FTM_FILT_DEVIDE_11 = 0XAU,
	FTM_FILT_DEVIDE_12 = 0XBU,
	FTM_FILT_DEVIDE_13 = 0XCU,
	FTM_FILT_DEVIDE_14 = 0XDU,
	FTM_FILT_DEVIDE_15 = 0XEU,
	FTM_FILT_DEVIDE_16 = 0XFU
}FTM_FilterPrescaler_t;

/*Channel n PWM enable bit*/
typedef enum
{
	FTM_CHANNEL_OUTPUT_DISABLE = 0U,
	FTM_CHANNEL_OUTPUT_ENABLE = 1U
}FTM_ChnlOutEnable_t;


/*Timer Overflow Interrupt Enable*/
typedef enum
{
	FTM_OVERFLOW_IRQ_DISABLE = 0U,
	FTM_OVERFLOW_IRQ_ENABLE = 1U
}FTM_OverflowIrqEnable_t;


/*Reload Point Interrupt Enable*/
typedef enum
{
	FTM_RELOAD_IRQ_DISABLE = 0U,
	FTM_RELOAD_IRQ_ENABLE = 1U
}FTM_ReloadIrqEnable_t;


/*count mode Select*/
typedef enum
{
	FTM_UP_COUNT = 0U,
	FTM_UP_DOWN_COUNT = 1U
}FTM_CountMode_t;


/*Clock Source Selection*/
typedef enum
{
	NO_CLOCK = 0X0U,
	FTM_INPUT_CLOCK = 0X1U,
	FIXED_FREQ_CLOCK = 0X2U,
	EXTERN_CLOCK = 0X3U
}FTM_ClkSource_t;


/*Clock Source Prescale Factor Selection*/
typedef enum
{
	FTM_CLKSOURCE_DEVIDE_1 = 0X0U,
	FTM_CLKSOURCE_DEVIDE_2 = 0X1U,
	FTM_CLKSOURCE_DEVIDE_4 = 0X2U,
	FTM_CLKSOURCE_DEVIDE_8 = 0X3U,
	FTM_CLKSOURCE_DEVIDE_16 = 0X4U,
	FTM_CLKSOURCE_DEVIDE_32 = 0X5U,
	FTM_CLKSOURCE_DEVIDE_64 = 0X6U,
	FTM_CLKSOURCE_DEVIDE_128 = 0X7U
}FTM_ClkSourcePrescale_t;


/******************************************CHANNEL CONFIG********************************************/



/*Trigger output enable*/
typedef enum
{
	FTM_TRG_DISABLE = 0X0U,
	FTM_TRG_ENABLE = 0X1U
}FTM_OutTriggerEnale_t;


/*Channel (n) Interrupt Enable,CHIE*/
typedef enum
{
	FTM_CHN_IRQ_DISABLE = 0X0U,
	FTM_CHN_IRQ_ENABLE = 0X1U
}FTM_ChnIrqEnable_t;

/*FTM counter reset by the selected input capture event.ICRST*/
typedef enum
{
	FTM_NOT_ERSET = 0X0U,
	FTM_RESET = 0X1U
}FTM_ChnResetInputEvent_t;

/*DMA Enable*/
typedef enum
{
	FTM_DMA_DISABLE = 0X0U,
	FTM_RESET_ENABLE = 0X1U
}FTM_ChnDMAEnable_t;


/*channel polarity vaule */
typedef enum
{
	FTM_PLO_HIGH = 0X0U,
	FTM_PLO_LOW = 0X1U
}FTM_ChnPlority_t;


/*channel outmask set */
typedef enum
{
	FTM_OUTMASK_DISABLE = 0X0U,
	FTM_OUTMASK_ENABLE = 0X1U
}FTM_ChnOutmaskEnable_t;


/*channel output initial*/
typedef enum
{
	FTM_OUTINIT_LOW = 0X0U,
	FTM_OUTINIT_HIGH = 0X1U
}FTM_ChnOutInitValue_t;

/*************************FTM mode ************************/

/*all modes the s32k144 support*/
typedef enum
{
	FTM_INPUT_CAPTURE_RISING = 0X0U,  /*Capture on Rising Edge Only*/
	FTM_INPUT_CAPTURE_FALLING = 0X1U, /*Capture on Falling Edge Only*/
	FTM_INPUT_CAPTURE_DUALEDGE = 0X2U,/*Capture on Rising or Falling Edge*/
	FTM_OUTPUT_COMPARE_TOGGLE = 0X3U, /* Output Compare ,Toggle Output on match*/
	FTM_OUTPUT_COMPARE_CLEAR = 0X4U,  /* Output Compare ,clear Output on match*/
	FTM_OUTPUT_COMPARE_SET = 0X5U,	  /* Output Compare ,set Output on match*/
	FTM_PWMMODE_EDGEALLIGNED_HIGHTRUR = 0X6U,/*Edge-Aligned PWM, High-true pulses*/
	FTM_PWMMODE_EDGEALLIGNED_LOWTRUE = 0X7U, /*Edge-Aligned PWM, Low-true pulses*/
	FTM_PWMMODE_CENTERALLIGNED_HIGHTRUR = 0X8U, /*Center-Aligned PWM, High-true pulses*/
	FTM_PWMMODE_CENTERALLIGNED_LOWTRUE = 0X9U,	/*Center-Aligned PWM, Low-true pulses*/
	FTM_PWMMODE_COMBINE_HIGHTRUR = 0XAU,	/*Combine PWM, High-true pulses*/
	FTM_PWMMODE_COMBINE_LOWTRUE = 0XBU,		/*Combine PWM, Low-true pulses*/
	FTM_PWMMODE_MODIFY_COMBINE_HIGHTRUE = 0XCU,/*Modified Combine PWM, High-true pulses*/
	FTM_PWMMODE_MODIFY_COMBINE_LOWTRUE = 0XDU, /*Modified Combine PWM, Low-true pulses*/
	FTM_INPUT_CAPTURE_DUALEDGE_ONESHOT = 0XEU, /*Dual Edge Capture, one-shot*/
	FTM_INPUT_CAPTURE_DUALEDGE_CONTINUE = 0XFU /*Dual Edge Capture, continue*/
}FTM_Mode_t;



/****************************************config structure *******************************/



/*the bits configure the channel mode*/
typedef struct
{
	uint8_t DECAP;
	uint8_t COMBINE;
	uint8_t MCOMBINE;
	uint8_t CPWMS;
	uint8_t MSB;
	uint8_t MSA;
	uint8_t ELSB;
	uint8_t	ELSA;
}FTM_ModeConfig_t;


typedef struct
{
	FTM_ChnDMAEnable_t 		 	 DMAEnable; 		 /*DMA Enable*/
	FTM_ChnResetInputEvent_t 	 InputEventReset;    /*FTM counter reset by the selected input capture event.ICRST*/
	FTM_ChnIrqEnable_t	 		 ChnIrqEnable; 	     /*Channel (n) Interrupt Enable,CHIE*/
	FTM_OutTriggerEnale_t		 OutTrgEnable;	     /*output Trigger enable */
	FTM_ChnPlority_t			 Plority;	         /*channle n plority*/
	FTM_ChnOutmaskEnable_t	 	 OutMaskEnable;      /*channle outmask enable*/
	FTM_ChnOutInitValue_t	 	 InitOutValue;  	 /*the initial output port value*/
	FTM_ChnlOutEnable_t	 	 	 OutputEnable;   	 /*Channel n PWM output enable bit*/
	uint16_t				 	 cnv;				 /*channle value*/
}FTM_ChannelConfig_t;





/******************************************FEATURE MODE******************************************/

/*Fault Interrupt Enable*/
typedef enum
{
	FTM_FAULT_IRQ_DISABLE = 0X0U,
	FTM_FAULT_IRQ_ENABLE = 0X1U
}FTM_FaultIrqEnable_t;


/*Fault Control Mode*/
typedef enum
{
	FAULTL_ALLCHN_DIABLE = 0X0U,
	FAULTL_EVENCHN_ENABLE_MANUAL_CLEAN = 0X1U,
	FAULTL_ALLCHN_ENABLE_MANUAL_CLEAN = 0X2U,
	FAULT_ALLCHN_ENABLE_AUTO_CLEAN = 0X3U
}FTM_FaultEnable_t;


/*Capture Test Mode Enable*/
typedef enum
{
	FTM_CAP_TEST_DISABLE = 0X0U,
	FTM_CAP_TEST_ENABLE = 0X1U
}FTM_CapTestEnable_t;


/*PWM Synchronization Mode*/
typedef enum
{
	FTM_PWMSYNC_FREE_TRG = 0X0U,
	FTM_PWMSYNC_STRIC_TRG = 0X1U
}FTM_PWMSync_t;


/*Write Protection Disable*/
typedef enum
{
	FTM_WR_PRO_ENABLE = 0X0U,
	FTM_WR_PRO_DISABLE = 0X1U
}FTM_WrProEnable_t;


/*Initialize The Channels Output*/
typedef enum
{
	FTM_INIT_NO_EFFECT = 0X0U,
	FTM_INIT_ACCRD_TO_OUTINT = 0X1U
}FTM_OutputInit_t;

/*FTM Enable*/
typedef enum
{
	FTM_TPM_COMPATIBLE = 0X0U,
	FTM_FEATURE_ENABLE = 0X1U
}FTM_FeatureEnable_t;




/*********************************function define***************************/
void FTM_Init(FTM_Type *FTM, uint16_t InitValue, uint16_t ModValue);
void FTM_ChnInit(FTM_Type *FTM, uint8_t ChnNum, uint16_t PwmCycleRatio);
void FTM_SetPwmRatio(FTM_Type *FTM, uint8_t ChnNum, uint16_t PwmCycleRatio);
void FTM_ClkSrcSelcect(FTM_Type* FTM, FTM_ClkSource_t ClkSrc, FTM_ClkSourcePrescale_t div);
void FTM_ModeSelect(FTM_Type *FTM, uint8_t ChnPairNum, uint8_t ChnNum, FTM_ModeConfig_t *config);
void FTM_ChnOutputMask(FTM_Type *FTM, uint8_t channle_num,  FTM_ChnOutmaskEnable_t outmask);
void FTM_ChnOutputInit(FTM_Type *FTM, uint8_t ChnNum, uint8_t value);
void FTM_ChnOutputEnble(FTM_Type *FTM, uint8_t channle_num, uint8_t value);
void FTM_ChannelConfig(FTM_Type *FTM, uint8_t ChnNum, FTM_ChannelConfig_t *config);
void FTM0_Ch0_Ch1_IRQHandler(void);
void FTM0_Ch2_Ch3_IRQHandler(void);
void FTM0_Ovf_Reload_IRQHandler(void);

















#endif
