################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 15
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
-include src/lpit/subdir.mk
-include src/subdir.mk
-include src/nvic/subdir.mk
-include src/pdb/subdir.mk
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
MY_S32K144.elf \

EXECUTABLES_QUOTED += \
"MY_S32K144.elf" \

EXECUTABLES_OS_FORMAT += \
MY_S32K144.elf \

SECONDARY_SIZE += \
MY_S32K144.siz \

SECONDARY_SIZE_QUOTED += \
"MY_S32K144.siz" \

SECONDARY_SIZE_OS_FORMAT += \
MY_S32K144.siz \


# All Target
all: warning-messages explicit-dependencies MY_S32K144.elf secondary-outputs

# Tool invocations
MY_S32K144.elf: $(OBJS) D:/professional_software/IDE/S32K144/myproject/MY_S32K144/Project_Settings/Linker_Files/S32K1xx_ram.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #16 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "MY_S32K144.elf" "@MY_S32K144.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

MY_S32K144.siz: $(EXECUTABLES)
	@echo 'Executing target #17 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*/*.d ./*/*.d  ./*/*/*.o ./*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

