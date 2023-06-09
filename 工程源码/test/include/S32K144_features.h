/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file S32K144_features.h
 * @brief Chip specific module features
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.3, Global typedef not referenced.
 * Type used only in some modules of the SDK.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The macros defined are used to define features for each driver, so this might be reported
 * when the analysis is made only on one driver.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
 * These are very simple macros used for abstracting hw implementation.
 * They help make the code easy to understand.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.1, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.2, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.4, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 5.5, identifier clash
 * The supported compilers use more than 31 significant characters for identifiers.
 *
 */

#if !defined(S32K144_FEATURES_H)
#define S32K144_FEATURES_H

/* ERRATA sections*/

/* @brief ARM Errata 838869: Store immediate overlapping exception return operation might vector to
 * incorrect interrupt. */
#define ERRATA_E9005

/* @brief ARM Errata 709718: VDIV or VSQRT instructions might not complete correctly when very
 * short ISRs are used. */
#define ERRATA_E6940

/* @brief E10655: When using LPSPI in master mode and the SR[MBF] bit is read as a one, then, the
 * flag is set. If it is read as a zero, it must be read second time and this second read will be
 * the correct state of the bit.�? */
#define ERRATA_E10655

/* @brief E10792: LPI2C: Slave Transmit Data Flag may incorrectly read as one when TXCFG is zero.
 * Interrupts for transfer data should be enabled after the address valid event is detected and
 * disabled at the end of the transfer. */
#define ERRATA_E10792

/* @brief Errata workaround: System clock status register may be a erroneous status during the system clock switch.
 * Read system clock source twice. */
#define ERRATA_E10777

/* @brief E10856: FTM: Safe state is not removed from channel outputs after fault condition
 * ends if SWOCTRL is being used to control the pin */
#define ERRATA_E10856

/* PCC module features */

/* @brief Has InUse feature (register bit PCC[INUSE]). */
#define FEATURE_PCC_HAS_IN_USE_FEATURE (0)

/* PORT module features */
/*! @brief PORT Used for setting Pins */
#define FEATURE_PINS_DRIVER_USING_PORT (1)
/* @brief Has control lock (register bit PCR[LK]). */
#define FEATURE_PORT_HAS_PIN_CONTROL_LOCK (1)
/* @brief Has open drain control (register bit PCR[ODE]). */
#define FEATURE_PINS_HAS_OPEN_DRAIN (0)
/* @brief Has digital filter (registers DFER, DFCR and DFWR). */
#define FEATURE_PORT_HAS_DIGITAL_FILTER (1)
/* @brief Has DMA request (register bit field PCR[IRQC] values). */
#define FEATURE_PORT_HAS_DMA_REQUEST (1)
/* @brief Has pull resistor selection available. */
#define FEATURE_PINS_HAS_PULL_SELECTION (1)
/* @brief Has slew rate control (register bit PCR[SRE]). */
#define FEATURE_PINS_HAS_SLEW_RATE (0)
/* @brief Has passive filter (register bit field PCR[PFE]). */
#define FEATURE_PORT_HAS_PASSIVE_FILTER (1)
/* @brief Has drive strength (register bit PCR[DSE]). */
#define FEATURE_PINS_HAS_DRIVE_STRENGTH (1)
/* @brief Has drive strength control bits*/
#define FEATURE_PINS_HAS_DRIVE_STRENGTH_CONTROL (0)

/* SOC module features */

/* @brief PORT availability on the SoC. */
#define FEATURE_SOC_PORT_COUNT (5)

#define FEATURE_SOC_SCG_COUNT (1)
/* @brief Slow IRC low range clock frequency. */
#define FEATURE_SCG_SIRC_LOW_RANGE_FREQ  (2000000U)
/* @brief Slow IRC high range clock frequency. */
#define FEATURE_SCG_SIRC_HIGH_RANGE_FREQ (8000000U)

/* @brief Fast IRC trimmed clock frequency(48MHz). */
#define FEATURE_SCG_FIRC_FREQ0  (48000000U)
/* @brief Fast IRC trimmed clock frequency(52MHz). */
#define FEATURE_SCG_FIRC_FREQ1  (52000000U)
/* @brief Fast IRC trimmed clock frequency(56MHz). */
#define FEATURE_SCG_FIRC_FREQ2  (56000000U)
/* @brief Fast IRC trimmed clock frequency(60MHz). */
#define FEATURE_SCG_FIRC_FREQ3  (60000000U)

/* FLASH module features */

