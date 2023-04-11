################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/lpit/lpit.c" \

C_SRCS += \
../src/lpit/lpit.c \

OBJS_OS_FORMAT += \
./src/lpit/lpit.o \

C_DEPS_QUOTED += \
"./src/lpit/lpit.d" \

OBJS += \
./src/lpit/lpit.o \

OBJS_QUOTED += \
"./src/lpit/lpit.o" \

C_DEPS += \
./src/lpit/lpit.d \


# Each subdirectory must supply rules for building sources it contributes
src/lpit/lpit.o: ../src/lpit/lpit.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lpit/lpit.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/lpit/lpit.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


