/*****************************************************************************
*
* @file adc.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of ADC Module
*
******************************************************************************/


#include "ftm.h"
#include "s32k144.h"
#include "devassert.h"
#include "S32K144_features.h"
#include "nvic.h"
#include "gpio.h"
#include "clock.h"
#include "pit.h"
#include "adc.h"
#include "pdb.h"
#include "uart.h"




/***********************************************************************
*
* @brief Init the ADC module
*
* @note  if define PDB_TRG. ChnCount is const 8 that decided by hardware.
*
* @param[in]    ADC : ADC0 ADC1
* 				accuracy: 8/12/10 bit
* 				div: div by 1/2/4/8
* 				ChnCount 0-16
*
* @return none.
*
************************************************************************/
void ADC_Init(ADC_Type *ADC, ADC_Resolution_t accuracy, ADC_ClkDivide_t div)
{

	/*enable the bus clk*/
	if(ADC == ADC0)
	{
		FuncCLK_Enable(PCC_ADC0_INDEX, SPLLDIV_CLK); //SPLLDIV_CLK = 40Mhz
		CLK_Enable(PCC_ADC0_INDEX);
	}
	else if(ADC == ADC1)
	{
		FuncCLK_Enable(PCC_ADC1_INDEX, SPLLDIV_CLK); //SPLLDIV_CLK = 40Mhz
		CLK_Enable(PCC_ADC1_INDEX);
	}

	/*calibrate ADC first*/
	Delay(100);
	ADC_CalibrateStart(ADC);
	Delay(100);

	/*ADC collection frequency: 40Mhz/div */
	ADC->CFG1 &= ~ADC_CFG1_ADICLK_MASK;
	ADC->CFG1 = (ADC->CFG1 & ~ADC_CFG1_ADIV_MASK) | ADC_CFG1_ADIV(div);

	/*solution*/
	ADC->CFG1 = (ADC->CFG1 & ~ADC_CFG1_MODE_MASK) | ADC_CFG1_MODE(accuracy);

	/*trigger select :software*/
	ADC->SC2 = (ADC->SC2 & ~ADC_SC2_ADTRG_MASK) | ADC_SC2_ADTRG(ADC_SOFTWARE_TRIG);

	/*irq enable*/
	ADC_IRQEnable(ADC, ADC_IRQ_ENABLE);

}


/***********************************************************************
*
* @brief  read the conv erse result
*
* @param[in]  	ADC : ADC0 ADC1
* 				ChnNum: 0-16
*
* @return  converse result
*
************************************************************************/
uint16_t ADC_Converst(ADC_Type *ADC, uint8_t ChnNum)
{
	/*software trigger convert*/
	ADC_SWTrigger(ADC, ChnNum);

	/*wait converse complete*/
	while(!(ADC->SC1[ChnNum] & ADC_SC1_COCO_MASK));

	/*read the result*/
	return ADC->R[ChnNum];
}



/***********************************************************************
*
* @brief generate a software trigger for adc converse
*
* @param[in]   	ADC : ADC0 ADC1
* 				channel :  0 - 16
*
* @return none.
*
************************************************************************/
void ADC_SWTrigger(ADC_Type *ADC, uint8_t channel)
{
	ADC->SC1[0] = (ADC->SC1[0] & ~ADC_SC1_ADCH_MASK) | ADC_SC1_ADCH(channel);
}




/***********************************************************************
*
* @brief ADC IRQ enable
*
* @param[in]   ADC : ADC0 ADC1
* 			   ADC_IrqEnable_t : ADC_IRQ_DISABLE
* 								 ADC_IRQ_ENABLE
*
* @return none.
*
************************************************************************/
void ADC_IRQEnable(ADC_Type *ADC, ADC_IrqEnable_t IrqSet)
{
	/*irq enable*/
	if(IrqSet)
	{
		ADC->SC1[0] |= ADC_SC1_AIEN(1);
		if(ADC == ADC0)
		    IRQ_Enable(ADC0_IRQn);
		else
			IRQ_Enable(ADC1_IRQn);
	}
	/*irq disable*/
	else
	{
		ADC->SC1[0] &= ~ADC_SC1_AIEN_MASK;
		if(ADC == ADC0)
			IRQ_Disable(ADC0_IRQn);
		else
			IRQ_Disable(ADC1_IRQn);
	}
}



