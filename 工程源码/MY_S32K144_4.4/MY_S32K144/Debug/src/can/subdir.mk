################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/can/can.c" \

C_SRCS += \
../src/can/can.c \

OBJS_OS_FORMAT += \
./src/can/can.o \

C_DEPS_QUOTED += \
"./src/can/can.d" \

OBJS += \
./src/can/can.o \

OBJS_QUOTED += \
"./src/can/can.o" \

C_DEPS += \
./src/can/can.d \


# Each subdirectory must supply rules for building sources it contributes
src/can/can.o: ../src/can/can.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/can/can.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/can/can.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


