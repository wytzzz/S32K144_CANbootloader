/*****************************************************************************
*
* @file adc.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of ADC Module
*
******************************************************************************/

#ifndef __ADC_H__
#define __ADC_H__




#define   DEFAULT_SAMPLE_TIME     12   //default sample time = 12 adc_clk

/*Interrupt Enable*/
typedef enum
{
	ADC_IRQ_DISABLE = 0U,
	ADC_IRQ_ENABLE = 1U
}ADC_IrqEnable_t;



/*Clock Divide Select*/
typedef enum
{
	ADC_CLKDIV_1 = 0U,
	ADC_CLKDIV_2 = 1U,
	ADC_CLKDIV_4 = 2U,
	ADC_CLKDIV_8 = 3U
}ADC_ClkDivide_t;


/*Input Clock Select*/
typedef enum
{
	ALTCLK_1 = 0U,
}ADC_ClkSelect_t;


/*resolution ratio*/
typedef enum
{
	ADC_8BIT = 0U,
	ADC_12BIT = 1U,
	ADC_10BIT = 2U,
}ADC_Resolution_t;



/*Conversion Trigger Select*/
typedef enum
{
	ADC_SOFTWARE_TRIG = 0U,
	ADC_HARDWARE_TRIG = 1U,
}ADC_TrgSelect_t;


/*Compare Function Enable*/
typedef enum
{
	ADC_CMP_DISABLE = 0U,
	ADC_CMP_ENABLE = 1U,
}ADC_CmpEnable_t;


/*DMA Enable*/
typedef enum
{
	ADC_DMA_DISABLE = 0U,
	ADC_DMA_ENABLE = 1U,
}ADC_DMAEnable_t;


/*Continuous Conversion Enable*/
typedef enum
{
	ADC_CONTINUE_DISABLE = 0U,
	ADC_CONTINUE_ENABLE = 1U,
}ADC_ContinueEnable_t;


/*Hardware Average Enable*/
typedef enum
{
	ADC_AVGE_DISABLE = 0U,
	ADC_AVGE_ENABLE = 1U,
}ADC_AverageEnable_t;


/*Hardware Average Select*/
typedef enum
{
	ADC_AVGE_4SAMPLE = 0U,
	ADC_AVGE_8SAMPLE = 1U,
	ADC_AVGE_16SAMPLE = 2U,
	ADC_AVGE_32SAMPLE = 3U
}ADC_AverageSelect_t;



/*adc init config*/
typedef struct
{
	ADC_TrgSelect_t    		 TrgSelect;       /*select the trigger for strt adc converse*/
	ADC_ContinueEnable_t	 ContinueMode;    /*enable the continue converse function*/
	ADC_IrqEnable_t			 IrqEnable;       /*enable the adc irq*/
}ADC_Config_t;



/*auto compare function*/
typedef struct
{
	ADC_CmpEnable_t CmpEnable;  /*enable cmp funciton*/
	uint8_t 		CmpGreater; /*cmp_greater and cmp_range determine the result's relative with */
	uint8_t			CmpRange;   /*cv1 and cv2, please refrence the "compare modes" list in S32l_RM.pdf*/
	uint16_t		cv1;
	uint16_t		cv2;
}ADC_CmpCfg_t;




void ADC_Init(ADC_Type *ADC, ADC_Resolution_t accuracy, ADC_ClkDivide_t div);
uint16_t ADC_Converst(ADC_Type *ADC, uint8_t ChnNum);
void ADC_IRQEnable(ADC_Type *ADC, ADC_IrqEnable_t IrqSet);
void ADC_AVRGEnable(ADC_Type *ADC, ADC_AverageEnable_t AvgEnable, ADC_AverageSelect_t SampCount);
void ADC_AutoCmpEnable(ADC_Type *ADC, ADC_CmpCfg_t *config);
void ADC_Config(ADC_Type *ADC, ADC_Config_t *config);
void ADC_CalibrateStart(ADC_Type *ADC);
void ADC_DMAEnable(ADC_Type *ADC, ADC_DMAEnable_t DMASet);
void ADC_SWTrigger(ADC_Type *ADC, uint8_t channel);
void ADC0_IRQHandler(void);

#endif




