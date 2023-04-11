#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"
#include "pit.h"


int main(void)
{
	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

	/*init led*/
	GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

	/*init pit*/
	/*note:use pit irq*/
	PIT_Init(0, 40000000);//1s

	while(1)
	{
		DelayMs(500);
	}
}