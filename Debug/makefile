################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MUSART/subdir.mk
-include MCAL/MTWI/subdir.mk
-include MCAL/MTIMER2/subdir.mk
-include MCAL/MTIMER1/subdir.mk
-include MCAL/MTIMER0/subdir.mk
-include MCAL/MSPI/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXIT/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HSevenSegment/subdir.mk
-include HAL/HServoMotor/subdir.mk
-include HAL/HRELAY/subdir.mk
-include HAL/HPushButton/subdir.mk
-include HAL/HLM35/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKPD/subdir.mk
-include HAL/HHC05/subdir.mk
-include HAL/HEEPROM/subdir.mk
-include HAL/HDimmer/subdir.mk
-include HAL/HDCMotor/subdir.mk
-include HAL/HCLCD/subdir.mk
-include HAL/HBUZZER/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SmartHomeApp.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: SmartHomeApp.elf secondary-outputs

# Tool invocations
SmartHomeApp.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SmartHomeApp.map -mmcu=atmega32 -o "SmartHomeApp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SmartHomeApp.lss: SmartHomeApp.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SmartHomeApp.elf  >"SmartHomeApp.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SmartHomeApp.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SmartHomeApp.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SmartHomeApp.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