/* @brief Is of type FTFA. */
#define FEATURE_FLS_IS_FTFA (0u)
/* @brief Is of type FTFC. */
#define FEATURE_FLS_IS_FTFC (1u)
/* @brief Is of type FTFE. */
#define FEATURE_FLS_IS_FTFE (0u)
/* @brief Is of type FTFL. */
#define FEATURE_FLS_IS_FTFL (0u)
/* @brief Has flags indicating the status of the FlexRAM (register bits FCNFG[EEERDY], FCNFG[RAMRDY] and FCNFG[PFLSH]). */
#define FEATURE_FLS_HAS_FLEX_RAM_FLAGS (1u)
/* @brief Has program flash swapping status flag (register bit FCNFG[SWAP]). */
#define FEATURE_FLS_HAS_PF_SWAPPING_STATUS_FLAG (0u)
/* @brief Has EEPROM region protection (register FEPROT). */
#define FEATURE_FLS_HAS_EEROM_REGION_PROTECTION (1u)
/* @brief Has data flash region protection (register FDPROT). */
#define FEATURE_FLS_HAS_DATA_FLS_REGION_PROTECTION (1u)
/* @brief P-Flash block count. */
#define FEATURE_FLS_PF_BLOCK_COUNT (1u)
/* @brief P-Flash block size. */
#define FEATURE_FLS_PF_BLOCK_SIZE (524288u)
/* @brief P-Flash sector size. */
#define FEATURE_FLS_PF_BLOCK_SECTOR_SIZE (4096u)
/* @brief P-Flash write unit size. */
#define FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE (8u)
/* @brief P-Flash block swap feature. */
#define FEATURE_FLS_HAS_PF_BLOCK_SWAP (0u)
/* @brief Has FlexNVM memory. */
#define FEATURE_FLS_HAS_FLEX_NVM (1u)
/* @brief FlexNVM block count. */
#define FEATURE_FLS_DF_BLOCK_COUNT (1u)
/* @brief FlexNVM block size. */
#define FEATURE_FLS_DF_BLOCK_SIZE (65536u)
/* @brief FlexNVM sector size. */
#define FEATURE_FLS_DF_BLOCK_SECTOR_SIZE (2048u)
/* @brief FlexNVM write unit size. */
#define FEATURE_FLS_DF_BLOCK_WRITE_UNIT_SIZE (8u)
/* @brief FlexNVM start address. (Valid only if FlexNVM is available.) */
#define FEATURE_FLS_DF_START_ADDRESS (0x10000000u)
/* @brief Has FlexRAM memory. */
#define FEATURE_FLS_HAS_FLEX_RAM (1u)
/* @brief FlexRAM size. */
#define FEATURE_FLS_FLEX_RAM_SIZE (4096u)
/* @brief FlexRAM start address. (Valid only if FlexRAM is available.) */
#define FEATURE_FLS_FLEX_RAM_START_ADDRESS (0x14000000u)
/* @brief Has 0x00 Read 1s Block command. */
#define FEATURE_FLS_HAS_READ_1S_BLOCK_CMD (1u)
/* @brief Has 0x01 Read 1s Section command. */
#define FEATURE_FLS_HAS_READ_1S_SECTION_CMD (1u)
/* @brief Has 0x02 Program Check command. */
#define FEATURE_FLS_HAS_PROGRAM_CHECK_CMD (1u)
/* @brief Has 0x03 Read Resource command. */
#define FEATURE_FLS_HAS_READ_RESOURCE_CMD (0u)
/* @brief Has 0x06 Program Longword command. */
#define FEATURE_FLS_HAS_PROGRAM_LONGWORD_CMD (0u)
/* @brief Has 0x07 Program Phrase command. */
#define FEATURE_FLS_HAS_PROGRAM_PHRASE_CMD (1u)
/* @brief Has 0x08 Erase Flash Block command. */
#define FEATURE_FLS_HAS_ERASE_BLOCK_CMD (1u)
/* @brief Has 0x09 Erase Flash Sector command. */
#define FEATURE_FLS_HAS_ERASE_SECTOR_CMD (1u)
/* @brief Has 0x0B Program Section command. */
#define FEATURE_FLS_HAS_PROGRAM_SECTION_CMD (1u)
/* @brief Has 0x40 Read 1s All Blocks command. */
#define FEATURE_FLS_HAS_READ_1S_ALL_BLOCKS_CMD (1u)
/* @brief Has 0x41 Read Once command. */
#define FEATURE_FLS_HAS_READ_ONCE_CMD (1u)
/* @brief Has 0x43 Program Once command. */
#define FEATURE_FLS_HAS_PROGRAM_ONCE_CMD (1u)
/* @brief Has 0x44 Erase All Blocks command. */
#define FEATURE_FLS_HAS_ERASE_ALL_CMD (1u)
/* @brief Has 0x45 Verify Backdoor Access Key command. */
#define FEATURE_FLS_HAS_VERIFY_BACKDOOR_ACCESS_KEY_CMD (1u)
/* @brief Has 0x46 Swap Control command. */
#define FEATURE_FLS_HAS_SWAP_CONTROL_CMD (0u)
/* @brief Has 0x49 Erase All Blocks unsecure command. */
#define FEATURE_FLS_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD (1u)
/* @brief Has 0x80 Program Partition command. */
#define FEATURE_FLS_HAS_PROGRAM_PARTITION_CMD (1u)
/* @brief Has 0x81 Set FlexRAM Function command. */
#define FEATURE_FLS_HAS_SET_FLEXRAM_FUNCTION_CMD (1u)
/* @brief P-Flash Erase/Read 1st all block command address alignment. */
#define FEATURE_FLS_PF_BLOCK_CMD_ADDRESS_ALIGMENT (16u)
/* @brief P-Flash Erase sector command address alignment. */
#define FEATURE_FLS_PF_SECTOR_CMD_ADDRESS_ALIGMENT (16u)
/* @brief P-Flash Program/Verify section command address alignment. */
#define FEATURE_FLS_PF_SECTION_CMD_ADDRESS_ALIGMENT (16u)
/* @brief P-Flash Read resource command address alignment. */
#define FEATURE_FLS_PF_RESOURCE_CMD_ADDRESS_ALIGMENT (8u)
/* @brief P-Flash Program check command address alignment. */
#define FEATURE_FLS_PF_CHECK_CMD_ADDRESS_ALIGMENT (4u)
/* @brief P-Flash Program check command address alignment. */
#define FEATURE_FLS_PF_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT (0u)
/* @brief FlexNVM Erase/Read 1st all block command address alignment. */
#define FEATURE_FLS_DF_BLOCK_CMD_ADDRESS_ALIGMENT (8u)
/* @brief FlexNVM Erase sector command address alignment. */
#define FEATURE_FLS_DF_SECTOR_CMD_ADDRESS_ALIGMENT (8u)
/* @brief FlexNVM Program/Verify section command address alignment. */
#define FEATURE_FLS_DF_SECTION_CMD_ADDRESS_ALIGMENT (8u)
/* @brief FlexNVM Read resource command address alignment. */
#define FEATURE_FLS_DF_RESOURCE_CMD_ADDRESS_ALIGMENT (8u)
/* @brief FlexNVM Program check command address alignment. */
#define FEATURE_FLS_DF_CHECK_CMD_ADDRESS_ALIGMENT (4u)
/* @brief FlexNVM partition code 0000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0000 (0x00010000u)
/* @brief FlexNVM partition code 0001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0001 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 0010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0010 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 0011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0011 (0x00008000u)
/* @brief FlexNVM partition code 0100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0100 (0x00000000u)
/* @brief FlexNVM partition code 0101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0101 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 0110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0110 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 0111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_0111 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 1000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1000 (0x00000000u)
/* @brief FlexNVM partition code 1001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1001 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 1010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1010 (0x00004000u)
/* @brief FlexNVM partition code 1011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1011 (0x00008000u)
/* @brief FlexNVM partition code 1100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1100 (0x00010000u)
/* @brief FlexNVM partition code 1101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1101 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 1110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1110 (0xFFFFFFFFu)
/* @brief FlexNVM partition code 1111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FEATURE_FLS_DF_SIZE_1111 (0x00010000u)
/* @brief Emulated EEPROM size code 0000 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0000 (0xFFFFu)
/* @brief Emulated EEPROM size code 0001 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0001 (0xFFFFu)
/* @brief Emulated EEPROM size code 0010 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0010 (0x1000u)
/* @brief Emulated EEPROM size code 0011 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0011 (0x0800u)
/* @brief Emulated EEPROM size code 0100 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0100 (0x0400u)
/* @brief Emulated EEPROM size code 0101 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0101 (0x0200u)
/* @brief Emulated EEPROM size code 0110 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0110 (0x0100u)
/* @brief Emulated EEPROM size code 0111 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_0111 (0x0080u)
/* @brief Emulated EEPROM size code 1000 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1000 (0x0040u)
/* @brief Emulated EEPROM size code 1001 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1001 (0x0020u)
/* @brief Emulated EEPROM size code 1010 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1010 (0xFFFFu)
/* @brief Emulated EEPROM size code 1011 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1011 (0xFFFFu)
/* @brief Emulated EEPROM size code 1100 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1100 (0xFFFFu)
/* @brief Emulated EEPROM size code 1101 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1101 (0xFFFFu)
/* @brief Emulated EEPROM size code 1110 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1110 (0xFFFFu)
/* @brief Emulated EEPROM size code 1111 mapping to emulated EEPROM size in bytes (0xFFFF = reserved). */
#define FEATURE_FLS_EE_SIZE_1111 (0x0000u)

/* CAN module features */

/* @brief Frames available in Rx FIFO flag shift */
#define FEATURE_CAN_RXFIFO_FRAME_AVAILABLE  (5U)
/* @brief Rx FIFO warning flag shift */
#define FEATURE_CAN_RXFIFO_WARNING          (6U)
/* @brief Rx FIFO overflow flag shift */
#define FEATURE_CAN_RXFIFO_OVERFLOW         (7U)
/* @brief Has Flexible Data Rate for CAN0 */
#define FEATURE_CAN0_HAS_FD                 (1)
/* @brief Has Flexible Data Rate for CAN1 */
#define FEATURE_CAN1_HAS_FD                 (0)
/* @brief Has Flexible Data Rate for CAN2 */
#define FEATURE_CAN2_HAS_FD                 (0)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN0 */
#define FEATURE_CAN0_MAX_MB_NUM             (32U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN1 */
#define FEATURE_CAN1_MAX_MB_NUM             (16U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN2 */
#define FEATURE_CAN2_MAX_MB_NUM             (16U)
/* @brief Has PE clock source select (bit field CAN_CTRL1[CLKSRC]). */
#define FEATURE_CAN_HAS_PE_CLKSRC_SELECT    (1)
/* @brief Has DMA enable (bit field MCR[DMA]). */
#define FEATURE_CAN_HAS_DMA_ENABLE          (1)
/* @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances */
#define FEATURE_CAN_MAX_MB_NUM              (32U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances */
#define FEATURE_CAN_MAX_MB_NUM_ARRAY        { FEATURE_CAN0_MAX_MB_NUM, \
                                              FEATURE_CAN1_MAX_MB_NUM, \
                                              FEATURE_CAN2_MAX_MB_NUM }
/* @brief Has Pretending Networking mode */
#define FEATURE_CAN_HAS_PRETENDED_NETWORKING    (1)
/* @brief Has Stuff Bit Count Enable Bit */
#define FEATURE_CAN_HAS_STFCNTEN_ENABLE         (0)
/* @brief Has ISO CAN FD Enable Bit */
#define FEATURE_CAN_HAS_ISOCANFDEN_ENABLE       (1)
/* @brief Has Message Buffer Data Size Region 1 */
#define FEATURE_CAN_HAS_MBDSR1                  (0)
/* @brief Has Message Buffer Data Size Region 2 */
#define FEATURE_CAN_HAS_MBDSR2                  (0)
/* @brief DMA hardware requests for all FlexCAN instances */
#define FEATURE_CAN_EDMA_REQUESTS              { EDMA_REQ_FLEXCAN0, \
                                                 EDMA_REQ_FLEXCAN1, \
                                                 EDMA_REQ_FLEXCAN2 }


/* @brief Maximum number of Message Buffers IRQs */
#define FEATURE_CAN_MB_IRQS_MAX_COUNT       (2U)
/* @brief Message Buffers IRQs */
#define FEATURE_CAN_MB_IRQS                 { CAN_ORed_0_15_MB_IRQS, \
                                              CAN_ORed_16_31_MB_IRQS }
/* @brief Has Wake Up Irq channels (CAN_Wake_Up_IRQS_CH_COUNT > 0u) */
#define FEATURE_CAN_HAS_WAKE_UP_IRQ         (1)

