/*****************************************************************************
*
* @file pdb.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of PDB Module
*
******************************************************************************/


#include "s32k144.h"
#include "clock.h"

/***********************************************************************
*
* @brief Init the PDB module
*
* @note set the PDB to back2back mode to trigger ADC module
*
* @return none.
*
************************************************************************/
void PDB_B2BModeInit(PDB_Type *PDB)
{
	/*1.enable bus clock*/
	if(PDB == PDB0)
		CLK_Enable(PCC_PDB0_INDEX);
	else
		CLK_Enable(PCC_PDB1_INDEX);

	/*2.general control init*/
	PDB->SC |=  PDB_SC_TRGSEL(0b1111)   //Software trigger is selected
	            | PDB_SC_PRESCALER(1)     // sysclck/(2*MULT) = 80 / (2*1) = 40MHz
	            | PDB_SC_MULT(0)
	            | PDB_SC_PDBEN(1);        //PDB enabled

	/*3.channle init*/
	PDB->CH[0].C1 |=  PDB_C1_EN(0xff)      //enable pre-trigger [0:3]
					  | PDB_C1_TOS(0x00)   //ptr-trigger bypass
					  | PDB_C1_BB(0xfe);    //enable back2back mode [1:3], [0] is start by softwre trigger

	/*4.update register*/
	PDB->SC |= PDB_SC_LDOK_MASK;
}



/***********************************************************************
*
* @brief generate a software trigger for PDB
*
* @note software trigger can restart count and generate pre-trigger out for PDB
*		pre-trigger after software trggiger is detected 2 peripheral clk.
*
* @return none.
*
************************************************************************/
void PDB_SwTrigger(void)
{
	PDB0->SC |= PDB_SC_SWTRIG_MASK;
}











