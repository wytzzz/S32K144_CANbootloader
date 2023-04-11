################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/gpio/gpio.c" \

C_SRCS += \
../src/gpio/gpio.c \

OBJS_OS_FORMAT += \
./src/gpio/gpio.o \

C_DEPS_QUOTED += \
"./src/gpio/gpio.d" \

OBJS += \
./src/gpio/gpio.o \

OBJS_QUOTED += \
"./src/gpio/gpio.o" \

C_DEPS += \
./src/gpio/gpio.d \


# Each subdirectory must supply rules for building sources it contributes
src/gpio/gpio.o: ../src/gpio/gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/gpio/gpio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/gpio/gpio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