#if FEATURE_CAN_HAS_PE_CLKSRC_SELECT
/*! @brief Number of FlexCAN PE clock sources */
#define FEATURE_CAN_PE_CLK_NUM    2U
/* @brief FlexCAN clock source */
typedef enum {
	FLEXCAN_CLK_SOURCE_SOSCDIV2 = 0U,  /*!< Clock divider 2 for System OSC */
	FLEXCAN_CLK_SOURCE_SYS = 1U        /*!< Sys clock */
} flexcan_clk_source_t;
/* @brief Clock names for FlexCAN PE clock */
#define FLEXCAN_PE_CLOCK_NAMES { FLEXCAN_CLK_SOURCE_SOSCDIV2, FLEXCAN_CLK_SOURCE_SYS }
#endif
/* @brief Has Self Wake Up mode */
#define FEATURE_CAN_HAS_SELF_WAKE_UP        (0)

/* LPUART module features */

/* @brief Has extended data register ED. */
#define FEATURE_LPUART_HAS_EXTENDED_DATA_REGISTER_FLAGS (1)
/* @brief Hardware flow control (RTS, CTS) is supported. */
#define FEATURE_LPUART_HAS_MODEM_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FEATURE_LPUART_HAS_BAUD_RATE_OVER_SAMPLING_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FEATURE_LPUART_HAS_BOTH_EDGE_SAMPLING_SUPPORT (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FEATURE_LPUART_FIFO_SIZE (4U)
/* @brief Supports two match addresses to filter incoming frames. */
#define FEATURE_LPUART_HAS_ADDRESS_MATCHING (1)
/* @brief Has transmitter/receiver DMA enable bits. */
#define FEATURE_LPUART_HAS_DMA_ENABLE (1)
/* @brief Flag clearance mask for STAT register. */
#define FEATURE_LPUART_STAT_REG_FLAGS_MASK (0xC01FC000U)
/* @brief Flag clearance mask for FIFO register. */
#define FEATURE_LPUART_FIFO_REG_FLAGS_MASK (0x00030000U)
/* @brief Default oversampling ratio. */
#define FEATURE_LPUART_DEFAULT_OSR (0x0FUL)
/* @brief Default baud rate modulo divisor. */
#define FEATURE_LPUART_DEFAULT_SBR (0x04UL)
/* @brief Clock names for LPUART. */
#define LPUART_CLOCK_NAMES {LPUART0_CLK, LPUART1_CLK, LPUART2_CLK}

/* FlexIO module features */

/* @brief Define the maximum number of shifters for any FlexIO instance. */
#define FEATURE_FLEXIO_MAX_SHIFTER_COUNT  (4U)
/* @brief Define DMA request names for Flexio. */
#define FEATURE_FLEXIO_DMA_REQ_0    EDMA_REQ_FLEXIO_SHIFTER0
#define FEATURE_FLEXIO_DMA_REQ_1    EDMA_REQ_FLEXIO_SHIFTER1
#define FEATURE_FLEXIO_DMA_REQ_2    EDMA_REQ_FLEXIO_SHIFTER2
#define FEATURE_FLEXIO_DMA_REQ_3    EDMA_REQ_FLEXIO_SHIFTER3

/* LPSPI module features */

/* @brief DMA instance used for LPSPI module */
#define LPSPI_DMA_INSTANCE 0U

/* LPI2C module features */

/* @brief DMA instance used for LPI2C module */
#define LPI2C_DMA_INSTANCE 0U

/* @brief EDMA requests for LPI2C module. */
#define LPI2C_EDMA_REQ                           {{(uint8_t)EDMA_REQ_LPI2C0_TX, (uint8_t)EDMA_REQ_LPI2C0_RX}}
/* @brief PCC clocks for LPI2C module. */
#define LPI2C_PCC_CLOCKS                         {LPI2C0_CLK}

/* PDB module features */

/* @brief Define the count of supporting ADC channels per each PDB. */
#define FEATURE_PDB_ADC_CHANNEL_COUNT     (2U)
/* @brief Define the count of supporting ADC pre-trigger for each channel. */
#define FEATURE_PDB_ADC_PRE_CHANNEL_COUNT (8U)
/* @brief Define the count of supporting Pulse-Out outputs per each PDB. */
#define FEATURE_PDB_PODLY_COUNT           (1U)

/* Interrupt module features */

/* @brief Lowest interrupt request number. */
#define FEATURE_INTERRUPT_IRQ_MIN         (NonMaskableInt_IRQn)
/* @brief Highest interrupt request number. */
#define FEATURE_INTERRUPT_IRQ_MAX         (FTM3_Ovf_Reload_IRQn)
/**< Number of priority bits implemented in the NVIC */
#define FEATURE_NVIC_PRIO_BITS            (4U)
/* @brief Has software interrupt. */
#define FEATURE_INTERRUPT_HAS_SOFTWARE_IRQ	(0u)
/* @brief Has pending interrupt state. */
#define FEATURE_INTERRUPT_HAS_PENDING_STATE	(1u)
/* @brief Has active interrupt state. */
#define FEATURE_INTERRUPT_HAS_ACTIVE_STATE	(1u)


/* System Control Block module features */

/* @brief VECTKEY value so that AIRCR register write is not ignored. */
#define FEATURE_SCB_VECTKEY               (0x05FAU)


/* SMC module features */

/* @brief Has stop option (register bit STOPCTRL[STOPO]). */
#define FEATURE_SMC_HAS_STOPO (1)
/* @brief Has partial stop option (register bit STOPCTRL[PSTOPO]). */
#define FEATURE_SMC_HAS_PSTOPO (0)
/* @brief Has WAIT and VLPW options. */
#define FEATURE_SMC_HAS_WAIT_VLPW (0)
/* @brief Has high speed run mode (register bit PMPROT[AHSRUN]). */
#define FEATURE_SMC_HAS_HIGH_SPEED_RUN_MODE (1)


/* MPU module features */

/* @brief Specifies hardware revision level. */
#define FEATURE_MPU_HARDWARE_REVISION_LEVEL   (1U)
/* @brief Has process identifier support. */
#define FEATURE_MPU_HAS_PROCESS_IDENTIFIER    (1U)
/* @brief Specifies total number of bus masters. */
#define FEATURE_MPU_MASTER_COUNT              (3U)
/* @brief Specifies maximum number of masters which have separated
privilege rights for user and supervisor mode accesses (e.g. master0~3 in S32K14x).
*/
#define FEATURE_MPU_MAX_LOW_MASTER_NUMBER     (3U)
/* @brief Specifies maximum number of masters which have only
read and write permissions (e.g. master4~7 in S32K14x).
*/
#define FEATURE_MPU_MAX_HIGH_MASTER_NUMBER    (7U)

/* @brief Specifies number of set access control right bits for
   masters which have separated privilege rights for user and
   supervisor mode accesses (e.g. master0~3 in S32K14x).
*/
#define FEATURE_MPU_LOW_MASTER_CONTROL_WIDTH  (6U)
/* @brief Specifies number of set access control right bits for
   masters which have only read and write permissions(e.g. master4~7 in S32K14x).
*/
#define FEATURE_MPU_HIGH_MASTER_CONTROL_WIDTH (2U)

/* @brief The MPU Logical Bus Master Number for core bus master. */
#define FEATURE_MPU_MASTER_CORE               (0U)
/* @brief The MPU Logical Bus Master Number for Debugger master. */
#define FEATURE_MPU_MASTER_DEBUGGER           (1U)
/* @brief The MPU Logical Bus Master Number for DMA master. */
#define FEATURE_MPU_MASTER_DMA                (2U)
/* @brief Specifies master number. */
#define FEATURE_MPU_MASTER                        \
{                                                 \
    FEATURE_MPU_MASTER_CORE,     /*!< CORE */     \
    FEATURE_MPU_MASTER_DEBUGGER, /*!< DEBUGGER */ \
    FEATURE_MPU_MASTER_DMA,      /*!< DMA */      \
}

/* @brief Specifies total number of slave ports. */
#define FEATURE_MPU_SLAVE_COUNT               (4U)
/* @brief The MPU Slave Port Assignment for Flash Controller and boot ROM. */
#define FEATURE_MPU_SLAVE_FLASH_BOOTROM       (0U)
/* @brief The MPU Slave Port Assignment for SRAM back door. */
#define FEATURE_MPU_SLAVE_SRAM_BACKDOOR       (1U)
/* @brief The MPU Slave Port Assignment for SRAM_L front door. */
#define FEATURE_MPU_SLAVE_SRAM_L_FRONTDOOR    (2U)
/* @brief The MPU Slave Port Assignment for SRAM_U front door. */
#define FEATURE_MPU_SLAVE_SRAM_U_FRONTDOOR    (3U)
/* @brief The MPU Slave Port mask. */
#define FEATURE_MPU_SLAVE_MASK                (0xF0000000U)
#define FEATURE_MPU_SLAVE_SHIFT               (28u)
#define FEATURE_MPU_SLAVE_WIDTH               (4u)
#define FEATURE_MPU_SLAVE(x)                  (((uint32_t)(((uint32_t)(x))<<FEATURE_MPU_SLAVE_SHIFT))&FEATURE_MPU_SLAVE_MASK)

