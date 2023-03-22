/*
 * LED_prog.c
 *
 *  Created on: ٣١‏/٠١‏/٢٠٢٣
 *      Author: houras
 */
#include"STD_TYPES.h"
#include"DIO_int.h"
#include "LED_priv.h"
#include"LED_config.h"
#include"LED_int.h"

void  H_Led_void_ledInit(u8 LedID)
{
	switch (LedID)
	{
	case RED_LED :
			M_DIO_void_setPinDir(LED_RED_PORT,  LED_RED_PIN , OUT);
		break;
	case GRN_LED :
			M_DIO_void_setPinDir(LED_GRN_PORT,  LED_GRN_PIN , OUT);
			break;
	case BLU_LED :
			M_DIO_void_setPinDir(LED_BLU_PORT,  LED_BLU_PIN , OUT);
			break;
	}
}


void  H_Led_void_setON(u8 LedID)
{
	switch(LedID)
	{
	case RED_LED :
#if (LED_RED_DIRECTION == LED_FORWARD )
		M_DIO_void_setPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
#elif(LED_RED_DIRECTION == LED_REVERSE )
		M_DIO_void_setPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
#endif
		break;

	case GRN_LED :
#if (LED_GRN_DIRECTION == LED_FORWARD )
		M_DIO_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,HIGH);
#elif(LED_RED_DIRECTION == LED_REVERSE )
		M_DIO_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,LOW);
#endif
		break;
	case BLU_LED :
	#if (LED_BLU_DIRECTION == LED_FORWARD )
			M_DIO_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,HIGH);
	#elif(LED_RED_DIRECTION == LED_REVERSE )
			M_DIO_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,LOW);
	#endif
			break;



	}
}
void  H_Led_void_setOFF(u8 LedID)
{
	switch(LedID)
		{
		case RED_LED :
	#if (LED_RED_DIRECTION == LED_FORWARD )
			M_DIO_void_setPinValue(LED_RED_PORT,LED_RED_PIN,LOW);
	#elif(LED_RED_DIRECTION == LED_REVERSE )
			M_DIO_void_setPinValue(LED_RED_PORT,LED_RED_PIN,HIGH);
	#endif
			break;

		case GRN_LED :
	#if (LED_GRN_DIRECTION == LED_FORWARD )
			M_DIO_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,LOW);
	#elif(LED_RED_DIRECTION == LED_REVERSE )
			M_DIO_void_setPinValue(LED_GRN_PORT,LED_GRN_PIN,HIGH);
	#endif
			break;
		case BLU_LED :
		#if (LED_BLU_DIRECTION == LED_FORWARD )
				M_DIO_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,LOW);
		#elif(LED_RED_DIRECTION == LED_REVERSE )
				M_DIO_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,HIGH);
		#endif
				break;

		}
}

void  H_Led_void_toggle(u8 LedID)
{
	switch (LedID)
		{
		case RED_LED :
			 M_DIO_void_TogPinValue(LED_RED_PORT,LED_RED_PIN);

			break;
		case GRN_LED :
			 M_DIO_void_TogPinValue(LED_GRN_PORT, LED_GRN_PIN);

				break;
		case BLU_LED :
			 M_DIO_void_TogPinValue(LED_BLU_PORT,LED_BLU_PIN);

				break;
		}
}

void Animation1()
{
	H_Led_void_setON(RED_LED);
	H_Led_void_setON(BLU_LED);
	_delay_ms(500);
	H_Led_void_setOFF(RED_LED);
	H_Led_void_setOFF(BLU_LED);
	_delay_ms(500);
    H_Led_void_setON(BLU_LED);
    H_Led_void_setON(GRN_LED);
    _delay_ms(500);
    H_Led_void_setOFF(BLU_LED);
    H_Led_void_setOFF(GRN_LED);
    _delay_ms(500);
    H_Led_void_setON(RED_LED);
    H_Led_void_setON(GRN_LED);
     _delay_ms(500);
     H_Led_void_setOFF(RED_LED);
     H_Led_void_setOFF(GRN_LED);
     _delay_ms(500);

}
void Animation2()
{
	H_Led_void_setON(RED_LED);
	_delay_ms(500);
	H_Led_void_setOFF(RED_LED);
	_delay_ms(500);
    H_Led_void_setON(BLU_LED);
    _delay_ms(500);
    H_Led_void_setOFF(BLU_LED);
    _delay_ms(500);
    H_Led_void_setON(GRN_LED);
     _delay_ms(500);
    H_Led_void_setOFF(GRN_LED);
     _delay_ms(500);

}
void Animation3()
{
	H_Led_void_setON(RED_LED);
	H_Led_void_setON(BLU_LED);
	H_Led_void_setON(GRN_LED);
	_delay_ms(500);
	H_Led_void_setOFF(RED_LED);
	H_Led_void_setOFF(BLU_LED);
	H_Led_void_setOFF(GRN_LED);
	_delay_ms(500);

}






