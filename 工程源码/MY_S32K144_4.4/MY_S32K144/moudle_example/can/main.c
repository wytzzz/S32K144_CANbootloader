#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "gpio.h"
#include "uart.h"
#include "ftm.h"
#include "can.h"

	int main(void)
	{
		uint8_t CanData[8] = {1,2,3,4,5,6,7,8};

		/*sys init*/
		WDOG_Disable();
		CLK_InitRunMode(); //run mode clock initial

		/*init led*/
		GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

		//init CAN
		CLK_Enable(PCC_PORTE_INDEX);  //port init
		PIN_Mux(PORTE, 4, PORT_MUX_ALT5);
		PIN_Mux(PORTE, 5, PORT_MUX_ALT5);
		CAN_Init(CAN0);

		//config MB1 as recieve data from ID 0x1ff ;
		CAN_RxFrameInit(CAN0, 1, 0x1ff);  //Rx


		CAN_TxFrameInfo_t info;
		info.DLC = 8;
		info.RTR = 0;
		info.ID = 0x2ff;
		info.data = CanData;

		while(1)
		{
			/*send data*/
			CAN_TxFrameInit(CAN0, 3, info);
			DelayMs(20);
		}
	}