/* WDOG module features */

/* @brief The 32-bit value used for unlocking the WDOG. */
#define FEATURE_WDOG_UNLOCK_VALUE                       (0xD928C520U)
/* @brief The 32-bit value used for resetting the WDOG counter. */
#define FEATURE_WDOG_TRIGGER_VALUE                      (0xB480A602U)
/* @brief The reset value of the timeout register. */
#define FEATURE_WDOG_TO_RESET_VALUE                     (0x400U)
/* @brief The value minimum of the timeout register. */
#define FEATURE_WDOG_MINIMUM_TIMEOUT_VALUE              (0x0U)
/* @brief The reset value of the window register. */
#define FEATURE_WDOG_WIN_RESET_VALUE                    (0x0U)
/* @brief The mask of the reserved bit in the CS register. */
#define FEATURE_WDOG_CS_RESERVED_MASK                   (0x2000U)
/* @brief The value used to set WDOG source clock from LPO. */
#define FEATURE_WDOG_CLK_FROM_LPO                       (0x1UL)
/* @brief The first 16-bit value used for unlocking the WDOG. */
#define FEATURE_WDOG_UNLOCK16_FIRST_VALUE               (0xC520U)
/* @brief The second 16-bit value used for unlocking the WDOG. */
#define FEATURE_WDOG_UNLOCK16_SECOND_VALUE              (0xD928U)
/* @brief The first 16-bit value used for resetting the WDOG counter. */
#define FEATURE_WDOG_TRIGGER16_FIRST_VALUE              (0xA602U)
/* @brief The second 16-bit value used for resetting the WDOG counter. */
#define FEATURE_WDOG_TRIGGER16_SECOND_VALUE             (0xB480U)

/* CRC module features */

/* @brief CRC module use for S32K1xx. */
#define FEATURE_CRC_DRIVER_S32K1xx      (1)
/* Default CRC bit width */
#define CRC_DEFAULT_WIDTH               CRC_BITS_16
/* Default CRC read transpose */
#define CRC_DEFAULT_READ_TRANSPOSE      CRC_TRANSPOSE_NONE
/* Default polynomial 0x1021U */
#define CRC_DEFAULT_POLYNOMIAL          (0x1021U)

/* EDMA module features */

/* @brief Number of EDMA channels. */
#define FEATURE_EDMA_MODULE_CHANNELS (16U)
/* @brief Number of EDMA channel interrupt lines. */
#define FEATURE_CHANNEL_INTERRUPT_LINES (16U)
/* @brief Number of EDMA error interrupt lines. */
#define FEATURE_ERROR_INTERRUPT_LINES (1U)
/* @brief eDMA module has error interrupt. */
#define FEATURE_EDMA_HAS_ERROR_IRQ
/* @brief eDMA module has separate interrupt lines for each channel. */
#define FEATURE_EDMA_SEPARATE_IRQ_LINES_PER_CHN
/* @brief Conversion from channel index to DCHPRI index. */
#define FEATURE_EDMA_CHN_TO_DCHPRI_INDEX(x) ((x) ^ 3U)
/* @brief eDMA channel groups count. */
#define FEATURE_EDMA_CHANNEL_GROUP_COUNT (1U)
/* @brief Number of eDMA channels with asynchronous request capability. */
#define FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (16U)
/* @brief Clock names for eDMA. */
#define EDMA_CLOCK_NAMES {SIM_DMA_CLK}

/* DMAMUX module features */

/* @brief Number of DMA channels. */
#define FEATURE_DMAMUX_MODULE_CHANNELS (16U)
/* @brief Has the periodic trigger capability */
#define FEATURE_DMAMUX_HAS_TRIG (1)
/* @brief Conversion from request source to the actual DMAMUX channel */
#define FEATURE_DMAMUX_REQ_SRC_TO_CHN(x) (x)
/* @brief Mapping between request source and DMAMUX instance */
#define FEATURE_DMAMUX_REQ_SRC_TO_INSTANCE(x) (0U)
/* @brief Conversion from eDMA channel index to DMAMUX channel. */
#define FEATURE_DMAMUX_CHN_FOR_EDMA_CHN(x) (x)
/* @brief Conversion from DMAMUX channel DMAMUX register index. */
#define FEATURE_DMAMUX_CHN_REG_INDEX(x) (x)
/* @brief Clock names for DMAMUX. */
#define DMAMUX_CLOCK_NAMES {DMAMUX0_CLK}
/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */

typedef enum {
    EDMA_REQ_DISABLED = 0U,
    EDMA_REQ_LPUART0_RX = 2U,
    EDMA_REQ_LPUART0_TX = 3U,
    EDMA_REQ_LPUART1_RX = 4U,
    EDMA_REQ_LPUART1_TX = 5U,
    EDMA_REQ_LPUART2_RX = 6U,
    EDMA_REQ_LPUART2_TX = 7U,
    EDMA_REQ_FLEXIO_SHIFTER0 = 10U,
    EDMA_REQ_FLEXIO_SHIFTER1 = 11U,
    EDMA_REQ_FLEXIO_SHIFTER2 = 12U,
    EDMA_REQ_FLEXIO_SHIFTER3 = 13U,
    EDMA_REQ_LPSPI0_RX = 14U,
    EDMA_REQ_LPSPI0_TX = 15U,
    EDMA_REQ_LPSPI1_RX = 16U,
    EDMA_REQ_LPSPI1_TX = 17U,
    EDMA_REQ_LPSPI2_RX = 18U,
    EDMA_REQ_LPSPI2_TX = 19U,
    EDMA_REQ_FTM1_CHANNEL_0 = 20U,
    EDMA_REQ_FTM1_CHANNEL_1 = 21U,
    EDMA_REQ_FTM1_CHANNEL_2 = 22U,
    EDMA_REQ_FTM1_CHANNEL_3 = 23U,
    EDMA_REQ_FTM1_CHANNEL_4 = 24U,
    EDMA_REQ_FTM1_CHANNEL_5 = 25U,
    EDMA_REQ_FTM1_CHANNEL_6 = 26U,
    EDMA_REQ_FTM1_CHANNEL_7 = 27U,
    EDMA_REQ_FTM2_CHANNEL_0 = 28U,
    EDMA_REQ_FTM2_CHANNEL_1 = 29U,
    EDMA_REQ_FTM2_CHANNEL_2 = 30U,
    EDMA_REQ_FTM2_CHANNEL_3 = 31U,
    EDMA_REQ_FTM2_CHANNEL_4 = 32U,
    EDMA_REQ_FTM2_CHANNEL_5 = 33U,
    EDMA_REQ_FTM2_CHANNEL_6 = 34U,
    EDMA_REQ_FTM2_CHANNEL_7 = 35U,
    EDMA_REQ_FTM0_OR_CH0_CH7 = 36U,
    EDMA_REQ_FTM3_OR_CH0_CH7 = 37U,
    EDMA_REQ_ADC0 = 42U,
    EDMA_REQ_ADC1 = 43U,
    EDMA_REQ_LPI2C0_RX = 44U,
    EDMA_REQ_LPI2C0_TX = 45U,
    EDMA_REQ_PDB0 = 46U,
    EDMA_REQ_PDB1 = 47U,
    EDMA_REQ_CMP0 = 48U,
    EDMA_REQ_PORTA = 49U,
    EDMA_REQ_PORTB = 50U,
    EDMA_REQ_PORTC = 51U,
    EDMA_REQ_PORTD = 52U,
    EDMA_REQ_PORTE = 53U,
    EDMA_REQ_FLEXCAN0 = 54U,
    EDMA_REQ_FLEXCAN1 = 55U,
    EDMA_REQ_FLEXCAN2 = 56U,
    EDMA_REQ_LPTMR0 = 59U,
    EDMA_REQ_DMAMUX_ALWAYS_ENABLED0 = 62U,
    EDMA_REQ_DMAMUX_ALWAYS_ENABLED1 = 63U
} dma_request_source_t;

/* LPI2C module features */

