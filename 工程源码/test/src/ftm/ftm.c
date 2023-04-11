/*****************************************************************************
*
* @file ftm.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of FlexTimer Module
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


/********************************************************************************
*
* @brief initial FTM module
*
* @note  FTM frequency :sysclk(80M)/8 = 10M
*
* @param[in] 	FTM        :FTM0,FTM1,FTM2,FTM3
* 				InitValue  :The start value
* 				ModValue   :The end value
*
* @return none.
*
*********************************************************************************/
void FTM_Init(FTM_Type *FTM, uint16_t InitValue, uint16_t ModValue)
{
	/*enable the clock*/
	if(FTM == FTM0)
		CLK_Enable(PCC_FTM0_INDEX);
	else if(FTM == FTM1)
		CLK_Enable(PCC_FTM1_INDEX);
	else if(FTM == FTM2)
		CLK_Enable(PCC_FTM2_INDEX);
	else
		CLK_Enable(PCC_FTM3_INDEX);

	/*disable write protection */
	FTM->MODE |= FTM_MODE_WPDIS_MASK;

	/*set MOD and COUNTIN*/
	FTM->CNTIN = InitValue;
	FTM->MOD = ModValue;

	/*reload and overflow irq enable*/
	FTM->SC &= ~FTM_SC_RIE_MASK;
	FTM->SC |= FTM_SC_RIE(1);
	FTM->SC &= ~FTM_SC_TOIE_MASK;
	FTM->SC |= FTM_SC_TOIE(1);
	if(FTM == FTM0)
		IRQ_Enable(FTM0_Ovf_Reload_IRQn);
	else if(FTM == FTM1)
		IRQ_Enable(FTM1_Ovf_Reload_IRQn);
	else if(FTM == FTM2)
		IRQ_Enable(FTM2_Ovf_Reload_IRQn);
	else
		IRQ_Enable(FTM3_Ovf_Reload_IRQn);

	/*select FTM count CLK : sysclk(80M)/8 = 10M*/
	FTM_ClkSrcSelcect(FTM, FTM_INPUT_CLOCK, FTM_CLKSOURCE_DEVIDE_8);
}

/********************************************************************************
*
* @brief initial FTM module
*
* @param[in] 	FTM        :FTM0,FTM1,FTM2,FTM3
* 				ChnNum     :0 - 7
* 				PwmCycleRatio : Between InitValue and ModValue
*
* @return none.
*
*********************************************************************************/

void FTM_ChnInit(FTM_Type *FTM, uint8_t ChnNum, uint16_t PwmCycleRatio)
{
	/*set channel MODE : Edge aligned pwm*/
	FTM->CONTROLS[ChnNum].CnSC &= ~(FTM_CnSC_MSA_MASK
						 	 	  |FTM_CnSC_MSB_MASK
								  |FTM_CnSC_ELSA_MASK
								  |FTM_CnSC_ELSB_MASK);
	FTM->CONTROLS[ChnNum].CnSC |=  FTM_CnSC_MSA(0)
						 	 	  |FTM_CnSC_MSB(1)
								  |FTM_CnSC_ELSA(0)
								  |FTM_CnSC_ELSB(1);

	/*enable channle and channle IRQ*/
	FTM->CONTROLS[ChnNum].CnSC |= FTM_CnSC_CHIE(1);
	if(ChnNum == 0 || ChnNum == 1)
	{
		IRQ_Enable(FTM0_Ch0_Ch1_IRQn);
	}
	else if(ChnNum == 2 || ChnNum == 3)
	{
		IRQ_Enable(FTM0_Ch2_Ch3_IRQn);
	}
	else if(ChnNum == 4 || ChnNum == 5)
	{
		IRQ_Enable(FTM0_Ch4_Ch5_IRQn);
	}
	else if(ChnNum == 6 || ChnNum == 7)
	{
		IRQ_Enable(FTM0_Ch6_Ch7_IRQn);
	}

	/*enable  channel output*/
	FTM_ChnOutputEnble(FTM, ChnNum, 1);
	/*initial channel output value*/
	FTM_ChnOutputInit(FTM, ChnNum, 1);

	/*set the PwmCycleRatio*/
	FTM->CONTROLS[ChnNum].CnV = PwmCycleRatio;

	/*write any value to CNT to reset FTM count and channle output update*/
	FTM->CNT = 0xFF;
}




