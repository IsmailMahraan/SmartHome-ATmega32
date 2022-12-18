################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HDCMotor/HDC_Motor_Program.c 

OBJS += \
./HAL/HDCMotor/HDC_Motor_Program.o 

C_DEPS += \
./HAL/HDCMotor/HDC_Motor_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HDCMotor/%.o: ../HAL/HDCMotor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