/* @brief Disable high-speed and ultra-fast operating modes for S32K14x. */
#define LPI2C_HAS_FAST_PLUS_MODE (0U)
#define LPI2C_HAS_HIGH_SPEED_MODE (0U)
#define LPI2C_HAS_ULTRA_FAST_MODE (0U)

/* FTM module features */
/* @brief Number of PWM channels */
#define FEATURE_FTM_CHANNEL_COUNT           (8U)
/* @brief Number of fault channels */
#define FTM_FEATURE_FAULT_CHANNELS              (4U)
/* @brief Width of control channel */
#define FTM_FEATURE_COMBINE_CHAN_CTRL_WIDTH     (8U)
/* @brief Output channel offset */
#define FTM_FEATURE_OUTPUT_CHANNEL_OFFSET       (16U)
/* @brief Max counter value */
#define FTM_FEATURE_CNT_MAX_VALUE_U32           (0x0000FFFFU)
/* @brief Input capture for single shot */
#define FTM_FEATURE_INPUT_CAPTURE_SINGLE_SHOT   (2U)
/* @brief Dithering has supported on the generated PWM signals */
#define FEATURE_FTM_HAS_SUPPORTED_DITHERING     (0U)

/* EWM module features */

/* @brief First byte of the EWM Service key        */
#define FEATURE_EWM_KEY_FIRST_BYTE      (0xB4U)
/* @brief Second byte of the EWM Service key       */
#define FEATURE_EWM_KEY_SECOND_BYTE     (0x2CU)
/* @brief EWM Compare High register maximum value  */
#define FEATURE_EWM_CMPH_MAX_VALUE      (0xFEU)
/* @brief EWM Compare Low register minimum value  */
#define FEATURE_EWM_CMPL_MIN_VALUE      (0x00U)

/* CLOCK names */

/*! @brief Clock names. */
typedef enum {

    /* Main clocks */
    CORE_CLK                     = 0u,       /*!< Core clock                     */
    BUS_CLK                      = 1u,       /*!< Bus clock                      */
    SLOW_CLK                     = 2u,       /*!< Slow clock                     */
    CLKOUT_CLK                   = 3u,       /*!< CLKOUT clock                   */

    /* Other internal clocks used by peripherals. */
    SIRC_CLK                     = 4u,       /*!< SIRC clock                     */
    FIRC_CLK                     = 5u,       /*!< FIRC clock                     */
    SOSC_CLK                     = 6u,       /*!< SOSC clock                     */
    SPLL_CLK                     = 7u,       /*!< SPLL clock                     */
    RTC_CLKIN_CLK                = 8u,       /*!< RTC_CLKIN clock                */
    SCG_CLKOUT_CLK               = 9u,       /*!< SCG CLK_OUT clock              */

    SIRCDIV1_CLK                 = 10u,      /*!< SIRCDIV1 functional clock      */
    SIRCDIV2_CLK                 = 11u,      /*!< SIRCDIV2 functional clock      */
    FIRCDIV1_CLK                 = 12u,      /*!< FIRCDIV1 functional clock      */
    FIRCDIV2_CLK                 = 13u,      /*!< FIRCDIV2 functional clock      */
    SOSCDIV1_CLK                 = 14u,      /*!< SOSCDIV1 functional clock      */
    SOSCDIV2_CLK                 = 15u,      /*!< SOSCDIV2 functional clock      */
    SPLLDIV1_CLK                 = 16u,      /*!< SPLLDIV1 functional clock      */
    SPLLDIV2_CLK                 = 17u,      /*!< SPLLDIV2 functional clock      */

    SCG_END_OF_CLOCKS            = 18u,      /*!< End of SCG clocks              */

    /* SIM clocks */
    SIM_FTM0_CLOCKSEL            = 21u,      /*!< FTM0 External Clock Pin Select */
    SIM_FTM1_CLOCKSEL            = 22u,      /*!< FTM1 External Clock Pin Select */
    SIM_FTM2_CLOCKSEL            = 23u,      /*!< FTM2 External Clock Pin Select */
    SIM_FTM3_CLOCKSEL            = 24u,      /*!< FTM3 External Clock Pin Select */
    SIM_CLKOUTSELL               = 25u,      /*!< CLKOUT Select                  */
    SIM_RTCCLK_CLK               = 26u,      /*!< RTCCLK clock                   */
    SIM_LPO_CLK                  = 27u,      /*!< LPO clock                      */
    SIM_LPO_1K_CLK               = 28u,      /*!< LPO 1KHz clock                 */
    SIM_LPO_32K_CLK              = 29u,      /*!< LPO 32KHz clock                */
    SIM_LPO_128K_CLK             = 30u,      /*!< LPO 128KHz clock               */
    SIM_EIM_CLK                  = 31u,      /*!< EIM clock source               */
    SIM_ERM_CLK                  = 32u,      /*!< ERM clock source               */
    SIM_DMA_CLK                  = 33u,      /*!< DMA clock source               */
    SIM_MPU_CLK                  = 34u,      /*!< MPU clock source               */
    SIM_MSCM_CLK                 = 35u,      /*!< MSCM clock source              */
    SIM_END_OF_CLOCKS            = 36u,      /*!< End of SIM clocks              */

    /* PCC clocks */
    CMP0_CLK                     = 41u,      /*!< CMP0 clock source              */
    CRC0_CLK                     = 42u,      /*!< CRC0 clock source              */
    DMAMUX0_CLK                  = 43u,      /*!< DMAMUX0 clock source           */
    EWM0_CLK                     = 44u,      /*!< EWM0 clock source              */
    PORTA_CLK                    = 45u,      /*!< PORTA clock source             */
    PORTB_CLK                    = 46u,      /*!< PORTB clock source             */
    PORTC_CLK                    = 47u,      /*!< PORTC clock source             */
    PORTD_CLK                    = 48u,      /*!< PORTD clock source             */
    PORTE_CLK                    = 49u,      /*!< PORTE clock source             */
    RTC0_CLK                     = 50u,      /*!< RTC0 clock source              */
    PCC_END_OF_BUS_CLOCKS        = 51u,      /*!< End of BUS clocks              */
    FlexCAN0_CLK                 = 52u,      /*!< FlexCAN0 clock source          */
    FlexCAN1_CLK                 = 53u,      /*!< FlexCAN1 clock source          */
    FlexCAN2_CLK                 = 54u,      /*!< FlexCAN2 clock source          */
    PDB0_CLK                     = 55u,      /*!< PDB0 clock source              */
    PDB1_CLK                     = 56u,      /*!< PDB1 clock source              */
    PCC_END_OF_SYS_CLOCKS        = 57u,      /*!< End of SYS clocks              */
    FTFC0_CLK                    = 58u,      /*!< FTFC0 clock source             */
    PCC_END_OF_SLOW_CLOCKS       = 59u,      /*!< End of SLOW clocks             */
    FTM0_CLK                     = 60u,      /*!< FTM0 clock source              */
    FTM1_CLK                     = 61u,      /*!< FTM1 clock source              */
    FTM2_CLK                     = 62u,      /*!< FTM2 clock source              */
    FTM3_CLK                     = 63u,      /*!< FTM3 clock source              */
    PCC_END_OF_ASYNCH_DIV1_CLOCKS= 64u,      /*!< End of ASYNCH DIV1 clocks      */
    ADC0_CLK                     = 65u,      /*!< ADC0 clock source              */
    ADC1_CLK                     = 66u,      /*!< ADC1 clock source              */
    FLEXIO0_CLK                  = 67u,      /*!< FLEXIO0 clock source           */
    LPI2C0_CLK                   = 68u,      /*!< LPI2C0 clock source            */
    LPIT0_CLK                    = 69u,      /*!< LPIT0 clock source             */
    LPSPI0_CLK                   = 70u,      /*!< LPSPI0 clock source            */
    LPSPI1_CLK                   = 71u,      /*!< LPSPI1 clock source            */
    LPSPI2_CLK                   = 72u,      /*!< LPSPI2 clock source            */
    LPTMR0_CLK                   = 73u,      /*!< LPTMR0 clock source            */
    LPUART0_CLK                  = 74u,      /*!< LPUART0 clock source           */
    LPUART1_CLK                  = 75u,      /*!< LPUART1 clock source           */
    LPUART2_CLK                  = 76u,      /*!< LPUART2 clock source           */
    PCC_END_OF_ASYNCH_DIV2_CLOCKS= 77u,      /*!< End of ASYNCH DIV2 clocks      */
    PCC_END_OF_CLOCKS            = 78u,      /*!< End of PCC clocks              */
    CLOCK_NAME_COUNT             = 79u,      /*!< The total number of entries    */
} clock_names_t;

