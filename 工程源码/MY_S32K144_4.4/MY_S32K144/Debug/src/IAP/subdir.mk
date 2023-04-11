################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/IAP/iap.c" \

C_SRCS += \
../src/IAP/iap.c \

OBJS_OS_FORMAT += \
./src/IAP/iap.o \

C_DEPS_QUOTED += \
"./src/IAP/iap.d" \

OBJS += \
./src/IAP/iap.o \

OBJS_QUOTED += \
"./src/IAP/iap.o" \

C_DEPS += \
./src/IAP/iap.d \


# Each subdirectory must supply rules for building sources it contributes
src/IAP/iap.o: ../src/IAP/iap.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/IAP/iap.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/IAP/iap.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


