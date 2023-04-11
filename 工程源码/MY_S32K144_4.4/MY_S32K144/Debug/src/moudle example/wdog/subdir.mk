################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/moudle example/wdog/main.c" \

C_SRCS += \
../src/moudle\ example/wdog/main.c \

OBJS_OS_FORMAT += \
./src/moudle\ example/wdog/main.o \

C_DEPS_QUOTED += \
"./src/moudle example/wdog/main.d" \

OBJS += \
./src/moudle\ example/wdog/main.o \

OBJS_QUOTED += \
"./src/moudle example/wdog/main.o" \

C_DEPS += \
./src/moudle\ example/wdog/main.d \


# Each subdirectory must supply rules for building sources it contributes
src/moudle\ example/wdog/main.o: ../src/moudle\ example/wdog/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/moudle example/wdog/main.args" -MMD -MP -MF"src/moudle example/wdog/main.d" -MT"src/moudle\ example/wdog/main.d" -c -o "src/moudle example/wdog/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


