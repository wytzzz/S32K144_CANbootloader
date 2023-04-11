#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"
#include "uart.h"
#include "ftm.h"

	int main(void)
	{
		/*sys init*/
		WDOG_Disable();
		CLK_InitRunMode(); //run mode clock initial

		/*init led*/
		GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

		/*init FTM*/
		/*1.PIN max,the ftm has too many channels, so need user configure the pin mux*/
		CLK_Enable(PCC_PORTB_INDEX);
		PIN_Mux(PORTB, 12, PORT_MUX_ALT2);//PIN mux

		/*2. init FTM module*/
		FTM_Init(FTM0, 1, 60000);  //period : 6ms
		FTM_ChnInit(FTM0, 0, 1);

		while(1)
		{
		   FTM_SetPwmRatio(FTM0, 0, 20000);
		}
	}