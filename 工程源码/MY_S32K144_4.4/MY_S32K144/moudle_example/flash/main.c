#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"
#include "uart.h"
#include "flash.h"



int main(void)
{
	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

	/*init led*/
	GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

	/*init uart*/
	UART_Init();

	/*flash erase, program, read*/
	uint8_t array[8] = {0x12,0x34,0x56,0x78,0x00,0x00,0x00,0x00};
	uint32_t temp;

	/*1.erase sector(4kb) */
	FLASH_EraseSector(0x00004000);

	/*2.program 1 Phrase(Phrase = 8byte)*/
	FLASH_ProgramPhrase(0x00004000, array);

	/*3.read flash*/
	temp = *(uint32_t *)0x00004000;

	while(1)
	{
		/*send data*/
		UART_TransmitChar(GET_BIT_0_7(temp));
		UART_TransmitChar(GET_BIT_8_15(temp));
		UART_TransmitChar(GET_BIT_16_23(temp));
		UART_TransmitChar(GET_BIT_24_31(temp));
		DelayMs(500);
	}
}