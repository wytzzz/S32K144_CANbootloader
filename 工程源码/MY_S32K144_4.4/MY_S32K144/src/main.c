/*************************************************************
 V1.0 :修改串口,支持中断接收.
 V1.1 :支持app运行过程中,通过软件触发为update mode.
 V2.0 :将IAP下载接口从UART修改为CAN.

 *************************************************************/

#include "S32K144.h"
#include "gpio.h"
#include "clock.h"
#include "wdog.h"
#include "nvic.h"
#include "pit.h"
#include "ftm.h"
#include "adc.h"
#include "pdb.h"
#include "can.h"
#include "uart.h"
#include "flash.h"
#include "iap.h"


int main(void)
{
	uint8_t UpdateMode = 0;

	/*sys init*/
	WDOG_Disable();
	CLK_InitRunMode(); //run mode clock initial

	/*init led*/
	GPIO_Init(PTD, 0, OUT_PUT, 1); //blue

	/*init uart*/
	UART_Init();

	/*CAN init*/
    CLK_Enable(PCC_PORTE_INDEX);  //port init
	PIN_Mux(PORTE, 4, PORT_MUX_ALT5);
	PIN_Mux(PORTE, 5, PORT_MUX_ALT5);
	CAN_Init(CAN0);
	CAN_RxFrameInit(CAN0, 1, 0x1ff);//config MB1 as recieve data from ID 0x1ff ;

	/*eeprom init*/
	EEPROM_Init();

	/*read the UpdateFlag*/
	UpdateMode = (uint8_t)EEPROM_Read(UPDATA_FLAG_EEPROM_ADDR);

	/*update app*/
	if((UpdateMode == APP_UPDATE_MODE) || (UpdateMode == 0xFF)) //若为0xFF,则为首次写入,此时还没有下载任何app,进入update_mode
	{														    //若为0xab,则进入到update_mode
		EEPROM_Write(UPDATA_FLAG_EEPROM_ADDR, 0x00); //防止下次CPU重启进入到下载状态
		IAP_UpdateApp(); //更新程序
	}
	/*directive jump to app*/
	else
	{
#ifdef DE_BUG
		UART_TransmitString("jump!\n");
#endif
		IAP_JumpApp(FLASH_APP_ADDR);//跳转到app
	}

	IAP_UpdateApp(); //更新程序

	return 0;
}


