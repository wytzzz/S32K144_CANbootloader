################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/clock/clock.c" \

C_SRCS += \
../src/clock/clock.c \

C_DEPS_QUOTED += \
"./src/clock/clock.d" \

OBJS_QUOTED += \
"./src/clock/clock.o" \

C_DEPS += \
./src/clock/clock.d \

OBJS_OS_FORMAT += \
./src/clock/clock.o \

OBJS += \
./src/clock/clock.o \


# Each subdirectory must supply rules for building sources it contributes
src/clock/clock.o: ../src/clock/clock.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clock/clock.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/clock/clock.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