/*********************************************************************************//*!
*
* @brief set PWM duty ratio for spcefic channel
*
* @param[in] 	FTM        :FTM0,FTM1,FTM2,FTM3
* 				ChnNum     :0 - 7
* 				PwmCycleRatio : Between InitValue and ModValue
*
* @return none.
*
*********************************************************************************/
void FTM_SetPwmRatio(FTM_Type *FTM, uint8_t ChnNum, uint16_t PwmCycleRatio)
{
	/*set the PwmCycleRatio*/
	FTM->CONTROLS[ChnNum].CnV = PwmCycleRatio;
}

/*******************************************************************************//*!
*
* @brief set the ftm moule clock source and prescale.
*
* @note call the function to select the clk source and enable start FTM counter
*
* @param[in]    FTM  : 	FTM0,FTM1,FTM2,FTM3
* @param[in]    clock_source   :      ftm clock source.
* @param[in]    clock_prescale :      prescale factor.
*
* @return none.
*
*
*********************************************************************************/
void FTM_ClkSrcSelcect(FTM_Type* FTM, FTM_ClkSource_t ClkSrc, FTM_ClkSourcePrescale_t div)
{
	/*set the clk source */
	if(ClkSrc)
	{
		FTM->SC	&= ~FTM_SC_CLKS_MASK;
		FTM->SC |= FTM_SC_CLKS(ClkSrc);
	}
	/*set the clk prescale*/
	if(div)
	{
		FTM->SC	&= ~FTM_SC_PS_MASK;
		FTM->SC |= FTM_SC_PS(div);
	}

}


/********************************************************************************
*
* @brief config ftm channel mode
*
* note  combine pwm mode   : need to set the channl(n+1) CnV
* 		input caputre mode : need to disable the output_enable
* 		output capare mode : initlal the channle outpout,can't write value to
* 							 CNT,can use SWOC to set the value
*
* @param[in]    channle_pair_num :0,1,2,3
* @param[in] 	channle_num : 0-7
* @param[in]    FTM		   :FTM0,FTM1,FTM2,FTM3
* @param[in] 	config     :mode configure structure
*
* @return none.
*
************************************************************************/
void FTM_ModeSelect(FTM_Type *FTM, uint8_t ChnPairNum, uint8_t ChnNum, FTM_ModeConfig_t *config)
{

	/*1.enable the dual edge capture mode*/
	if(config->DECAP)
	{
		FTM->COMBINE |= 1 << (uint32_t)((ChnPairNum << 3) + 2);
	}

	/*2.configure the mode*/
	/*COMBINE,MCOMBINE,DECAP*/
	FTM->COMBINE &= ~ ((1 << (uint32_t)((ChnPairNum << 3) + 0))
					  |(1 << (uint32_t)((ChnPairNum << 3) + 3))
					  |(1 << (uint32_t)((ChnPairNum << 3) + 7)));

	FTM->COMBINE |=  ((config->COMBINE  << (uint32_t)((ChnPairNum << 3) + 0))
					 |(config->DECAP    << (uint32_t)((ChnPairNum << 3) + 3))
					 |(config->MCOMBINE << (uint32_t)((ChnPairNum << 3) + 7)));

	/*CPWMS*/
	if(config->CPWMS)
	{
		FTM->SC &= ~FTM_SC_CPWMS_MASK;
		FTM->SC |= FTM_SC_CPWMS(config->CPWMS);

		/*check the CNTIN and MOD*/
		if(FTM->MOD > 0x7FF)
		{
			FTM->MOD = 0x7FF;
		}
		if(FTM->CNTIN < 0x1)
		{
			FTM->CNTIN = 0x1;
		}
	}

	/*MSB,MSA,ELSA,ELSB*/
	FTM->CONTROLS[ChnNum].CnSC &= ~(FTM_CnSC_MSA_MASK
					 	 	 	 	|FTM_CnSC_MSB_MASK
									|FTM_CnSC_ELSA_MASK
									|FTM_CnSC_ELSB_MASK);


	FTM->CONTROLS[ChnNum].CnSC |= FTM_CnSC_MSA(config->MSA)
					 	 	 	  |FTM_CnSC_MSB(config->MSB)
								  |FTM_CnSC_ELSA(config->ELSA)
								  |FTM_CnSC_ELSB(config->ELSB);

}