#define PCC_INVALID_INDEX  0

  /*! @brief PCC clock name mappings
   *  Mappings between clock names and peripheral clock control indexes.
   *  If there is no peripheral clock control index for a clock name,
   *  then the corresponding value is PCC_INVALID_INDEX.
   */
#define PCC_CLOCK_NAME_MAPPINGS \
{                                                                                \
PCC_INVALID_INDEX,                  /*!< Core clock                      0  */   \
PCC_INVALID_INDEX,                  /*!< Bus clock                       1  */   \
PCC_INVALID_INDEX,                  /*!< Slow clock                      2  */   \
PCC_INVALID_INDEX,                  /*!< CLKOUT clock                    3  */   \
PCC_INVALID_INDEX,                  /*!< SIRC clock                      4  */   \
PCC_INVALID_INDEX,                  /*!< FIRC clock                      5  */   \
PCC_INVALID_INDEX,                  /*!< SOSC clock                      6  */   \
PCC_INVALID_INDEX,                  /*!< SPLL clock                      7  */   \
PCC_INVALID_INDEX,                  /*!< RTC_CLKIN clock                 8  */   \
PCC_INVALID_INDEX,                  /*!< SCG CLK_OUT clock               9  */   \
PCC_INVALID_INDEX,                  /*!< SIRCDIV1 functional clock       10 */   \
PCC_INVALID_INDEX,                  /*!< SIRCDIV2 functional clock       11 */   \
PCC_INVALID_INDEX,                  /*!< FIRCDIV1 functional clock       12 */   \
PCC_INVALID_INDEX,                  /*!< FIRCDIV2 functional clock       13 */   \
PCC_INVALID_INDEX,                  /*!< SOSCDIV1 functional clock       14 */   \
PCC_INVALID_INDEX,                  /*!< SOSCDIV2 functional clock       15 */   \
PCC_INVALID_INDEX,                  /*!< SPLLDIV1 functional clock       16 */   \
PCC_INVALID_INDEX,                  /*!< SPLLDIV2 functional clock       17 */   \
PCC_INVALID_INDEX,                  /*!< End of SCG clocks               18 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 19 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 20 */   \
PCC_INVALID_INDEX,                  /*!< FTM0 External Clock Pin Select  21 */   \
PCC_INVALID_INDEX,                  /*!< FTM1 External Clock Pin Select  22 */   \
PCC_INVALID_INDEX,                  /*!< FTM2 External Clock Pin Select  23 */   \
PCC_INVALID_INDEX,                  /*!< FTM3 External Clock Pin Select  24 */   \
PCC_INVALID_INDEX,                  /*!< CLKOUT Select                   25 */   \
PCC_INVALID_INDEX,                  /*!< CLK32K clock                    26 */   \
PCC_INVALID_INDEX,                  /*!< LPO clock                       27 */   \
PCC_INVALID_INDEX,                  /*!< LPO 1KHz clock                  28 */   \
PCC_INVALID_INDEX,                  /*!< LPO 32KHz clock                 29 */   \
PCC_INVALID_INDEX,                  /*!< LPO 128KHz clock                30 */   \
PCC_INVALID_INDEX,                  /*!< EIM clock source                31 */   \
PCC_INVALID_INDEX,                  /*!< ERM clock source                32 */   \
PCC_INVALID_INDEX,                  /*!< DMA clock source                33 */   \
PCC_INVALID_INDEX,                  /*!< MPU clock source                34 */   \
PCC_INVALID_INDEX,                  /*!< MSCM clock source               35 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 36 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 37 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 38 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 39 */   \
PCC_INVALID_INDEX,                  /*!< No clock entry in clock_names_t 40 */   \
PCC_CMP0_INDEX,                     /*!< CMP0 clock source               41 */   \
PCC_CRC_INDEX,                      /*!< CRC clock source                42 */   \
PCC_DMAMUX_INDEX,                   /*!< DMAMUX clock source             43 */   \
PCC_EWM_INDEX,                      /*!< EWM clock source                44 */   \
PCC_PORTA_INDEX,                    /*!< PORTA clock source              45 */   \
PCC_PORTB_INDEX,                    /*!< PORTB clock source              46 */   \
PCC_PORTC_INDEX,                    /*!< PORTC clock source              47 */   \
PCC_PORTD_INDEX,                    /*!< PORTD clock source              48 */   \
PCC_PORTE_INDEX,                    /*!< PORTE clock source              49 */   \
PCC_RTC_INDEX,                      /*!< RTC clock source                50 */   \
PCC_INVALID_INDEX,                  /*!< End of BUS clocks               51 */   \
PCC_FlexCAN0_INDEX,                 /*!< FlexCAN0 clock source           52 */   \
PCC_FlexCAN1_INDEX,                 /*!< FlexCAN1 clock source           53 */   \
PCC_FlexCAN2_INDEX,                 /*!< FlexCAN2 clock source           54 */   \
PCC_PDB0_INDEX,                     /*!< PDB0 clock source               55 */   \
PCC_PDB1_INDEX,                     /*!< PDB1 clock source               56 */   \
PCC_INVALID_INDEX,                  /*!< End of SYS clocks               57 */   \
PCC_FTFC_INDEX,                     /*!< FTFC clock source               58 */   \
PCC_INVALID_INDEX,                  /*!< End of SLOW clocks              59 */   \
PCC_FTM0_INDEX,                     /*!< FTM0 clock source               60 */   \
PCC_FTM1_INDEX,                     /*!< FTM1 clock source               61 */   \
PCC_FTM2_INDEX,                     /*!< FTM2 clock source               62 */   \
PCC_FTM3_INDEX,                     /*!< FTM3 clock source               63 */   \
PCC_INVALID_INDEX,                  /*!< End of ASYNCH DIV1 clocks       64 */   \
PCC_ADC0_INDEX,                     /*!< ADC0 clock source               65 */   \
PCC_ADC1_INDEX,                     /*!< ADC1 clock source               66 */   \
PCC_FlexIO_INDEX,                   /*!< FLEXIO clock source             67 */   \
PCC_LPI2C0_INDEX,                   /*!< LPI2C0 clock source             68 */   \
PCC_LPIT_INDEX,                     /*!< LPIT clock source               69 */   \
PCC_LPSPI0_INDEX,                   /*!< LPSPI0 clock source             70 */   \
PCC_LPSPI1_INDEX,                   /*!< LPSPI1 clock source             71 */   \
PCC_LPSPI2_INDEX,                   /*!< LPSPI2 clock source             72 */   \
PCC_LPTMR0_INDEX,                   /*!< LPTMR0 clock source             73 */   \
PCC_LPUART0_INDEX,                  /*!< LPUART0 clock source            74 */   \
PCC_LPUART1_INDEX,                  /*!< LPUART1 clock source            75 */   \
PCC_LPUART2_INDEX,                  /*!< LPUART2 clock source            76 */   \
PCC_INVALID_INDEX,                  /*!< End of ASYNCH DIV2 clocks       77 */   \
PCC_INVALID_INDEX,                  /*!< End of PCC clocks               78 */   \
}

/*! @brief Peripheral instance features
 *  List of features that are supported by a peripheral instance
 */
#define NO_PERIPHERAL_FEATURE                   (0U)         /* It's not a peripheral instance, there is no peripheral feature. */
#define HAS_CLOCK_GATING_IN_SIM                 (1U << 0U)   /* Clock gating is implemented in SIM (it's not in PCC) */
#define HAS_MULTIPLIER                          (1U << 1U)   /* Multiplier is implemented in PCC */
#define HAS_DIVIDER                             (1U << 2U)   /* Divider is implemented in PCC */
#define HAS_PROTOCOL_CLOCK_FROM_ASYNC1          (1U << 3U)   /* Functional clock source is provided by the first asynchronous clock. */
#define HAS_PROTOCOL_CLOCK_FROM_ASYNC2          (1U << 4U)   /* Functional clock source is provided by the second asynchronous clock. */
#define HAS_INT_CLOCK_FROM_BUS_CLOCK            (1U << 5U)   /* Interface clock is provided by the bus clock. */
#define HAS_INT_CLOCK_FROM_SYS_CLOCK            (1U << 6U)   /* Interface clock is provided by the sys clock. */
#define HAS_INT_CLOCK_FROM_SLOW_CLOCK           (1U << 7U)   /* Interface clock is provided by the slow clock. */

