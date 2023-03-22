/*
 * ADC_priv.h
 *
 *  Created on: ١٣‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef ADC_ADC_PRIV_H_
#define ADC_ADC_PRIV_H_

#include "STD_TYPES.h"


#define  ADCL_REG   (*((volatile u16*)0x24))
#define  ADCH_REG   (*((volatile u8*)0x25))
#define ADCSRA_REG  (*((volatile u8*)0x26))//select prescaler ,interrupt enable
#define ADMUX_REG   (*((volatile u8*)0x27))//select channel ,left adjust,v ref
#define  SFIOR_REG  (*((volatile u8*)0x50))
//define ADMUX REG BITS
#define MUX0         0
#define MUX1         1
#define MUX2         2
#define MUX3         3
#define MUX4         4
#define ADLAR_BIT    5
#define REFS0_BIT    6
#define REFS1_BIT    7
//define ADCSRA_REG BITS

#define ADPS0        0
#define ADPS1         1
#define ADPS2         2
#define ADIE          3
#define ADIF          4
#define ADATE         5
#define ADSC          6
#define ADEN          7

//
#define ADC_CHANNEL_MASK  0b11100000//0xE0

#define VREF_MASK  0b00111111//0x3F

#define ADC_PRESCALER  0b11111000;
#define VREF_SHIFT 6

//prescaler  macros








#endif /* ADC_ADC_PRIV_H_ */
