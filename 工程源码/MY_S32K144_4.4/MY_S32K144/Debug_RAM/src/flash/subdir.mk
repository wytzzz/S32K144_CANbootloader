################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/flash/flash.c" \

C_SRCS += \
../src/flash/flash.c \

OBJS_OS_FORMAT += \
./src/flash/flash.o \

C_DEPS_QUOTED += \
"./src/flash/flash.d" \

OBJS += \
./src/flash/flash.o \

OBJS_QUOTED += \
"./src/flash/flash.o" \

C_DEPS += \
./src/flash/flash.d \


# Each subdirectory must supply rules for building sources it contributes
src/flash/flash.o: ../src/flash/flash.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/flash/flash.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/flash/flash.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