/*! @brief Peripheral features.
*  List of features for each clock name. If a clock name is not
*  a peripheral, no feature is supported.
*/
#define PERIPHERAL_FEATURES \
{                                                                                                                                                \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< Core clock                      0  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< Bus clock                       1  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< Slow clock                      2  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< CLKOUT clock                    3  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< SIRC clock                      4  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< FIRC clock                      5  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< SOSC clock                      6  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< SPLL clock                      7  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< RTC_CLKIN clock                 8  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< SCG CLK_OUT clock               9  */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of SCG clocks               10 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 11 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 12 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 13 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 14 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 15 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 16 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 17 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 18 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 19 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 20 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< FTM0 External Clock Pin Select  21 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< FTM1 External Clock Pin Select  22 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< FTM2 External Clock Pin Select  23 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< FTM3 External Clock Pin Select  24 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< CLKOUT Select                   25 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< CLK32K clock                    26 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< LPO clock                       27 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< LPO 1KHz clock                  28 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< LPO 32KHz clock                 29 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< LPO 128KHz clock                30 */   \
(HAS_CLOCK_GATING_IN_SIM | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                           /*!< EIM clock source                31 */   \
(HAS_CLOCK_GATING_IN_SIM | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                           /*!< ERM clock source                32 */   \
(HAS_CLOCK_GATING_IN_SIM | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                           /*!< DMA clock source                33 */   \
(HAS_CLOCK_GATING_IN_SIM | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                           /*!< MPU clock source                34 */   \
(HAS_CLOCK_GATING_IN_SIM | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                           /*!< MSCM clock source               35 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 36 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 37 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 38 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 39 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< No clock entry in clock_names_t 40 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< CMP0 clock source               41 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< CRC clock source                42 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< DMAMUX clock source             43 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< EWM clock source                44 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< PORTA clock source              45 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< PORTB clock source              46 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< PORTC clock source              47 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< PORTD clock source              48 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< PORTE clock source              49 */   \
(HAS_INT_CLOCK_FROM_BUS_CLOCK),                                                                     /*!< RTC clock source                50 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of BUS clocks               51 */   \
(HAS_INT_CLOCK_FROM_SYS_CLOCK),                                                                     /*!< FlexCAN0 clock source           52 */   \
(HAS_INT_CLOCK_FROM_SYS_CLOCK),                                                                     /*!< FlexCAN1 clock source           53 */   \
(HAS_INT_CLOCK_FROM_SYS_CLOCK),                                                                     /*!< FlexCAN2 clock source           54 */   \
(HAS_INT_CLOCK_FROM_SYS_CLOCK),                                                                     /*!< PDB0 clock source               55 */   \
(HAS_INT_CLOCK_FROM_SYS_CLOCK),                                                                     /*!< PDB1 clock source               56 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of SYS clocks               57 */   \
(HAS_INT_CLOCK_FROM_SLOW_CLOCK),                                                                    /*!< FTFC clock source               58 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of SLOW clocks              59 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC1 | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                    /*!< FTM0 clock source               60 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC1 | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                    /*!< FTM1 clock source               61 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC1 | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                    /*!< FTM2 clock source               62 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC1 | HAS_INT_CLOCK_FROM_SYS_CLOCK),                                    /*!< FTM3 clock source               63 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of ASYNCH DIV1 clocks       64 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< ADC0 clock source               65 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< ADC1 clock source               66 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< FLEXIO clock source             67 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPI2C0 clock source             68 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPIT clock source               69 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPSPI0 clock source             70 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPSPI1 clock source             71 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPSPI2 clock source             72 */   \
(HAS_MULTIPLIER | HAS_DIVIDER | HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),     /*!< LPTMR0 clock source             73 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPUART0 clock source            74 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPUART1 clock source            75 */   \
(HAS_PROTOCOL_CLOCK_FROM_ASYNC2 | HAS_INT_CLOCK_FROM_BUS_CLOCK),                                    /*!< LPUART2 clock source            76 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of ASYNCH DIV2 clocks       77 */   \
(NO_PERIPHERAL_FEATURE),                                                                            /*!< End of PCC clocks               78 */   \
}

/* Time to wait for SIRC to stabilize (number of
 * cycles when core runs at maximum speed - 112 MHz */
#define SIRC_STABILIZATION_TIMEOUT 26U;

/* Time to wait for FIRC to stabilize (number of
 * cycles when core runs at maximum speed - 112 MHz */
#define FIRC_STABILIZATION_TIMEOUT 10U;

/* Time to wait for SOSC to stabilize (number of
 * cycles when core runs at maximum speed - 112 MHz */
#define SOSC_STABILIZATION_TIMEOUT 3205000U;

/* Time to wait for SPLL to stabilize (number of
 * cycles when core runs at maximum speed - 112 MHz */
#define SPLL_STABILIZATION_TIMEOUT 1000U;

/*! @brief Maximum frequencies of core, bus and flash clocks.
 *  Each entry represents the maximum frequency of
 *  SYS_CLK (CORE_CLK), BUS_CLK, SLOW_CLK (FLASH_CLK)
 *  in VLPR, RUN and HSRUN modes.
 *
 *          SYS_CLK  BUS_CLK  SLOW_CLK
 *  VLPR       *        *         *
 *  RUN        *        *         *
 *  HSRUN      *        *         *
 */
#define MAX_FREQ_VLPR     0U
#define MAX_FREQ_RUN      1U
#define MAX_FREQ_HSRUN    2U

#define MAX_FREQ_SYS_CLK  0U
#define MAX_FREQ_BUS_CLK  1U
#define MAX_FREQ_SLOW_CLK 2U

#define MAX_FREQ_MODES_NO 3U
#define MAX_FREQ_CLK_NO   3U

#define CLOCK_MAX_FREQUENCIES                                                                      \
{/* SYS_CLK  BUS_CLK SLOW_CLK */                                                                   \
{  4000000, 4000000, 1000000},               /*!< MAX FREQ in low power modes */                   \
{ 80000000,40000000,26670000},               /*!< MAX FREQ in normal power modes */                \
{112000000,56000000,28000000},               /*!< MAX FREQ in high speed modes */                  \
}


/*! @brief Temporary system clock source configurations.
 *         Each line represents the SYS(CORE), BUS and SLOW(FLASH) dividers
 *         for SIRC, FIRC, SOSC and SPLL clock sources.
  *
 *          SYS_CLK  BUS_CLK  SLOW_CLK
 *  SIRC       *        *         *
 *  FIRC       *        *         *
 *  SOSC       *        *         *
 *  SPLL       *        *         *
 */
#define TMP_SIRC_CLK   0U
#define TMP_FIRC_CLK   1U
#define TMP_SOSC_CLK   2U
#define TMP_SPLL_CLK   3U

#define TMP_SYS_DIV    0U
#define TMP_BUS_DIV    1U
#define TMP_SLOW_DIV   2U

#define TMP_SYS_CLK_NO 4U
#define TMP_SYS_DIV_NO 3U

#define TMP_SYSTEM_CLOCK_CONFIGS                                                                                \
{  /*       SYS_CLK                    BUS_CLK                  SLOW_CLK      */                                \
{  SCG_SYSTEM_CLOCK_DIV_BY_1, SCG_SYSTEM_CLOCK_DIV_BY_1, SCG_SYSTEM_CLOCK_DIV_BY_1},  /*!< Dividers for SIRC */ \
{  SCG_SYSTEM_CLOCK_DIV_BY_1, SCG_SYSTEM_CLOCK_DIV_BY_2, SCG_SYSTEM_CLOCK_DIV_BY_4},  /*!< Dividers for FIRC */ \
{  SCG_SYSTEM_CLOCK_DIV_BY_1, SCG_SYSTEM_CLOCK_DIV_BY_2, SCG_SYSTEM_CLOCK_DIV_BY_2},  /*!< Dividers for SOSC */ \
{  SCG_SYSTEM_CLOCK_DIV_BY_3, SCG_SYSTEM_CLOCK_DIV_BY_2, SCG_SYSTEM_CLOCK_DIV_BY_2},  /*!< Dividers for SPLL */ \
}

/* Do not use the old names of the renamed symbols */
/* #define DO_NOT_USE_DEPRECATED_SYMBOLS */

/*! START !DO_NOT_USE_DEPRECATED_SYMBOLS
 *  These symbols have been renamed.
 *  The old names (deprecated symbols)
 *  are defined for backward compatibility.
 */
#if !defined(DO_NOT_USE_DEPRECATED_SYMBOLS)
#define    CORE_CLOCK               CORE_CLK
#define    BUS_CLOCK                BUS_CLK
#define    SLOW_CLOCK               SLOW_CLK
#define    CLKOUT_CLOCK             CLKOUT_CLK
#define    SIRC_CLOCK               SIRC_CLK
#define    FIRC_CLOCK               FIRC_CLK
#define    SOSC_CLOCK               SOSC_CLK
#define    SPLL_CLOCK               SPLL_CLK
#define    RTC_CLKIN_CLOCK          RTC_CLKIN_CLK
#define    SCG_CLKOUT_CLOCK         SCG_CLKOUT_CLK
#define    SIM_RTCCLK_CLOCK         SIM_RTCCLK_CLK
#define    SIM_LPO_CLOCK            SIM_LPO_CLK
#define    SIM_LPO_1K_CLOCK         SIM_LPO_1K_CLK
#define    SIM_LPO_32K_CLOCK        SIM_LPO_32K_CLK
#define    SIM_LPO_128K_CLOCK       SIM_LPO_128K_CLK
#define    SIM_EIM_CLOCK            SIM_EIM_CLK
#define    SIM_ERM_CLOCK            SIM_ERM_CLK
#define    SIM_DMA_CLOCK            SIM_DMA_CLK
#define    SIM_MPU_CLOCK            SIM_MPU_CLK
#define    SIM_MSCM_CLOCK           SIM_MSCM_CLK
#define    PCC_DMAMUX0_CLOCK        DMAMUX0_CLK
#define    PCC_CRC0_CLOCK           CRC0_CLK
#define    PCC_RTC0_CLOCK           RTC0_CLK
#define    PCC_PORTA_CLOCK          PORTA_CLK
#define    PCC_PORTB_CLOCK          PORTB_CLK
#define    PCC_PORTC_CLOCK          PORTC_CLK
#define    PCC_PORTD_CLOCK          PORTD_CLK
#define    PCC_PORTE_CLOCK          PORTE_CLK
#define    PCC_EWM0_CLOCK           EWM0_CLK
#define    PCC_CMP0_CLOCK           CMP0_CLK
#define    PCC_FlexCAN0_CLOCK       FlexCAN0_CLK
#define    PCC_FlexCAN1_CLOCK       FlexCAN1_CLK
#define    PCC_FlexCAN2_CLOCK       FlexCAN2_CLK
#define    PCC_PDB1_CLOCK           PDB1_CLK
#define    PCC_PDB0_CLOCK           PDB0_CLK
#define    PCC_FTFC0_CLOCK          FTFC0_CLK
#define    PCC_FTM0_CLOCK           FTM0_CLK
#define    PCC_FTM1_CLOCK           FTM1_CLK
#define    PCC_FTM2_CLOCK           FTM2_CLK
#define    PCC_FTM3_CLOCK           FTM3_CLK
#define    PCC_ADC1_CLOCK           ADC1_CLK
#define    PCC_LPSPI0_CLOCK         LPSPI0_CLK
#define    PCC_LPSPI1_CLOCK         LPSPI1_CLK
#define    PCC_LPSPI2_CLOCK         LPSPI2_CLK
#define    PCC_LPIT0_CLOCK          LPIT0_CLK
#define    PCC_ADC0_CLOCK           ADC0_CLK
#define    PCC_LPTMR0_CLOCK         LPTMR0_CLK
#define    PCC_FLEXIO0_CLOCK        FLEXIO0_CLK
#define    PCC_LPI2C0_CLOCK         LPI2C0_CLK
#define    PCC_LPUART0_CLOCK        LPUART0_CLK
#define    PCC_LPUART1_CLOCK        LPUART1_CLK
#define    PCC_LPUART2_CLOCK        LPUART2_CLK
#endif /* !DO_NOT_USE_DEPRECATED_SYMBOLS */


/* CSEc module features */

/*! @brief CSE_PRAM offset of the page length parameter used by the following
commands: CMD_ENC_ECB, CMD_ENC_CBC, CMD_DEC_ECB, CMD_DEC_CBC, CMD_MP_COMPRESS */
#define FEATURE_CSEC_PAGE_LENGTH_OFFSET                   (0xEU)
/*! @brief CSE_PRAM offset of the message length parameter used by the following
commands: CMD_GENERATE_MAC, CMD_VERIFY_MAC (both copy and pointer methods) */
#define FEATURE_CSEC_MESSAGE_LENGTH_OFFSET                (0xCU)
/*! @brief CSE_PRAM offset of the MAC length parameter used by the following
commands: CMD_VERIFY_MAC (both copy and pointer methods) */
#define FEATURE_CSEC_MAC_LENGTH_OFFSET                    (0x8U)
/*! @brief CSE_PRAM offset of the boot size parameter used by the following
commands: CMD_BOOT_DEFINE */
#define FEATURE_CSEC_BOOT_SIZE_OFFSET                     (0x1CU)
/*! @brief CSE_PRAM offset of the boot flavor parameter used by the following
commands: CMD_BOOT_DEFINE */
#define FEATURE_CSEC_BOOT_FLAVOR_OFFSET                   (0x1BU)
/*! @brief CSE_PRAM offset of the Flash start address parameter used by the
following commands: CMD_GENERATE_MAC, CMD_VERIFY_MAC (pointer method) */
#define FEATURE_CSEC_FLASH_START_ADDRESS_OFFSET           (0x10U)
/*! @brief CSE_PRAM offset of the verification status parameter used by the
following commands: CMD_VERIFY_MAC (both copy and pointer methods) */
#define FEATURE_CSEC_VERIFICATION_STATUS_OFFSET           (0x14U)
/*! @brief CSE_PRAM offset of the error bits field contained by all commands */
#define FEATURE_CSEC_ERROR_BITS_OFFSET                    (0x4U)
/*! @brief CSE_PRAM offset of the SREG parameter used by the following commands:
CMD_GET_ID */
#define FEATURE_CSEC_SREG_OFFSET                          (0x2FU)

/*! @brief CSE_PRAM offset of page 0 */
#define FEATURE_CSEC_PAGE_0_OFFSET                        (0x0U)
/*! @brief CSE_PRAM offset of page 1 */
#define FEATURE_CSEC_PAGE_1_OFFSET                        (0x10U)
/*! @brief CSE_PRAM offset of page 2 */
#define FEATURE_CSEC_PAGE_2_OFFSET                        (0x20U)
/*! @brief CSE_PRAM offset of page 3 */
#define FEATURE_CSEC_PAGE_3_OFFSET                        (0x30U)
/*! @brief CSE_PRAM offset of page 4 */
#define FEATURE_CSEC_PAGE_4_OFFSET                        (0x40U)
/*! @brief CSE_PRAM offset of page 5 */
#define FEATURE_CSEC_PAGE_5_OFFSET                        (0x50U)
/*! @brief CSE_PRAM offset of page 6 */
#define FEATURE_CSEC_PAGE_6_OFFSET                        (0x60U)
/*! @brief CSE_PRAM offset of page 7 */
#define FEATURE_CSEC_PAGE_7_OFFSET                        (0x70U)


/* ADC module features */

/*! @brief ADC feature flag for extended number of SC1 and R registers,
 * generically named 'alias registers' */
#define FEATURE_ADC_HAS_EXTRA_NUM_REGS                    (0)

/*! @brief ADC feature flag for defining number of external ADC channels.
 * If each ADC instance has different number of external channels, then
 * this define is set with the maximum value. */
#define FEATURE_ADC_MAX_NUM_EXT_CHANS                     (16)

/*! @brief ADC number of control channels */
#if FEATURE_ADC_HAS_EXTRA_NUM_REGS
#define ADC_CTRL_CHANS_COUNT                              ADC_aSC1_COUNT
#else
#define ADC_CTRL_CHANS_COUNT                              ADC_SC1_COUNT
#endif /* FEATURE_ADC_HAS_EXTRA_NUM_REGS */

/*! @brief ADC default Sample Time from RM */
#define ADC_DEFAULT_SAMPLE_TIME                           (0x0CU)
/*! @brief ADC default User Gain from RM */
#define ADC_DEFAULT_USER_GAIN                             (0x04U)

/* MSCM module features */

/* @brief Has interrupt router control registers (IRSPRCn). */
#define FEATURE_MSCM_HAS_INTERRUPT_ROUTER                (0)
/* @brief Has directed CPU interrupt routerregisters (IRCPxxx). */
#define FEATURE_MSCM_HAS_CPU_INTERRUPT_ROUTER            (0)

/* OSIF module features */

#define FEATURE_OSIF_USE_SYSTICK                         (1)
#define FEATURE_OSIF_FREERTOS_ISR_CONTEXT_METHOD         (1) /* Cortex M device */

/* TRGMUX module features */

#define FEATURE_TRGMUX_HAS_EXTENDED_NUM_TRIGS            (0)

/* LPSPI module features */
/* @brief Initial value for state structure */
#define FEATURE_LPSPI_STATE_STRUCTURES_NULL {NULL, NULL, NULL}

#endif /* S32K144_FEATURES_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
