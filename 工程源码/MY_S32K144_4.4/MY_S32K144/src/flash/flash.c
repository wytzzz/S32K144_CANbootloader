/*****************************************************************************
*
* @file flash.c
*
* @author Wuhao
*
* @brief  providing APIs for common operation of FLASH Module
*
******************************************************************************/

#include "s32k144.h"
#include "devassert.h"
#include "nvic.h"
#include "uart.h"
#include "clock.h"
#include "can.h"
#include "gpio.h"
#include "flash.h"
#include "stdlib.h"



/***********************************************************************
*
* @brief program data in spcific PFLASH address
*
* @note : 1.addr need 8 byte aligned
* 		  2.addr just 24 bit
* 		  2.once phrase program cmd must program 8 byte.
*
*
* @param[in]  addr
* 			  pData
*
* @return none.
*
*************************************************************************/
void CODE_RAM_SECTION FLASH_ProgramPhrase(uint32_t addr, uint8_t const *pData)
{
	uint32_t i = 0;
	uint32_t address = addr;

	/*1.Must be 64-bit(8byte) aligned (Flash address [2:0] = 000)*/
	if((address & 0b111) != 0)
		address &= (uint32_t)~0b111;

	/*2.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);

	/*3.clear error falg before lauch the cmd*/
	FTFC->FSTAT = FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK;

	/*4.fill the FCCOB*/
	/*4.1 fill cmd num to FCCOB*/
	FTFC->FCCOB[3] = FTFx_PROGRAM_PHRASE;  //Program Phrase command (0x07)

	/*4.2 fill address to FCCOB*/
	FTFC->FCCOB[2] = GET_BIT_16_23(address);  //Flash address [23:16]
	FTFC->FCCOB[1] = GET_BIT_8_15(address);  //Flash address [15:08]
	FTFC->FCCOB[0] = GET_BIT_0_7(address);  //Flash address [7:0]

	/*4.2 fill data to FCCOB*/
	for(i = 0; i < PFLASH_PHASE_SIZE; i++)
	{
		FTFC->FCCOB[i+4] = pData[i];
	}

	/*5.launch command*/
	FTFC->FSTAT = FTFC_FSTAT_CCIF_MASK;

	/*5.2 wait cmd finish*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);
}



/***********************************************************************
*
* @brief The Erase Flash Block operation erases all addresses
* 		  in a single program flash or data flash block
*
* @note	1.addr need 128(PFLASH)/64(DFLASH) bit aligned
* 		2.block size is 512(PFLASH)/64(DFLASH) kb.
*
* @param[in] addr
*
* @return none.
*
*************************************************************************/
void CODE_RAM_SECTION FLASH_EraseBlock(uint32_t addr)
{

	uint32_t address = addr;

	/*1.address aligned   PFLASH: 128¡¡bit aligned /  DFLASH: 64 bit aligned*/
	if(address < PFLASH_BLOCK_END)
	{
		/*Must be 128-bit(16byte) aligned PFLASH(Flash address [3:0] = 0000)*/
		if((address & 0b1111) != 0)
		{
			address &= (uint32_t)~0b1111;
		}
	}
	else
	{
		/*Must be 64-bit(8byte) aligned DFLASH(Flash address [2:0] = 000)*/
		if((address & 0b111) != 0)
		{
			address &= (uint32_t)~0b111;
		}
	}

	/*2.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);

	/*3.clear error falg before lauch the cmd*/
	FTFC->FSTAT = FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK;

	/*4.fill the FCCOB*/
	/*4.1 fill cmd num to FCCOB*/
	FTFC->FCCOB[3] = FTFx_ERASE_BLOCK;  //Program Phrase command
	/*4.2 fill address to FCCOB*/
		FTFC->FCCOB[2] = GET_BIT_16_23(address);  //Flash address [23:16]
		FTFC->FCCOB[1] = GET_BIT_8_15(address);  //Flash address [15:08]
		FTFC->FCCOB[0] = GET_BIT_0_7(address);  //Flash address [7:0]

	/*5.launch command*/
	FTFC->FSTAT |= FTFC_FSTAT_CCIF_MASK;

	/*5.2 wait cmd finish*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);
}


/***********************************************************************
*
* @brief Erase the spcific FLASH sector.
*
* @note	1.addr need 128(PFLASH)/64(DFLASH) bit aligned
* 		2.sector size is 4(PFLASH)/2(DFLASH) kb.
*
* @param[in] addr
*
* @return none.
*
*************************************************************************/
void CODE_RAM_SECTION FLASH_EraseSector(uint32_t addr)
{

	uint32_t address = addr;

	/*1.address aligned   PFLASH: 128¡¡bit aligned /  DFLASH: 64 bit aligned*/
	if(address < PFLASH_BLOCK_END)
	{
		/*Must be 128-bit(16byte) aligned PFLASH(Flash address [3:0] = 0000)*/
		if((address & 0b1111) != 0)
		{
			address &= (uint32_t)~0b1111;
		}
	}
	else
	{
		/*Must be 64-bit(8byte) aligned DFLASH(Flash address [2:0] = 000)*/
		if((address & 0b111) != 0)
		{
			address &= (uint32_t)~0b111;
		}
	}

	/*2.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);   //wait if operation in progress

	/*3.clear error falg before lauch the cmd*/
	FTFC->FSTAT = (uint8_t)(FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK | FTFC_FSTAT_RDCOLERR_MASK);

	/*4.fill the FCCOB*/
	/*4.1 fill cmd num to FCCOB*/
	FTFC->FCCOB[3] = FTFx_ERASE_SECTOR;  //Erase Flash Sector command (0x09)

	/*4.2 fill address to FCCOB*/
	FTFC->FCCOB[2] = GET_BIT_16_23(address);  //Flash address [23:16]
	FTFC->FCCOB[1] = GET_BIT_8_15(address);  //Flash address [15:08]
	FTFC->FCCOB[0] = GET_BIT_0_7(address);  //Flash address [7:0]

	/*5.launch command*/
	FTFC->FSTAT |= FTFC_FSTAT_CCIF_MASK;

	/*5.2 wait cmd finish*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);
}



/*******************************************************************************
*
* @brief configure the FlexNVM block for use as data flash,emulated EEPROM backup
*	     or a combination of both and initializes the FlexRAM
*
* @param[in] SizeCode : EEPROM Size code
*			 PartCode : FlexNVM Partition code
*
* @return none.
*
********************************************************************************/
void CODE_RAM_SECTION FLASH_DflashPartition(EEEPROMSizeCode_t SizeCode, FlexNVMPartCode_t PartCode)
{
	/*1.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);

	/*2.clear error falg before lauch the cmd*/
	FTFC->FSTAT = FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK;

	/*3.fill the FCCOB*/
	FTFC->FCCOB[3] = FTFx_PROGRAM_PARTITION;
	FTFC->FCCOB[2] = 0x00;  //CSEc/SHE key size = 0
	FTFC->FCCOB[1] = 0x00;  //Flash Key 'Verify Only' attribute not enabled
	FTFC->FCCOB[0] = 0x00;  //FlexRAM  loaded EEPROM backup data  during reset sequence
	FTFC->FCCOB[7] = (uint8_t)SizeCode;  //EEPROM Data Set Size 4KB of FlexRAM
	FTFC->FCCOB[6] = (uint8_t)PartCode;  //Data flash Size 0KB, EEPROM-backup Size 64KB

	/*4.launch command*/
	FTFC->FSTAT = FTFC_FSTAT_CCIF_MASK;

	/*5.wait cmd finish*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);
}

/*******************************************************************************
*
* @brief Set FlexRAM to EEPROM(4kb)
*
* @param[in]
*
* @return none.
*
********************************************************************************/
void CODE_RAM_SECTION FlexRAM_SetToEEPROM(void)
{
	/*1.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);

	/*2.clear error falg before lauch the cmd*/
	FTFC->FSTAT = FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK;

	/*3.fill the FCCOB*/
	FTFC->FCCOB[3] = FTFx_SET_EERAM;
	FTFC->FCCOB[2] = 0x00; /*Make FlexRAM available for emulated EEPROM */

	/*4.launch command*/
	FTFC->FSTAT = FTFC_FSTAT_CCIF_MASK;

	/*5.wait cmd finish*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);
}


/*******************************************************************************
*
* @brief Init the EEPROM module
*
* @note 1.EEPROM in S32K144 is simulation
* 		2.enable chip EEPROM need configure the FlexARM to simulated EEPROM,
* 		  and FlexNVM need to patition space for EEPROM data backup.
* 		3.so put flash and eeprom together.
*
* @param[in]
*
* @return none.
*
********************************************************************************/
void CODE_RAM_SECTION EEPROM_Init(void)
{
	/*1.check whether flexRAM configure to eeprom*/
	if((SIM->FCFG1 & SIM_FCFG1_EEERAMSIZE_MASK) != 0x02u)
	{
		if((SIM->FCFG1 & SIM_FCFG1_DEPART_MASK) != 0x00u)
		{
			/*partition flexnvm  to eeprom backup(64KB)*/
			FLASH_DflashPartition(EEPROM_4KB, DFLASH_0KB_EEPROM_64KB);

			/*configure the flexram to eeprom(4KB)*/
			FlexRAM_SetToEEPROM();
		}
	}

	/*2.wait EEEPROM ready flag*/
	while((FTFC->FCNFG & FTFC_FCNFG_EEERDY_MASK) != 1);
}



/*******************************************************************************
*
* @brief EEPROM write
*
* @param[in]  addr : 0x14000000 - 0x14000fff (4kb)
* 			  data : write data
*
* @return none.
*
********************************************************************************/
void CODE_RAM_SECTION EEPROM_Write(uint32_t addr, uint32_t data)
{

	/*1.check input address whether in EEPROM space*/
	if(addr < EEPROM_START || addr > EEPROM_END)
	{
		UART_TransmitString("EEPROM write address error!\n");
		exit(1);
	}
	uint32_t *address = (uint32_t *)addr;

	/*2.check EEPROM ready flag*/
	while((FTFC->FCNFG & FTFC_FCNFG_EEERDY_MASK) != 1);

	/*3.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);

	/*4.write data*/
	*address = data;
}

/*******************************************************************************
*
* @brief EEPROM read
*
* @param[in]  addr : 0x140000000 - 0x14000fff (4kb)
*
* @return  data read from EEPROM
*
********************************************************************************/
uint32_t CODE_RAM_SECTION EEPROM_Read(uint32_t addr)
{
	/*1.check input address whether in EEPROM space*/
	if(addr < EEPROM_START || addr > EEPROM_END)
	{
		UART_TransmitString("EEPROM read address error!\n");
		exit(0);
	}
	uint32_t *address = (uint32_t *)addr;

	/*2.check EEPROM ready flag*/
	while((FTFC->FCNFG & FTFC_FCNFG_EEERDY_MASK) != 1);

	/*3.Whether there is an operation being performed*/
	while((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0);

	/*4.return data*/
	return *address;
}






