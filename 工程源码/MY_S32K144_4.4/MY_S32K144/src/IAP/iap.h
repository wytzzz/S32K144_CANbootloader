/***************************************************************************//*!
*
* @file iap.h
*
* @author Wuhao
*
* @brief  Provide iap function
*
******************************************************************************/

#ifndef __IAP_H__
#define __IAP_H__

/*update app flag*/
#define APP_UPDATE_MODE  0xab
/*定义缓存*/
#define  CAN_RECV_32BIT_LEN  5*1024  //4*5*1024 = 20k

/*16kb for bootloader : 0x00000000 - 0x00004000*/
#define FLASH_APP_ADDR 0x00004000

/*each 8 byte write to flash*/
#define FLASH_EACH_WRITE_SIZE 8

//定义一个函数类型的参数.
typedef  void (*IapFun)(void);

void IAP_UpdateApp();
void IAP_WriteFLash(uint32_t FlashSecAddr, uint8_t *AppBuf, uint32_t AppSize);
void IAP_JumpApp(uint32_t AppAddr);

#endif
