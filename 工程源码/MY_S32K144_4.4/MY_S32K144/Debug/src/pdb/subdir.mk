################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/pdb/pdb.c" \

C_SRCS += \
../src/pdb/pdb.c \

OBJS_OS_FORMAT += \
./src/pdb/pdb.o \

C_DEPS_QUOTED += \
"./src/pdb/pdb.d" \

OBJS += \
./src/pdb/pdb.o \

OBJS_QUOTED += \
"./src/pdb/pdb.o" \

C_DEPS += \
./src/pdb/pdb.d \


# Each subdirectory must supply rules for building sources it contributes
src/pdb/pdb.o: ../src/pdb/pdb.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/pdb/pdb.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "src/pdb/pdb.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


