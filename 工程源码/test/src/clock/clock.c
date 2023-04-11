
/****************************************************************************
*
* @file clock.c
*
* @author Wuhao
*
* @brief providing APIs for clock initialize
*
*******************************************************************************/


#include "clock.h"
#include "S32K144.h"
#include "devassert.h"



/*********************************************************************************************
 * @brief initial the clock.
 * 		  VCO_CLK  : 320MHZ	  VCO_CLK = SPLL_SOURCE/(PREDIV + 1) X (MULT + 16)
 * 		  SPLL_CLK : 160MHZ   VCO_CLK = 2*SPLL_CLK.=
 * 		  CORE_CLK : 80MHZ
 *		  SYS_CLK  : 80MHZ    the max freq in RUN mode
 *		  BUS_CLK  : 40MHz    the max freq when pll as system clock source
 *		  FLASH_CLK: 26.67MHz the max freq in RUN mode
 *@param none
 *
 *@return none
 **********************************************************************************************/
void CLK_InitRunMode()
{

	uint32_t RegValue;

	/*1.configure the OSC clock*/
	while(SCG->SOSCCSR & SCG_SOSCCSR_LK_MASK);  //ensure the SOSCCSR no lock
	SCG->SOSCCSR = 0x00000000u;  //disable the osc before config


	SCG->SOSCCFG &= ~(SCG_SOSCCFG_EREFS_MASK
				   | SCG_SOSCCFG_HGO_MASK
				   | SCG_SOSCCFG_RANGE_MASK);
	SCG->SOSCCFG |= (SCG_SOSCCFG_EREFS(1)     // Internal crystal oscillator
				  | SCG_SOSCCFG_HGO(0u)     // low_gain
				  | SCG_SOSCCFG_RANGE(3)); // high frequency range 8MHz-40MHz
											//0x00000034

	SCG->SOSCDIV &= ~(SCG_SOSCDIV_SOSCDIV1_MASK
				   | SCG_SOSCDIV_SOSCDIV2_MASK);
	SCG->SOSCDIV |= (SCG_SOSCDIV_SOSCDIV1(1)     //divide by 1
				  | SCG_SOSCDIV_SOSCDIV2(1)); //divide by 1


	SCG->SOSCCSR &= ~(SCG_SOSCCSR_SOSCEN_MASK
			      | SCG_SOSCCSR_SOSCCM_MASK
				  | SCG_SOSCCSR_SOSCCMRE_MASK
				  | SCG_SOSCCSR_LK_MASK);
	SCG->SOSCCSR |= (SCG_SOSCCSR_SOSCEN(1)    //enable
				  | SCG_SOSCCSR_SOSCCM(0u)  //clock monitor disable, зЂвт
				  | SCG_SOSCCSR_SOSCCMRE(0)//clk monitor irq enable
				  | SCG_SOSCCSR_LK(0));	//unlock


	while(!(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK)); //wait for the osc clock valid



	/*2.configure the SPLL clock*/
	while(SCG->SPLLCSR & SCG_SPLLCSR_LK_MASK);  //no lock
	SCG->SPLLCSR = 0x00000000u;   //disable the spll before config


	SCG->SPLLCFG &= ~(SCG_SPLLCFG_PREDIV_MASK
				   | SCG_SPLLCFG_MULT_MASK);
	SCG->SPLLCFG |= (SCG_SPLLCFG_PREDIV(0)        //PREDIV=0 VCO_CLK = SPLL_SOURCE/(PREDIV + 1) X (MULT + 16)
				 | SCG_SPLLCFG_MULT(0b11000)); //MLT=24, VCO_CLK=320M



	SCG->SPLLDIV &= ~(SCG_SPLLDIV_SPLLDIV1_MASK
				    | SCG_SPLLDIV_SPLLDIV2_MASK);
	SCG->SPLLDIV |= (SCG_SPLLDIV_SPLLDIV1(2)   //Divide by 2 = 80M
				 	| SCG_SPLLDIV_SPLLDIV2(3));//Divide by 4 = 40M



	SCG->SPLLCSR &= ~(SCG_SPLLCSR_SPLLEN_MASK
					| SCG_SPLLCSR_SPLLCM_MASK
					| SCG_SPLLCSR_SPLLCMRE_MASK
					| SCG_SPLLCSR_LK_MASK);
	SCG->SPLLCSR |= (SCG_SPLLCSR_SPLLEN(1)       //enable
					| SCG_SPLLCSR_SPLLCM(0)   //disable clk monitor
					| SCG_SPLLCSR_SPLLCMRE(0) //clk monitor irq enable
					| SCG_SPLLCSR_LK(0));	   //no lock


	while(!(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK)); //wait for the spll clock valid

	/*3.set the clock source and div*/
	RegValue = SCG->RCCR;
	RegValue &= ~(SCG_RCCR_DIVSLOW_MASK
					| SCG_RCCR_DIVBUS_MASK
					| SCG_RCCR_DIVCORE_MASK
					| SCG_RCCR_SCS_MASK);

	RegValue |= (SCG_RCCR_DIVSLOW(0b0010)   //Divide-by-3 26.67MHz
					|SCG_RCCR_DIVBUS(0b0001) //Divide-by-2 40MHz
					|SCG_RCCR_DIVCORE(0b0001)//Divide-by-2 80MHz
					|SCG_RCCR_SCS(0b0110));  //spll_clock as the clock source
	SCG->RCCR = RegValue;

	while( (SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT != 6); //wait the clk source become spll
}

/*****************************************************************************//*!
*
* @brief enable prephrial module  gate clock.
*
* @note   1.each moudule need to enable the clock before using.
* 		  2.if the module has function clock,should config the PCS extra
* 		  3.if the PCC has FPAC,PCD bit,can configure the prescale
*
* @param  ModuleIndex :
* 						PCC_FTFC_INDEX  :see the define in the S32K144.h
* 				        PCC_DMAMUX_INDEX
* 				        PCC_FlexCAN0_INDEX
*
* @return none
*****************************************************************************/
void CLK_Enable(uint8_t ModuleIndex)
{
	/*check the input*/
	DEV_ASSERT(ModuleIndex < PCC_PCCn_COUNT);
	/*enable the clock*/
	PCC->PCCn[ModuleIndex] |= PCC_PCCn_CGC(1);
}



/*****************************************************************************//*!
*
* @brief select prephrial module functional clock source
*
* @note  1.some module has functional clock,need to selcet the clock source othwise be disable
*		 2.This field can be written only when the clock is disabled (CGC = 0).
*		 3.if the PCC has FPAC,PCD bit,can configure the prescale
* @param  ModuleIndex :
* 						PCC_FTFC_INDEX  :see the define in the S32K144.h
* 				        PCC_DMAMUX_INDEX
* 				        PCC_FlexCAN0_INDEX
*
* @return none
*****************************************************************************/
void FuncCLK_Enable(uint32_t ModuleIndex, PCC_FuncClkSrc_t ClkSrc)
{
	/*check the input*/
	DEV_ASSERT(ModuleIndex < PCC_PCCn_COUNT);

	/*enable the clock*/
	PCC->PCCn[ModuleIndex] &= ~PCC_PCCn_PCS_MASK;
	PCC->PCCn[ModuleIndex] |= PCC_PCCn_PCS(ClkSrc);
}




/********************************************************************************
*
* @brief delay
*
* @param[in]    cycles : n cycles
*
* @return none.
*
************************************************************************/
void Delay(volatile uint32_t cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}



/********************************************************************************
*
* @brief delay n ms
*
* @param[in]    MsCount : n ms
*
* @return none.
*
************************************************************************/
void DelayMs(uint32_t MsCount)
{
	uint32_t i,j;

	/*delay n ms*/
	for(i = MsCount; i > 0; i--)
    {
		for(j = ONE_MS; j > 0; j--);
    }
}






