################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/ftm/ftm.c" \

C_SRCS += \
../src/ftm/ftm.c \

C_DEPS_QUOTED += \
"./src/ftm/ftm.d" \

OBJS_QUOTED += \
"./src/ftm/ftm.o" \

C_DEPS += \
./src/ftm/ftm.d \

OBJS_OS_FORMAT += \
./src/ftm/ftm.o \

OBJS += \
./src/ftm/ftm.o \


# Each subdirectory must supply rules for building sources it contributes
src/ftm/ftm.o: ../src/ftm/ftm.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/ftm/ftm.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/ftm/ftm.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


