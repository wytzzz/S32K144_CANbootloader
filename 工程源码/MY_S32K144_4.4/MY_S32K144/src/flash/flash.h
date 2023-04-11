/*****************************************************************************
*
* @file flash.h
*
* @author Wuhao
*
* @brief  providing APIs for common operation of FLASH Module
*
******************************************************************************/

#ifndef __FLASH_H__
#define __FLASH_H__


/*set the section of function when link*/
#define CODE_RAM_SECTION __attribute__ ((section(".code_ram")))

/*update mode flag addr in eeprom*/
#define UPDATA_FLAG_EEPROM_ADDR  0x14000000


/*Flash hardware algorithm operation commands*/
#define FTFx_VERIFY_BLOCK             0x00U
#define FTFx_VERIFY_SECTION           0x01U
#define FTFx_PROGRAM_CHECK            0x02U
#define FTFx_READ_RESOURCE            0x03U
#define FTFx_PROGRAM_LONGWORD         0x06U
#define FTFx_PROGRAM_PHRASE           0x07U
#define FTFx_ERASE_BLOCK              0x08U
#define FTFx_ERASE_SECTOR             0x09U
#define FTFx_PROGRAM_SECTION          0x0BU
#define FTFx_VERIFY_ALL_BLOCK         0x40U
#define FTFx_READ_ONCE                0x41U
#define FTFx_PROGRAM_ONCE             0x43U
#define FTFx_ERASE_ALL_BLOCK          0x44U
#define FTFx_SECURITY_BY_PASS         0x45U
#define FTFx_PFLASH_SWAP              0x46U
#define FTFx_ERASE_ALL_BLOCK_UNSECURE 0x49U
#define FTFx_PROGRAM_PARTITION        0x80U
#define FTFx_SET_EERAM                0x81U

/*flash information*/
#define PFLASH_SECTOR_SIZE 	 	4096
#define PFLASH_PHASE_SIZE 		8
#define PFLASH_BLOCK_START  	0X00000000  //512KB
#define PFLASH_BLOCK_END  		0x00080000
#define	DFLASH_BLOCK_START		0x10000000  //64KB
#define	DFLASH_BLOCK_END		0x10010000
#define EEPROM_START			0X14000000  //4KB
#define EEPROM_END 				0X14000FFF

/*FlexNVM Partition code*/
typedef enum
{
	DFLASH_64KB_EEPROM_0KB  = 0b0000u,
	DFLASH_32KB_EEPROM_32KB = 0b0011u,
	DFLASH_16KB_EEPROM_48KB = 0b1010u,
	DFLASH_0KB_EEPROM_64KB  = 0b0100u
}FlexNVMPartCode_t;

/*EEPROM Size code*/
typedef enum
{
	EEPROM_0KB = 0xFu,
	EEPROM_4KB = 0X2U
}EEEPROMSizeCode_t;

/*FLASH*/
void CODE_RAM_SECTION FLASH_EraseSector(uint32_t addr);
void CODE_RAM_SECTION FLASH_EraseBlock(uint32_t addr);
void CODE_RAM_SECTION FLASH_ProgramPhrase(uint32_t addr, uint8_t const *pData);
void CODE_RAM_SECTION FLASH_DflashPartition(EEEPROMSizeCode_t SizeCode, FlexNVMPartCode_t PartCode);
/*EEPROM*/
void CODE_RAM_SECTION FlexRAM_SetToEEPROM(void);
void CODE_RAM_SECTION EEPROM_Init(void);
void CODE_RAM_SECTION EEPROM_Write(uint32_t addr, uint32_t data);
uint32_t CODE_RAM_SECTION EEPROM_Read(uint32_t addr);
#endif