/*********************************************************************************//*!
*
* @brief set output mask.
*
* @param[in]    channle_num  :0 -7
* @param[in]    FTM          :FTM0,FTM1,FTM2,FTM3
* @param[in]    outmask      :FTM_OUTMASK_DISABLE
* 							  FTM_OUTMASK_ENABLE
* @return none.
*
*********************************************************************************/
void FTM_ChnOutputMask(FTM_Type *FTM, uint8_t ChnNum,  FTM_ChnOutmaskEnable_t OutMask)
{
	/*set the mask*/
	FTM->OUTMASK &= ~(uint32_t)(1 << ChnNum);
    FTM->OUTMASK |= (uint32_t)(OutMask << ChnNum);
}



/*********************************************************************************//*!
*
* @brief  Initial State For Channels Output
*
* @note   wirte any value to CNT to initial the channel output,
*         but in  ouput compare mode, need to use SWOC
*
* @param[in]    FTM     :FTM0,FTM1,FTM2,FTM3
*    			ChnNum  :0 - 7
*				value   :0,1
*
* @return none.
*
*********************************************************************************/
void FTM_ChnOutputInit(FTM_Type *FTM, uint8_t ChnNum, uint8_t value)
{
	FTM->OUTINIT &= ~(uint32_t)(1 << ChnNum);
	FTM->OUTINIT |=	(uint32_t)(value << ChnNum);
}


/*********************************************************************************//*!
*
* @brief  enable/disable channel pwm out
*
*
* @param[in]    FTM          :FTM0,FTM1,FTM2,FTM3
*    		    channle_num  :0 - 7
* 				value		 :0 : disable 1: enable
* @return none.
*
*********************************************************************************/
void FTM_ChnOutputEnble(FTM_Type *FTM, uint8_t ChnNum, uint8_t value)
{
	/*enable/disable channel pwm out*/
	FTM->SC &= ~(uint32_t)(1 << (ChnNum + 16));
	FTM->SC |= (uint32_t)(value << (uint32_t)(ChnNum + 16));
}



/********************************************************************************
*
* @brief configure channel of FTM
*
* @note if is input caputure mode, the ouput_enable must disable.
*
* @param[in]   	FTM			:FTM0,FTM1,FTM2,FTM3
*				ChnNum 		:0 - 7
*  				config      :FTM channel config structer
*
* @return none.
*
************************************************************************/
void FTM_ChannelConfig(FTM_Type *FTM, uint8_t ChnNum, FTM_ChannelConfig_t *config)
{

	/*1.channle general config*/
	/*enable the DMA*/
	if(config->DMAEnable)
	{
		FTM->CONTROLS[ChnNum].CnSC |= FTM_CnSC_DMA(1);
	}

	/*set the FTM counter reset when input event happen*/
	if(config->InputEventReset)
	{
		FTM->CONTROLS[ChnNum].CnSC |= FTM_CnSC_ICRST(1);
	}

	/*enable the channle irq*/
	if(config->ChnIrqEnable)
	{
		FTM->CONTROLS[ChnNum].CnSC |= FTM_CnSC_CHIE(1);

		/*nvic enable the irq*/
		if(ChnNum == 0 || ChnNum == 1)
			IRQ_Enable(FTM0_Ch0_Ch1_IRQn);
		else if(ChnNum == 2 || ChnNum == 3)
			IRQ_Enable(FTM0_Ch2_Ch3_IRQn);
		else if(ChnNum == 4 || ChnNum == 5)
			IRQ_Enable(FTM0_Ch4_Ch5_IRQn);
		else if(ChnNum == 6 || ChnNum == 7)
			IRQ_Enable(FTM0_Ch6_Ch7_IRQn);
	}

	/*2.set the channel ouput*/
	/* set the trigger generation on FTM channel outputs*/
	if(config->OutTrgEnable)
	{
		FTM->CONTROLS[ChnNum].CnSC |= FTM_CnSC_TRIGMODE(1);
	}

	/*initial the channel output value*/
	if(config->InitOutValue)
	{
		FTM_ChnOutputInit(FTM, ChnNum, 1);
	}

	/*set mask for channle output*/
	if(config->OutMaskEnable)
	{
		FTM_ChnOutputMask(FTM, ChnNum, 1);
	}

	/*set the globel control of output*/
	if(config->OutputEnable)
	{
		FTM_ChnOutputEnble(FTM, ChnNum, 1);
	}

	/*set the compare value*/
	FTM->CONTROLS[ChnNum].CnV = config->cnv;

	/*write any value to CNT to reset FTM count and channle output update*/
	FTM->CNT = 0xFF;
}


