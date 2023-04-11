/***************************************************************************//*!
*
* @file iap.c
*
* @author Wuhao
*
* @brief  Provide iap function
*
******************************************************************************/
#include "s32k144.h"
#include "devassert.h"
#include "S32K144_features.h"
#include "iap.h"
#include "flash.h"
#include "uart.h"
#include "clock.h"


uint32_t CanBuf[CAN_RECV_32BIT_LEN];//���ջ���,���USART_REC_LEN���ֽ�
uint32_t CanRevCount; //���ռ���.��4���ֽ�Ϊ��λ����.
IapFun   JumpToApp;  //����ָ��

/*****************************************************************************
*
* @brief    update app
*
* @param 	none
*
* @return   none
*
*******************************************************************************/
void IAP_UpdateApp()
{
	uint32_t OldCount = 0;
	uint32_t AppLenth = 0;

	while(1)
	{
		/*��������*/
		if(CanRevCount)
		{
			if(OldCount == CanRevCount)//�Ƿ����µ����ݱ�����
			{
				DelayMs(200); //�ӳٵȴ�,�ж��Ƿ��������.
				if(OldCount == CanRevCount)
				{
					AppLenth = CanRevCount*4; //32bit/8bit = 4,�ļ��������,�����ļ�size.
					OldCount = 0;
					CanRevCount = 0;
				}
				else
				{
					OldCount = CanRevCount; //���½������ݼ���
				}
			}
			else
			{
				OldCount = CanRevCount; //���½������ݼ���
			}
		}

		/*���ս���*/
		if(AppLenth > 0)
		{
#ifdef DE_BUG
			UART_TransmitChar(GET_BIT_0_7(AppLenth));//��ӡsize
			UART_TransmitChar(GET_BIT_8_15(AppLenth));
#endif
			IAP_WriteFLash(FLASH_APP_ADDR, (uint8_t *)CanBuf, AppLenth);//��appд�뵽flash��.
			UART_TransmitString("download!\n");
			IAP_JumpApp(FLASH_APP_ADDR);//��ת��app.
		}

	}

}

/*****************************************************************************
*
* @brief    program app.bin to flash
*
* @param 	FlashAddr : addrs to storage app.bin in flash
* 			AppBuf 	  : buffer temporarily storage app.bin in ram
* 			AppSize   : size of app.bin
*
* @return   none
*
*******************************************************************************/
void IAP_WriteFLash(uint32_t FlashSecAddr, uint8_t *AppBuf, uint32_t AppSize)
{
	uint32_t SecCount = 0 ;  //������
	uint32_t RestCount = 0;  //���һ���������ֽ���
	uint32_t TempCount = 0;  //��¼����ƫ��
	uint32_t SecNum = 0;     //������
	uint32_t TempFlashAddr;  //ÿ��flash��д���ַ,8�ֽڶ���
	uint32_t i = 0;

	TempFlashAddr = FlashSecAddr;

	/*������Ϊ��λд��,����ռ��������*/
	RestCount = AppSize % 4096;
	if(RestCount == 0)
	{
		SecCount = AppSize / 4096;
	}
	else
	{
		SecCount = AppSize / 4096 + 1;
	}

	/*���ζ�ÿ����������д��*/
    for(SecNum = 0; SecNum < SecCount; SecNum++)
    {
    	/*д��ǰ�ȶ��������в���*/
    	FLASH_EraseSector(TempFlashAddr + SecNum*4096);

    	/*ÿ8���ֽ�д��һ��flash*/
    	for(i = 0; i< 512; i++)
    	{
    		FLASH_ProgramPhrase(TempFlashAddr, &AppBuf[TempCount]);
    		TempFlashAddr += 8;  //ÿ�ε�ַ����8
    		TempCount += 8;
    		/*��app.binд�����,���˳���������ѭ��.*/
    		if(TempCount >= AppSize)
    		{
    		    break;
    		}

#ifdef DE_DUG  //debug
    		UART_TransmitChar((char)i);
#endif
    	}
#ifdef DE_DUG
    	UART_TransmitChar((char)SecNum); //����������
#endif
    }
}


/*****************************************************************************
*
* @brief    jump to app
*
* @param 	AppAddr : addrs to storage app.bin in flash
*
* @return   none
*
*******************************************************************************/

void IAP_JumpApp(uint32_t AppAddr)
{
	/*��ȡapp.bin��reset handle�ж�����.*/
	JumpToApp = (IapFun)(*(uint32_t *)(AppAddr + 4));/*ǿ��ת��Ϊ����ָ��.*/
	JumpToApp();  /*ͨ������ָ���ӷ��ʺ���,���к���reset_handle*/
}















