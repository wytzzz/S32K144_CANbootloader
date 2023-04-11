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


uint32_t CanBuf[CAN_RECV_32BIT_LEN];//接收缓冲,最大USART_REC_LEN个字节
uint32_t CanRevCount; //接收计数.以4个字节为单位增加.
IapFun   JumpToApp;  //函数指针

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
		/*接收数据*/
		if(CanRevCount)
		{
			if(OldCount == CanRevCount)//是否还有新的数据被接收
			{
				DelayMs(200); //延迟等待,判断是否结束传输.
				if(OldCount == CanRevCount)
				{
					AppLenth = CanRevCount*4; //32bit/8bit = 4,文件传输完成,保存文件size.
					OldCount = 0;
					CanRevCount = 0;
				}
				else
				{
					OldCount = CanRevCount; //更新接收数据计数
				}
			}
			else
			{
				OldCount = CanRevCount; //更新接收数据计数
			}
		}

		/*接收结束*/
		if(AppLenth > 0)
		{
#ifdef DE_BUG
			UART_TransmitChar(GET_BIT_0_7(AppLenth));//打印size
			UART_TransmitChar(GET_BIT_8_15(AppLenth));
#endif
			IAP_WriteFLash(FLASH_APP_ADDR, (uint8_t *)CanBuf, AppLenth);//将app写入到flash中.
			UART_TransmitString("download!\n");
			IAP_JumpApp(FLASH_APP_ADDR);//跳转到app.
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
	uint32_t SecCount = 0 ;  //扇区数
	uint32_t RestCount = 0;  //最后一个扇区的字节数
	uint32_t TempCount = 0;  //记录数据偏移
	uint32_t SecNum = 0;     //扇区号
	uint32_t TempFlashAddr;  //每次flash的写入地址,8字节对齐
	uint32_t i = 0;

	TempFlashAddr = FlashSecAddr;

	/*以扇区为单位写入,计算占有扇区数*/
	RestCount = AppSize % 4096;
	if(RestCount == 0)
	{
		SecCount = AppSize / 4096;
	}
	else
	{
		SecCount = AppSize / 4096 + 1;
	}

	/*依次对每个扇区进行写入*/
    for(SecNum = 0; SecNum < SecCount; SecNum++)
    {
    	/*写入前先对扇区进行擦除*/
    	FLASH_EraseSector(TempFlashAddr + SecNum*4096);

    	/*每8个字节写入一次flash*/
    	for(i = 0; i< 512; i++)
    	{
    		FLASH_ProgramPhrase(TempFlashAddr, &AppBuf[TempCount]);
    		TempFlashAddr += 8;  //每次地址增加8
    		TempCount += 8;
    		/*若app.bin写入完成,则退出本次扇区循环.*/
    		if(TempCount >= AppSize)
    		{
    		    break;
    		}

#ifdef DE_DUG  //debug
    		UART_TransmitChar((char)i);
#endif
    	}
#ifdef DE_DUG
    	UART_TransmitChar((char)SecNum); //发送扇区数
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
	/*获取app.bin的reset handle中断向量.*/
	JumpToApp = (IapFun)(*(uint32_t *)(AppAddr + 4));/*强制转化为函数指针.*/
	JumpToApp();  /*通过函数指针间接访问函数,运行函数reset_handle*/
}















