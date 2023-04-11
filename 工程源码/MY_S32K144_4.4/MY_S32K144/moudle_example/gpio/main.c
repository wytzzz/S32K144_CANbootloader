#include "S32K144.h"
#include "wdog.h"
#include "clock.h"
#include "nvic.h"
#include "gpio.h"

int main(void)
{
	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

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

	