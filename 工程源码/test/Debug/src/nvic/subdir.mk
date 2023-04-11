################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/nvic/nvic.c" \

C_SRCS += \
../src/nvic/nvic.c \

C_DEPS_QUOTED += \
"./src/nvic/nvic.d" \

OBJS_QUOTED += \
"./src/nvic/nvic.o" \

C_DEPS += \
./src/nvic/nvic.d \

OBJS_OS_FORMAT += \
./src/nvic/nvic.o \

OBJS += \
./src/nvic/nvic.o \


# Each subdirectory must supply rules for building sources it contributes
src/nvic/nvic.o: ../src/nvic/nvic.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/nvic/nvic.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/nvic/nvic.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


