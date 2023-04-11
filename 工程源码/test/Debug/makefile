################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 14
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/adc/subdir.mk
-include src/can/subdir.mk
-include src/clock/subdir.mk
-include src/flash/subdir.mk
-include src/ftm/subdir.mk
-include src/gpio/subdir.mk
-include src/subdir.mk
-include src/nvic/subdir.mk
-include src/pit/subdir.mk
-include src/uart/subdir.mk
-include src/wdog/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
test.elf \

EXECUTABLES_QUOTED += \
"test.elf" \

EXECUTABLES_OS_FORMAT += \
test.elf \

SECONDARY_FLASH += \
test.bin \

SECONDARY_FLASH_QUOTED += \
"test.bin" \

SECONDARY_FLASH_OS_FORMAT += \
test.bin \

SECONDARY_SIZE += \
test.siz \
test.siz \

SECONDARY_SIZE_QUOTED += \
"test.siz" \
"test.siz" \

SECONDARY_SIZE_OS_FORMAT += \
test.siz \
test.siz \

SECONDARY_SIZE += \
test.siz \
test.siz \

SECONDARY_SIZE_QUOTED += \
"test.siz" \
"test.siz" \

SECONDARY_SIZE_OS_FORMAT += \
test.siz \
test.siz \


# All Target
all: warning-messages explicit-dependencies test.elf secondary-outputs

# Tool invocations
test.elf: $(OBJS) D:/WorkSpace/S32DS.ARM.2018R1/test_wh/test/Project_Settings/Linker_Files/S32K1xx_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #15 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "test.elf" "@test.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

test.bin: $(EXECUTABLES)
	@echo 'Executing target #16 $@'
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O binary $(EXECUTABLES)  "test.bin"
	@echo 'Finished building: $@'
	@echo ' '

test.siz: $(EXECUTABLES)
	@echo 'Executing target #17 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH_QUOTED) ./*/*/*.d ./*/*.d  ./*/*/*.o ./*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE) $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

