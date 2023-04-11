/****************************************************************************
*
* @file gpio.c
*
* @author Wuhao
*
* @brief providing APIs for configuring PROT and GPIO
*
*******************************************************************************/


#include <stddef.h>
#include <stdint.h>
#include "devassert.h"
#include "S32K144.h"
#include "gpio.h"
#include "nvic.h"
#include "clock.h"



/*****************************************************************************//*!
   *
   * @brief initialize GPIO as per params.
   *
   * @param[in] base: PTA, PTB, PTC, PTD, PTE
   * @param[in]  pin : 0-31
   * @param[in]  direction : INT_PUT, OUT_PUT
   * @param[in]	 data : 0, 1
   * @return none
   *
   *****************************************************************************/
void GPIO_Init( GPIO_Type *const base,
				uint32_t pin,
				GPIO_Drection_t direction,
				uint32_t data)
{
	PORT_Type *port = NULL;
	uint8_t  PccIndex = 0;

	if(base == PTA)
	{
		PccIndex = PCC_PORTA_INDEX;
		port = PORTA;
	}
	else if(base == PTB)
	{
		PccIndex = PCC_PORTB_INDEX;
		port = PORTB;
	}
	else if(base == PTC)
	{
		PccIndex = PCC_PORTC_INDEX;
		port = PORTC;
	}
	else if(base == PTD)
	{
		PccIndex = PCC_PORTD_INDEX;
		port = PORTD;
	}
	else if(base == PTE)
	{
		PccIndex = PCC_PORTE_INDEX;
		port = PORTE;
	}

	/*enable gpio moudle clk*/
	CLK_Enable(PccIndex);

	/*pin multiplex to gpio*/
	PIN_Mux(port, pin, PORT_MUX_GPIO);
	PIN_Mux(port, pin, PORT_MUX_GPIO);

	/*set the gpio directoin and data*/
	GPIO_SetDirection(base, pin, direction);
	GPIO_SetData(base, pin, data);
}



/*****************************************************************************//*!
   *
   * @brief set the gpio direction as per params
   *
   * @param[in] base: PTA, PTB, PTC, PTD, PTE
   * @param[in]  pin : 0-31
   * @param[in]  direction : INT_PUT, OUT_PUT
   *
   * @return none
   *
   *****************************************************************************/

