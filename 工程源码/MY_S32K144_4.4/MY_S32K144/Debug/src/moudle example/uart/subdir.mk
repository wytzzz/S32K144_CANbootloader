################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/moudle example/uart/main.c" \

C_SRCS += \
../src/moudle\ example/uart/main.c \

OBJS_OS_FORMAT += \
./src/moudle\ example/uart/main.o \

C_DEPS_QUOTED += \
"./src/moudle example/uart/main.d" \

OBJS += \
./src/moudle\ example/uart/main.o \

OBJS_QUOTED += \
"./src/moudle example/uart/main.o" \

C_DEPS += \
./src/moudle\ example/uart/main.d \


# Each subdirectory must supply rules for building sources it contributes
src/moudle\ example/uart/main.o: ../src/moudle\ example/uart/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/moudle example/uart/main.args" -MMD -MP -MF"src/moudle example/uart/main.d" -MT"src/moudle\ example/uart/main.d" -c -o "src/moudle example/uart/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


