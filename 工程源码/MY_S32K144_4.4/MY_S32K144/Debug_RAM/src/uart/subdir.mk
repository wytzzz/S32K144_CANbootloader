################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/uart/LPUART.c" \

C_SRCS += \
../src/uart/LPUART.c \

OBJS_OS_FORMAT += \
./src/uart/LPUART.o \

C_DEPS_QUOTED += \
"./src/uart/LPUART.d" \

OBJS += \
./src/uart/LPUART.o \

OBJS_QUOTED += \
"./src/uart/LPUART.o" \

C_DEPS += \
./src/uart/LPUART.d \


# Each subdirectory must supply rules for building sources it contributes
src/uart/LPUART.o: ../src/uart/LPUART.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/uart/LPUART.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/uart/LPUART.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