/***********************************************************************
*
* @brief hardware average function enable
*
* @param[in]   ADC : ADC0 ADC1
* 			   AvgEnable  : ADC_AVGE_DISABLE
* 								 ADC_AVGE_ENABLE
* 			   SampCount   : sample count for calculate the average
*
* @return none.
*
************************************************************************/
void ADC_AVRGEnable(ADC_Type *ADC, ADC_AverageEnable_t AvgEnable, ADC_AverageSelect_t SampCount)
{
	if(AvgEnable)
	{
		/*enable the hardware average*/
		ADC->SC3 |= ADC_SC3_AVGE(1);
		/*set the sample count to calculate the average*/
		ADC->SC3 = (ADC->SC3 & ~ADC_SC3_AVGS_MASK) | ADC_SC3_AVGS(SampCount);
	}
	else
	{
		ADC->SC3 &= ~ADC_SC3_AVGE_MASK;
	}
}


/***********************************************************************
*
* @brief auto compare function config
*
* @note : the value set to CV1 CV2 should reference solution.
* 		  greater and range can refrenrence mannul compare mode list.
*
* @param[in]  	ADC : ADC0 ADC1
				ADC_CmpConfig_t : compare mode config structure
*
* @return none.
*
************************************************************************/
void ADC_AutoCmpEnable(ADC_Type *ADC, ADC_CmpCfg_t *config)
{
	if(config->CmpEnable)
	{
		/*enable the compare function*/
		ADC->SC2 |= ADC_SC2_ACFE(1);

		/*config the cmpare mode*/
		ADC->SC2 = (ADC->SC2 & ~ADC_SC2_ACFGT_MASK) | ADC_SC2_ACFGT(config->CmpGreater);
		ADC->SC2 = (ADC->SC2 & ~ADC_SC2_ACREN_MASK) | ADC_SC2_ACREN(config->CmpRange);

		/*set the cv1 and cv2*/
		ADC->CV[0] = (uint32_t)config->cv1;
		if(config->CmpRange)
		{
			ADC->CV[1] = (uint32_t)config->cv2;
		}
	}
	else
	{
		ADC->SC2 &= ~ADC_SC2_ACFE_MASK;
	}
}



/***********************************************************************
*
* @brief  Calibration the ADC to increase the accuracy
*
* @note	  before startup converse, better Calibrate ADC
*
* @param[in]    ADC : ADC0 ADC1
*
* @return none.
*
************************************************************************/
void ADC_CalibrateStart(ADC_Type *ADC)
{
	/*init the clk for calibrate*/
	ADC->CFG1 &= ~ADC_CFG1_ADICLK_MASK; //40M
	ADC->CFG1 = (ADC->CFG1 & ~ADC_CFG1_ADIV_MASK) | ADC_CFG1_ADIV(ADC_CLKDIV_2); //20M < 50/2M

	/*clear calibrate relative register*/
	ADC->CLPS = 0x00000000;
	ADC->CLP3 = 0x00000000;
	ADC->CLP2 = 0x00000000;
	ADC->CLP1 = 0x00000000;
	ADC->CLP0 = 0x00000000;
	ADC->CLPX = 0x00000000;
	ADC->CLP9 = 0x00000000;

	/*start calibration*/
	ADC->SC3 |=   ADC_SC3_CAL(1) | ADC_SC3_AVGE(ADC_AVGE_ENABLE) | ADC_SC3_AVGS(ADC_AVGE_32SAMPLE);

	/*wait for clibration finish*/
	while(!(ADC->SC1[0] & ADC_SC1_COCO_MASK));

	/* diSable AVGE */
	ADC->SC3 &= ~ADC_SC3_AVGE_MASK;
}


/***********************************************************************
*
* @brief config the ADC module
*
* @param[in]    ADC : ADC0 ADC1
* 				ADC_Config_t : adc config structure
*
* @return none.
*
************************************************************************/
void ADC_Config(ADC_Type *ADC, ADC_Config_t *config)
{

	/*trigger select*/
	ADC->SC2 = (ADC->SC2 & ~ADC_SC2_ADTRG_MASK) | ADC_SC2_ADTRG(config->TrgSelect);

	/*continue converse*/
	ADC->SC3 = (ADC->SC3 & ~ADC_SC3_ADCO_MASK) | ADC_SC3_ADCO(config->ContinueMode);

	/*irq enable*/
	ADC_IRQEnable(ADC, config->IrqEnable);

}


/*****************************************************************************//*!
*
* @brief ADC0 module interrupt service routine
*
* @param none
*
* @return none
*****************************************************************************/
void ADC0_IRQHandler(void)
{
	ADC_Converst(ADC0, 0);
}









