/*
 * ADC_int.h
 *
 *  Created on: ١٣‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_


typedef enum{

	prescaler_2 = 1,//1
	prescaler_4,
	prescaler_8,
	prescaler_16,
	prescaler_32,
	prescaler_64,
	prescaler_128

}prescaler_t;

typedef enum{

	vref_Aref,
	vref_Avcc,
	vref_internal = 3 //2.65 v



}vref_t;

typedef enum{

	channel0, //temp sensor
	channel1, // smock
	channel2,
	channel3,
	channel4,
	channel5,
	channel7

}channel_t;
void M_ADC_voidInit(prescaler_t copy_prescaler,vref_t copy_vref);
u16 M_ADC_voidRead(channel_t copy_channel);



#endif /* ADC_ADC_INT_H_ */


