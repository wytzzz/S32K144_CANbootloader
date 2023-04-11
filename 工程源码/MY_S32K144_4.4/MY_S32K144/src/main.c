/*************************************************************
 V1.0 :�޸Ĵ���,֧���жϽ���.
 V1.1 :֧��app���й�����,ͨ���������Ϊupdate mode.
 V2.0 :��IAP���ؽӿڴ�UART�޸�ΪCAN.

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
	if((UpdateMode == APP_UPDATE_MODE) || (UpdateMode == 0xFF)) //��Ϊ0xFF,��Ϊ�״�д��,��ʱ��û�������κ�app,����update_mode
	{														    //��Ϊ0xab,����뵽update_mode
		EEPROM_Write(UPDATA_FLAG_EEPROM_ADDR, 0x00); //��ֹ�´�CPU�������뵽����״̬
		IAP_UpdateApp(); //���³���
	}
	/*directive jump to app*/
	else
	{
#ifdef DE_BUG
		UART_TransmitString("jump!\n");
#endif
		IAP_JumpApp(FLASH_APP_ADDR);//��ת��app
	}

	IAP_UpdateApp(); //���³���

	return 0;
}


