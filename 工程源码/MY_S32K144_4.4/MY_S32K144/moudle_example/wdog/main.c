#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"



int main(void)
{

	/*sys clk init*/
	CLK_InitRunMode(); //run mode clock initial

	/*init gpio*/

	GPIO_Init(PTD, 0, OUT_PUT, 1); //INIT,blue

	/*init wdog*/
	WODG_Init(12800);//time out : 0.1s

	while(1)
	{
		GPIO_SetData(PTD, 0, 0);
		DelayMs(10);
		GPIO_SetData(PTD, 0, 0);
		DelayMs(10);

#if 1  //feed dog
		WDOG_Feed();
#endif

	}
}