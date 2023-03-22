/*
 * ADC_proj.c
 *
 *  Created on: ١٣‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_int.h"
#include"ADC_priv.h"
#include"ADC_config.h"
#include "ADC_int.h"

void M_ADC_voidInit(prescaler_t copy_prescaler,vref_t copy_vref)
{


//choose prescaller
	ADCSRA_REG&=ADC_PRESCALER;
	//INSERT VALUE
	ADCSRA_REG|=copy_prescaler;


//SET_BIT(ADCSRA_REG,ADPS0);
//SET_BIT(ADCSRA_REG,ADPS1);
//SET_BIT(ADCSRA_REG,ADPS2);
//STEP 2 disable interrupt
CLR_BIT(ADCSRA_REG,ADIE);
//STEP 3config right adjust
CLR_BIT(ADMUX_REG,ADLAR_BIT);

// disable auto trigger

// SET vref references
 ADMUX_REG &= 0b00111111;
SET_BIT(ADMUX_REG,REFS0_BIT);
//ENABLE ADC
SET_BIT(ADCSRA_REG,ADEN);


}
u16 M_ADC_voidRead(channel_t copy_channel)
{
     u16 Value;
	//config channel
	   //APPLY NMASK
	ADMUX_REG&=ADC_CHANNEL_MASK;
	   //STEP INSERT VALUE'
	ADMUX_REG|=copy_channel;

	// single conversion START CONVERSION;
   SET_BIT(ADCSRA_REG,ADSC);

//step 3 pollinfg wait untill conversion is done
   while((GET_BIT(ADCSRA_REG,ADSC))==0);


//step 4 return digital value

 Value=ADCL_REG;
 return Value;
}
