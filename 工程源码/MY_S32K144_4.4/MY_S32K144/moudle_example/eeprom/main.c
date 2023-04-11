#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"
#include "uart.h"
#include "flash.h"


int main(void)
{
	uint32_t temp = 0xab;
	uint32_t data;
	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

	/*init led*/
	GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

	/*init uart*/
	UART_Init();

	/*init EEPROM*/
	EEPROM_Init();

	/*1.read eeprom*/
	data = EEPROM_Read(0x14000000); //first read data is 0xFF

	/*2.write eeprom*/
	EEPROM_Write(0x14000000, temp); //if reset the S32K144,the EEPROM_Read() will read the data had writed
								    //Proved that power loss but data is not lost.
	while(1)
	{
		/*send data*/
		UART_TransmitChar(GET_BIT_0_7(data));
		UART_TransmitChar(GET_BIT_8_15(data));
		UART_TransmitChar(GET_BIT_16_23(data));
		UART_TransmitChar(GET_BIT_24_31(data));
		DelayMs(500);
	}
}