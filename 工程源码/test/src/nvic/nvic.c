/***************************************************************************//*!
*
* @file nvic.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of interrupt
*
******************************************************************************/


#include "s32k144.h"
#include "nvic.h"
#include "devassert.h"
#include "S32K144_features.h"



/***********************************************************************************************
*
* @brief    Enable_Interrupt(UINT8 vector_number).
*
* @note     IrqNum should >= 0
*
* @param    IrqNum Module: interrupt number from the interrupts vector table
*
* @return   none
*
************************************************************************************************/
void IRQ_Enable(IRQn_Type IrqNum)
{
	/* Check IRQ number */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	/* Clear pending interrupt register */
	S32_NVIC->ICPR[(uint32_t)IrqNum >> 5u] = 1u << ((uint32_t)IrqNum & 0x1fu);

	/* set the enable interrupt register*/
	S32_NVIC->ISER[(uint32_t)IrqNum >> 5u] = 1u << ((uint32_t)IrqNum & 0x1fu);
}

/***********************************************************************************************
*
* @brief    Disable_Interrupt(UINT8 vector_number).
*
* @note     IrqNum should >= 0
*
* @param    IrqNum Module interrupt number from the interrupts vector table
*
* @return   none
*
************************************************************************************************/
void IRQ_Disable(IRQn_Type IrqNum)
{
	/* Check IRQ number */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	/* set the disable interrupt register*/
	S32_NVIC->ICER[(uint32_t)IrqNum >> 5u] = 1u << ((uint32_t)IrqNum & 0x1fu);
}


/***********************************************************************************************
*
* @brief    set irq pending register
*
* @note     IrqNum should >= 0
*
* @param    IrqNum Module interrupt number from the interrupts vector table
*
* @return   none
*
************************************************************************************************/
void IRQ_SetPending(IRQn_Type IrqNum)
{
	/* Check IRQ number */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	/* set the pending interrupt register*/
	S32_NVIC->ISPR[(uint32_t)IrqNum >> 5u] = 1u << ((uint32_t)IrqNum & 0x1fu);
}


/***********************************************************************************************
*
* @brief    get irq pending state
*
* @note     IrqNum should >= 0
*
* @param    IrqNum  :Module interrupt number from the interrupts vector table
*
* @return   1 pending
* 			0 not pending
*
************************************************************************************************/
uint32_t IRQ_GetPending(IRQn_Type IrqNum)
{
	uint32_t ret = 0;
	/* Check IRQ number */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	/* get the pending interrupt register state*/
	ret = (uint32_t)(S32_NVIC->ISPR[(uint32_t)IrqNum >> 5u] >> ((uint32_t)IrqNum & 0x1fu)) & 1u;
	return ret;
}

/***********************************************************************************************
*
* @brief    clear irq pending  register
*
* @note     IrqNum should >= 0
*
* @param    IrqNum Module interrupt number from the interrupts vector table
*
* @return   none
*
************************************************************************************************/
void IRQ_ClearPending(IRQn_Type IrqNum)
{
	/* Check IRQ number */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	/* clear the pending interrupt register*/
	S32_NVIC->ICPR[(uint32_t)IrqNum >> 5u] = 1u << ((uint32_t)IrqNum & 0x1fu);
}


/***********************************************************************************************
*
* @brief    set device irq priority
*
* @note     IrqNum should >= 0
* 			priority shoud >=0 and <=16
*
* @param    IrqNum  :Module interrupt number from the interrupts vector table
* @param 	priority : 0-16
*
* @return   none
*
************************************************************************************************/
void IRQ_SetPriority(IRQn_Type IrqNum, uint8_t priority)
{
	/* Check input */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h
	DEV_ASSERT((priority >= 0) && (priority <= (1u << FEATURE_NVIC_PRIO_BITS)));

	uint8_t shift;
	shift = (uint8_t)8 - FEATURE_NVIC_PRIO_BITS;

	/*set the Priority register*/
	S32_NVIC->IP[(uint32_t)IrqNum] = (uint8_t)(priority << shift);
}


/***********************************************************************************************
*
* @brief    get device irq priority
*
* @note     IrqNum should >= 0
*
* @param    IrqNum  :Module interrupt number from the interrupts vector table
*
* @return   priority
*
************************************************************************************************/
uint8_t IRQ_GetPriority(IRQn_Type IrqNum)
{
	/* Check input */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	uint8_t shift;
	shift = (uint8_t)8 - FEATURE_NVIC_PRIO_BITS;

	/*get the Priority */
	return (uint8_t)(S32_NVIC->IP[(uint32_t)IrqNum] >> shift);
}

/***********************************************************************************************
*
* @brief    get device irq active state
*
* @note     IrqNum should >= 0
*
* @param    IrqNum  :Module interrupt number from the interrupts vector table
*
* @return   1 active
* 			0 not active
*
************************************************************************************************/
uint32_t IRQ_GetActive(IRQn_Type IrqNum)
{
	/* Check input */
	DEV_ASSERT((IrqNum >= 0) && (IrqNum <= FEATURE_INTERRUPT_IRQ_MAX)); //define in s32k144_feature.h

	/*get the active state*/
	return (uint32_t)(S32_NVIC->IABR[IrqNum >> 5u] & (1u << (IrqNum & 0x1fu)));
}





