################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MEXIT/MEXIT_Program.c 

OBJS += \
./MCAL/MEXIT/MEXIT_Program.o 

C_DEPS += \
./MCAL/MEXIT/MEXIT_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MEXIT/%.o: ../MCAL/MEXIT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


