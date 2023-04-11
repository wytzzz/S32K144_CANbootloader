/****************************************************************************
* @file gpio.h
*
* @author Wuhao

* @brief provide APIs for accessing GPIO and PORT
*
*******************************************************************************/

#ifndef __GPIO_H__
#define __GPIO_H__

#include "S32K144.h"

/* port pull_enable */
typedef enum
{
	PORT_PULL_DISABLE = 0u,
	PORT_PULL_ENABLE =1u
}PORT_PullEnable_t;

/* port pull_select */
typedef enum
{
	PORT_PULL_DOWN = 0u,
	PORT_PULL_UP = 1u
}PORT_PullSelect_t;

/* passivefilter_config */
typedef enum
{
	PORT_PAFILTER_DISABLE = 0u,
	PORT_PAFILTER_ENABLE = 1u
}PORT_FilterEnable_t;

/* Drive Strength Enable */
typedef enum
{
	PORT_LOW_DRV = 0u,
	PORT_HIGH_DRV = 1u
}PORT_DrvSelect_t;

/* Pin Mux Control */
typedef enum
{
	PORT_PIN_DISABLED = 0u,
	PORT_MUX_GPIO = 1u,
	PORT_MUX_ALT2 = 2u,
	PORT_MUX_ALT3 = 3u,
	PORT_MUX_ALT4 = 4u,
	PORT_MUX_ALT5 = 5u,
	PORT_MUX_ALT6 = 6u,
	PORT_MUX_ALT7 = 7u
}PORT_MuxCfg_t;

typedef enum
{
	PORT_LOCK_DISABLE = 0,
	PORT_LOCK_ENABLE  = 1u
}PORT_LockEnable_t;


typedef enum
{
	 PORT_DMA_INT_DISABLED = 0x0u,
	 PORT_DMA_RISING_EDGE  = 0x1u,
	 PORT_DMA_FALLING_EDGE = 0x2u,
	 PORT_DMA_EITHER_EDGE  = 0x3u,
	 PORT_INT_LOGIC_ZERO   = 0x8u,
	 PORT_INT_RISING_EDGE  = 0x9u,
	 PORT_INT_FALLING_EDGE = 0xAu,
	 PORT_INT_EITHER_EDGE  = 0xBu,
	 PORT_INT_LOGIC_ONE    = 0xCu
}PORT_IrqMode_t;

/* GPIO_Drection */
typedef enum
{
	INT_PUT = 0u,
	OUT_PUT = 1u
}GPIO_Drection_t;


/*portConfig struct*/
typedef struct
{
	PORT_FilterEnable_t			FilterEnable;  //passice fileter
	PORT_DrvSelect_t			DriveSelect;   //drive strength
	PORT_LockEnable_t			LockEnable; 	//pin lock control
}PORT_FuncCfg_t;


void GPIO_Init( GPIO_Type *const base,uint32_t pin,GPIO_Drection_t direction,uint32_t data);
void GPIO_SetDirection(GPIO_Type *const base,uint32_t pin,GPIO_Drection_t direction);
uint32_t GPIO_GetDirection(GPIO_Type *const base, uint32_t pin);
void GPIO_SetData(GPIO_Type *const base, uint32_t pin,  uint32_t data);
uint32_t GPIO_GetData(GPIO_Type *const base, uint32_t pin);
void PIN_Config(PORT_Type *const base, uint32_t pin, PORT_FuncCfg_t *PortCfg);
void PIN_IrqModeSet(PORT_Type *const base, uint32_t pin, PORT_IrqMode_t mode);
void PIN_PullSet(PORT_Type *const base, uint32_t pin, PORT_PullSelect_t PullSelect);
void PIN_PullClose(PORT_Type *const base, uint32_t pin);
void PIN_Mux(PORT_Type *const base, uint32_t pin, PORT_MuxCfg_t MuxCfg);
void PIN_IrqClear(PORT_Type  *const base, uint32_t pin);



#endif








