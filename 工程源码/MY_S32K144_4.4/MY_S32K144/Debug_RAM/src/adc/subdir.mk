################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/adc/adc.c" \

C_SRCS += \
../src/adc/adc.c \

OBJS_OS_FORMAT += \
./src/adc/adc.o \

C_DEPS_QUOTED += \
"./src/adc/adc.d" \

OBJS += \
./src/adc/adc.o \

OBJS_QUOTED += \
"./src/adc/adc.o" \

C_DEPS += \
./src/adc/adc.d \


# Each subdirectory must supply rules for building sources it contributes
src/adc/adc.o: ../src/adc/adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/adc/adc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/adc/adc.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


