/***************************************************************************//*!
*
* @file nvic.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of interrupt
*
******************************************************************************/

#ifndef __NVIC_H__
#define __NVIC_H__


void IRQ_Enable(IRQn_Type IrqNum);
void IRQ_Disable(IRQn_Type IrqNum);
void IRQ_SetPending(IRQn_Type IrqNum);
uint32_t IRQ_GetPending(IRQn_Type IrqNum);
void IRQ_ClearPending(IRQn_Type IrqNum);
void IRQ_SetPriority(IRQn_Type IrqNum, uint8_t priority);
uint8_t IRQ_GetPriority(IRQn_Type IrqNum);
uint32_t IRQ_GetActive(IRQn_Type IrqNum);

#endif
