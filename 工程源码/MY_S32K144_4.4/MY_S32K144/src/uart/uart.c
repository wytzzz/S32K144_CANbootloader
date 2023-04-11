/*****************************************************************************
*
* @file uart.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of UART Module
*
******************************************************************************/

#include "s32k144.h"
#include "devassert.h"
#include "nvic.h"
#include "uart.h"
#include "clock.h"
#include "can.h"
#include "gpio.h"
#include "string.h"
#include "iap.h"

/***********************************************************************
*
* @brief Init the UART module
*
* @note : baudrate 		: 9600
* 		  stop bit 		: 1bit
* 		  packge size   : 1byte
* 		  parity check  : no
*
* @param[in]
*
* @return none.
*************************************************************************/
void UART_Init(void)
{

	/*1.init the port*/
	CLK_Enable(PCC_PORTC_INDEX);/* Enable clock for PORTC */
	PIN_Mux(PORTC, 6, PORT_MUX_ALT2);
	PIN_Mux(PORTC, 7, PORT_MUX_ALT2);


	/*2.enable clock*/
	FuncCLK_Enable(PCC_LPUART1_INDEX, SOSCDIV_CLK);  //8M
	CLK_Enable(PCC_LPUART1_INDEX);  // uart1


	/*3.Baud rate*/
    LPUART1->BAUD = 0x0F000034;  /* 9600 baud, 1 stop */
                                 /* SBNS=0: One stop bit */
    							 /* Oversampling Ratio : 16*/

    LPUART1->CTRL = 0x002C0000;  /* Enable transmitter & receiver, no parity, 8 bit char: */
    							 /*recieve inturrupt enable*/
                                 /* Receiver enabled */
                                 /* Transmitter enabled */
                                 /* parity check disable */
                                 /* 8-bit */

    /*4.enable inturrupt*/
    IRQ_Enable(LPUART1_RxTx_IRQn);

}

/***********************************************************************
* @brief UART send char data
*
* @param[in] data
*
* @return none.
*************************************************************************/
void UART_TransmitChar(char data)
{
	/* Wait for transmit buffer to be empty */
	while((LPUART1->STAT & LPUART_STAT_TDRE_MASK) == 0);

	/*send data*/
	LPUART1->DATA = data;
}

/***********************************************************************
* @brief UART send string
*
* @param[in] string[]
*
* @return none.
*************************************************************************/
void UART_TransmitString(char string[])
{
	uint32_t i=0;
	while(string[i] != '\0')
	{
		UART_TransmitChar(string[i]);
		i++;
	}
	UART_TransmitChar('\n');
}


/***********************************************************************
* @brief UART recieve string
*
* @note :¡¡it's block recieve
*
* @param[in]
*
* @return : data(1 byte)
*************************************************************************/
char UART_RecieveChar(void)
{
	char data = 0;

	/* Wait for received buffer to be full */
	while((LPUART1->STAT & LPUART_STAT_RDRF_MASK) ==0);

	/*recieve data*/
	data = LPUART1->DATA;

	return data;
}


/***********************************************************************
* @brief UART recieve IRQ
*
* @param[in]
*
* @return none
* **********************************************************************/
void LPUART1_RxTx_IRQHandler()
{
	if((LPUART1->STAT & LPUART_STAT_RDRF_MASK) == 1);
	{
		//temp = (uint8_t)LPUART1->DATA;
	}
}