void GPIO_SetDirection(GPIO_Type *const base,
						uint32_t pin,
						GPIO_Drection_t direction)
{
	/*check th input*/
	DEV_ASSERT(base != NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*set the direction*/
	base->PDDR = (base->PDDR & ~(1u << pin)) | (direction << pin);
}


/*****************************************************************************//*!
   *
   * @brief get the gpio direction
   *
   * @param[in] base: PTA, PTB, PTC, PTD, PTE
   * @param[in]  pin : 0-31
   *
   * @return 0: INT_PUT
   * 		 1:	OUT_PUT
   *
   *****************************************************************************/
uint32_t GPIO_GetDirection(GPIO_Type *const base, uint32_t pin)
{

	/*check th input*/
	DEV_ASSERT(base != NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*get the direction*/
	if(base->PDDR & (uint32_t)(1u << pin))
		return 1;
	else
		return 0;
}


/*****************************************************************************//*!
   *
   * @brief set the gpio output data
   *
   * @param[in] base: PTA, PTB, PTC, PTD, PTE
   * @param[in]  pin : 0-31
   * @param data: 0, 1
   *
   * @return none
   *
   *****************************************************************************/
void GPIO_SetData(GPIO_Type *const base, uint32_t pin,  uint32_t data)
{
	/*check th input*/
	DEV_ASSERT(base != NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*set the data*/
	base->PDOR = (base->PDOR & ~(1u << pin)) | (data << pin);
}


/*****************************************************************************//*!
   *
   * @brief get the gpio output data
   *
   * @param[in] base: PTA, PTB, PTC, PTD, PTE
   * @param[in]  pin : 0-31
   *
   * @return 0
   * 		 1
   *
   *****************************************************************************/
uint32_t GPIO_GetData(GPIO_Type *const base, uint32_t pin)
{

	/*check th input*/
	DEV_ASSERT(base != NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*get the data*/
	if(base->PDIR & (1u << pin))
			return 1;
	else
			return 0;
}



/*****************************************************************************//*!
   *
   * @brief config the PORT
   *
   * @param  base : PORTA, PORTB, PORTC, PORTD, PORTE
   * @param	 pin   : 0-31
   * @param  PortCfg : pin config structure
   *
   * @return none.
   *
   *****************************************************************************/
void PIN_Config(PORT_Type *const base, uint32_t pin, PORT_FuncCfg_t *PortCfg)
{
	/*check the input */
	DEV_ASSERT(base!= NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*passive filter*/
	if(PortCfg->FilterEnable)
		base->PCR[pin] |= PORT_PCR_PFE(1);

	/*drive strenth*/
	if(PortCfg->DriveSelect)
		base->PCR[pin] |= PORT_PCR_DSE(1);

	/*pin lock*/
	if(PortCfg->LockEnable)
		base->PCR[pin] |= PORT_PCR_LK(1);
}


/*****************************************************************************//*!
   *
   * @brief config EXIT IRQ mode
   *
   * @param[in]  base: PORTA, PORTB, PORTC, PORTD, PORTE
   * @param[in]  pin : 0-31
   * @param[in]  mode: irq mode
   *
   * @return none.
   *
   *****************************************************************************/
void PIN_IrqModeSet(PORT_Type *const base, uint32_t pin, PORT_IrqMode_t mode)
{
		/*check the input */
		DEV_ASSERT(base!= NULL);
		DEV_ASSERT(pin < PORT_PCR_COUNT);

		/*config external irq mode*/
		base->PCR[pin] &= ~PORT_PCR_IRQC_MASK;
		base->PCR[pin] |= PORT_PCR_IRQC(mode);
}


/*****************************************************************************//*!
   *
   * @brief enable and config the pin pull
   *
   * @param[in]  base: PORTA, PORTB, PORTC, PORTD, PORTE
   * @param[in]  pin : 0-31
   * @param[in]  PullSelect: PULL_DOWN,
   *				         PULL_UP
   * @return none.
   *
   *****************************************************************************/
void PIN_PullSet(PORT_Type *const base, uint32_t pin, PORT_PullSelect_t PullSelect)
{
	/*check the input*/
	DEV_ASSERT(base != NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*pin pull enable*/
	base->PCR[pin] |= PORT_PCR_PE(1);
	base->PCR[pin] |= PORT_PCR_PS((uint32_t)PullSelect);
}


/*****************************************************************************//*!
   *
   * @brief set the pin mux
   *
   * @param[in]  base: PORTA, PORTB, PORTC, PORTD, PORTE
   * @param[in]  pin : 0-31
   * @param[in]  muxconfig:
   * 				PORT_PIN_DISABLED = 0u,
					PORT_MUX_AS_GPIO = 1u,
					PORT_MUX_ALT2 = 2u,
					PORT_MUX_ALT3 = 3u,
					PORT_MUX_ALT4 = 4u,
					PORT_MUX_ALT5 = 5u,
					PORT_MUX_ALT6 = 6u,
					PORT_MUX_ALT7 = 7u
   *
   * @return none.
   *
   *****************************************************************************/

void PIN_Mux(PORT_Type *const base, uint32_t pin, PORT_MuxCfg_t MuxCfg)
{
	/*check the input*/
	DEV_ASSERT(base != NULL);
	DEV_ASSERT(pin < PORT_PCR_COUNT);

	/*pin mux*/
	base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_MUX_MASK)
					  | PORT_PCR_MUX(MuxCfg);

}


/*****************************************************************************//*!
   *
   * @brief clear the pin interrupt flag
   *
   * @param[in]  base: PORTA, PORTB, PORTC, PORTD, PORTE
   * @param[in]  pin : 0-31
   *
   * @return none
   *
   *****************************************************************************/
void PIN_IrqClear(PORT_Type *const base, uint32_t pin)
{
	/*check the input*/
	DEV_ASSERT(base != NULL);

	/*write 1 to clear the flag*/
	if(base->PCR[pin] & PORT_PCR_ISF_MASK)
	{
		base->PCR[pin]  |= PORT_PCR_ISF(1);
	}
}
































