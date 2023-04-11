/*****************************************************************************
*
* @file uart.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of UART Module
*
******************************************************************************/

#ifndef __UART_H__
#define __UART_H__

void UART_Init(void);
void UART_TransmitChar(char data);
void UART_TransmitString(char string[]);
char UART_RecieveChar(void);


#endif /* LPUART_H_ */