/*****************************************************************************//*!
*
* @brief  FTM0 ch0_ch1 channel interrupt service routine.
*
* @param  none.
*
* @return none.
*
*****************************************************************************/
void FTM0_Ch0_Ch1_IRQHandler(void)
{
	/*check and clear the flag*/
	if(FTM0->CONTROLS[0].CnSC & FTM_CnSC_CHF_MASK)
	{
		/*Ch0 irq*/
		FTM0->CONTROLS[0].CnSC &= ~FTM_CnSC_CHF_MASK;

	    /*irq function*/
		uint32_t RegValue;
		RegValue = GPIO_GetData(PTD, 0);
		RegValue = !RegValue;
		GPIO_SetData(PTD, 0, RegValue);

#if 0
		/*input capture mode IRQ : calculate the FRQ*/
		prior_value = current_value;
		current_value = FTM0->CONTROLS[0].CnV;
		input_frequency = current_value - prior_value;
#endif

	}
	if(FTM0->CONTROLS[1].CnSC & FTM_CnSC_CHF_MASK)
	{
		/*Ch1 irq*/
		FTM0->CONTROLS[1].CnSC &= ~FTM_CnSC_CHF_MASK;
	}

}

/*****************************************************************************//*!
*
* @brief  FTM0 ch2_ch3 channel interrupt service routine.
*
* @param  none.
*
* @return none.
*
*****************************************************************************/
void FTM0_Ch2_Ch3_IRQHandler(void)
{
	/*clear the flag*/
	if(FTM0->CONTROLS[0].CnSC & FTM_CnSC_CHF_MASK)
	{
		FTM0->CONTROLS[0].CnSC &= ~FTM_CnSC_CHF_MASK;
	}
	if(FTM0->CONTROLS[1].CnSC & FTM_CnSC_CHF_MASK)
	{
		FTM0->CONTROLS[1].CnSC &= ~FTM_CnSC_CHF_MASK;
	}
}


/*****************************************************************************//*!
*
* @brief  FTM0 module reload and overflow service routine.
*
* @param  none.
*
* @return none.
*
*****************************************************************************/
void FTM0_Ovf_Reload_IRQHandler(void)
{
	/*check and clear overflow flag*/
	if(FTM0->SC & FTM_SC_TOF_MASK)
	{
		FTM0->SC &= ~FTM_SC_TOF_MASK;
	}

	/*check and clear reload flag*/
	if(FTM0->SC & FTM_SC_RF_MASK)
	{
		FTM0->SC &= ~FTM_SC_RF_MASK;
	}

	/*irq func*/
#if 1
	uint32_t reg_value;
	reg_value = GPIO_GetData(PTD, 0);
	reg_value = !reg_value;
	GPIO_SetData(PTD, 0, reg_value);
#endif

}



/*****************************************************************************//*!
*
* @brief  FTM2 ch6_ch7 channel interrupt service routine.
*
* @param  none.
*
* @return none.
*
*****************************************************************************/
void FTM2_Ch6_Ch7_IRQHandler(void)
{
	/*check and clear the flag*/
	if(FTM2->CONTROLS[6].CnSC & FTM_CnSC_CHF_MASK)
	{
		/*Ch6 irq*/
		FTM2->CONTROLS[6].CnSC &= ~FTM_CnSC_CHF_MASK;
#if 0
	    /*irq function*/
		uint32_t reg_value;
		reg_value = GPIO_GetData(PTD, 0);
		reg_value = !reg_value;
		GPIO_SetData(PTD, 0, reg_value);
#endif
#if 0
		/*input ccapture calculate the FRQ*/
		prior_value = current_value;
		current_value = FTM0->CONTROLS[0].CnV;
		input_frequency = current_value - prior_value;
#endif

	}
	if(FTM2->CONTROLS[7].CnSC & FTM_CnSC_CHF_MASK)
	{
		/*Ch7 irq*/
		FTM2->CONTROLS[7].CnSC &= ~FTM_CnSC_CHF_MASK;
	}

}





































