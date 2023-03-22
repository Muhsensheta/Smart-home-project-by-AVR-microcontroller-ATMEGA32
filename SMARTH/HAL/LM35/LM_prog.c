/*
 * LM_prog.c
 *
 *  Created on: ١٦‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */


#include "STD_TYPES.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "LM35_priv.h"
#include "LM35_config.h"
#include "LM35_int.h"
void H_TEMPSENSOR_void_Init()
{
   //set direction of temp Sensor channel  pin as input
	M_DIO_void_setPinDir(PORTA_ID,TEMP_SENSOR_CHANNEL, IN);
	// ADC init
	M_ADC_voidInit(prescaler_128, vref_Avcc);

}

u8   H_TEMPSENSOR_u8_readTemp()
{
	// step 1 : call adc to convert (read digital value)
	u16 adc_read = M_ADC_voidRead(TEMP_SENSOR_CHANNEL);
	// step 2: convert digital value to analog
    u32 read_mv =   ( (u32)adc_read * TEMP_VREF)/ TEMP_RES;
    //step 3 : convert from mv to degree C
    u8 temp =  read_mv / 10;
    //step 4 : return temp
    return temp;
}

