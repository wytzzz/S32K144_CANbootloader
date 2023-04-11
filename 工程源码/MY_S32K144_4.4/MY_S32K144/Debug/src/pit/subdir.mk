################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/pit/pit.c" \

C_SRCS += \
../src/pit/pit.c \

OBJS_OS_FORMAT += \
./src/pit/pit.o \

C_DEPS_QUOTED += \
"./src/pit/pit.d" \

OBJS += \
./src/pit/pit.o \

OBJS_QUOTED += \
"./src/pit/pit.o" \

C_DEPS += \
./src/pit/pit.d \


# Each subdirectory must supply rules for building sources it contributes
src/pit/pit.o: ../src/pit/pit.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/pit/pit.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/pit/pit.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


