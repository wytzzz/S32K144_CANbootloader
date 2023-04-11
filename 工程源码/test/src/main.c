/****************************************************************
 * V1.0 :1.添加串口,支持触发update mode.
 *
 ****************************************************************/

#include "S32K144.h"
#include "wdog.h"
#include "clock.h"
#include "nvic.h"
#include "gpio.h"
#include "flash.h"
#include "uart.h"


int main(void)
{
	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

	/*uart init*/
	UART_Init();

	/*can init*/
	 CLK_Enable(PCC_PORTE_INDEX);  //port init
     PIN_Mux(PORTE, 4, PORT_MUX_ALT5);
	 PIN_Mux(PORTE, 5, PORT_MUX_ALT5);
	 CAN_Init(CAN0);
	 CAN_RxFrameInit(CAN0, 1, 0x1ff);//config MB1 as recieve data from ID 0x1ff ;

	/*init eeprom*/
	EEPROM_Init();

	/*init led*/
	GPIO_Init(PTD, 0, OUT_PUT, 1); //blue
	GPIO_Init(PTD, 15, OUT_PUT, 1); //red
	GPIO_Init(PTD, 16, OUT_PUT, 1); //green

	while(1)
	{
		GPIO_SetData(PTD, 15, 1);
		GPIO_SetData(PTD, 0,  0); //blue
		DelayMs(1000);
		GPIO_SetData(PTD, 0,  1);
		GPIO_SetData(PTD, 16, 0);//green
		DelayMs(1000);
		GPIO_SetData(PTD, 16, 1);
		GPIO_SetData(PTD, 15, 0);//red
		DelayMs(1000);
	}
}

	
