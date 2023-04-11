################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/uart/uart.c" \

C_SRCS += \
../src/uart/uart.c \

OBJS_OS_FORMAT += \
./src/uart/uart.o \

C_DEPS_QUOTED += \
"./src/uart/uart.d" \

OBJS += \
./src/uart/uart.o \

OBJS_QUOTED += \
"./src/uart/uart.o" \

C_DEPS += \
./src/uart/uart.d \


# Each subdirectory must supply rules for building sources it contributes
src/uart/uart.o: ../src/uart/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/uart/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/uart/uart.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


