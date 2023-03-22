################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC/ADC_proj.c 

OBJS += \
./MCAL/ADC/ADC_proj.o 

C_DEPS += \
./MCAL/ADC/ADC_proj.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ADC/%.o: ../MCAL/ADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\APP" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\MCAL\TIMER" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\MCAL\TIMER1" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\HAL\KEYPAD" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\HAL\LCD" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\HAL\LED" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\HAL\LM35" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\LIB" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\MCAL\ADC" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\MCAL\DIO" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\MCAL\EXT1" -I"F:\communication engineering\embedded system\nti\avr interfaces\eclipse_ex\SMARTH\MCAL\GIE" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


