
/****************************************************************************
*
* @file clock.h
*
* @author Wuhao
*
* @brief providing APIs for clock initialize
*
*******************************************************************************/

#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "S32K144.h"

#define   ONE_MS   8000  //about 1ms

/*PCC[CS] select the function clk*/
typedef enum
{
	OTHER_CLK   = 0X0U,
	SOSCDIV_CLK = 0X1U,
	SIRCDIV_CLK = 0X2U,
	FIRCDIV_CLK = 0X3U,
	SPLLDIV_CLK = 0X6U
}PCC_FuncClkSrc_t;


void Delay(volatile uint32_t cycles);
void DelayMs(uint32_t MsCount);
void CLK_InitRunMode();
void CLK_Enable(uint8_t ModuleIndex);
void FuncCLK_Enable(uint32_t ModuleIndex, PCC_FuncClkSrc_t ClkSrc);

#endif
