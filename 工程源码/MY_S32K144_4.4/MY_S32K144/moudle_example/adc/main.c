#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"
#include "uart.h"
#include "ftm.h"
#include "can.h"
#include "flash.h"
#include "adc.h"


 /*reference voltage*/
#define REF_VOLTAGE  5000  //5V

int main(void)
{
	uint16_t DigitValue = 0;
	uint16_t Volt = 0;

	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

	/*init led*/
	GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

	/*init uart*/
	UART_Init();

	/*init ADC*/
	ADC_Init(ADC0, ADC_12BIT, ADC_CLKDIV_2);

	while(1)
	{
		/*read convert result*/
		DigitValue = ADC_Converst(ADC0, 0); //channuel 0
		Volt = (DigitValue * REF_VOLTAGE) / 0x0fff; // 12bit
		if(Volt > 3000)
		{
			GPIO_SetData(PTD, 0, 0);
		}
		else
		{
			GPIO_SetData(PTD, 0, 1);
		}
		UART_TransmitChar(GET_BIT_0_7(Volt));
		UART_TransmitChar(GET_BIT_8_15(Volt));
	}
}