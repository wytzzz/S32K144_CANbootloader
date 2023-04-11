################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/wdog/wdog.c" \

C_SRCS += \
../src/wdog/wdog.c \

OBJS_OS_FORMAT += \
./src/wdog/wdog.o \

C_DEPS_QUOTED += \
"./src/wdog/wdog.d" \

OBJS += \
./src/wdog/wdog.o \

OBJS_QUOTED += \
"./src/wdog/wdog.o" \

C_DEPS += \
./src/wdog/wdog.d \


# Each subdirectory must supply rules for building sources it contributes
src/wdog/wdog.o: ../src/wdog/wdog.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/wdog/wdog.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/wdog/wdog.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


