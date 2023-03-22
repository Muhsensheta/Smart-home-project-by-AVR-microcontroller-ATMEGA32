/*
 * DIO_prg.c
 *
 *  Created on: Jan 29, 2023
 *      Author: DELL
 */
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_pvt.h"
#include "DIO_config.h"
#include "DIO_int.h"

void M_DIO_void_setPinDir(u8 Port, PIN_T Pin, Dir_T DIRECTION)
{
	switch (Port)
	{
	case PORTA_ID :
		switch (DIRECTION)
		{
		case IN:
			 CLR_BIT(DDRA,Pin);
			 break;
		case OUT:
			SET_BIT(DDRA,Pin);
			break;
		}
		break;
	case PORTB_ID :
				switch (DIRECTION)
				{
				case IN:
					 CLR_BIT(DDRB,Pin);
					 break;
				case OUT:
					SET_BIT(DDRB,Pin);
					break;
				}
			break;
	case PORTC_ID:
				switch (DIRECTION)
				{
				case IN:
						 CLR_BIT(DDRC,Pin);
						 break;
				case OUT:
						 SET_BIT(DDRC,Pin);
						 break;
					}
				break;
	case PORTD_ID :
				 switch (DIRECTION)
				 {
					case IN:
						 CLR_BIT(DDRD,Pin);
						 break;
					case OUT:
						SET_BIT(DDRD,Pin);
						 break;
				}
				break;
	}
}
void M_DIO_void_setPinValue(u8 Port, u8 Pin, VALUE_T value)
{
	switch (Port)
		{
		case PORTA_ID :
			switch (value)
			{
			case LOW:
				 CLR_BIT(PORTA_REG,Pin);
				 break;
			case HIGH:
				SET_BIT(PORTA_REG,Pin);
				break;
		   }
			break;
		case PORTB_ID :
			switch (value)
			{
			case LOW:
				 CLR_BIT(PORTB_REG,Pin);
				 break;
			case HIGH:
				 SET_BIT(PORTB_REG,Pin);
				 break;
			}
			break;
		case PORTC_ID:
			switch (value)
			{
			case LOW:
				 CLR_BIT(PORTC_REG,Pin);
				break;
			case HIGH:
				 SET_BIT(PORTC_REG,Pin);
				break;
			}
			break;
		case PORTD_ID :
			 switch (value)
			 {
				case LOW:
				   CLR_BIT(PORTD_REG,Pin);
					break;
				case HIGH:
					SET_BIT(PORTD_REG,Pin);
					break;
			 }
			 break;
		}
}
void M_DIO_void_getPinValue(u8 Port, u8 Pin, u8 *pvalue)
{
	switch (Port){
	case PORTA_ID:
		*pvalue = GET_BIT(PINA_REG,Pin);
		break;
	case PORTB_ID:
		*pvalue=GET_BIT(PINB_REG,Pin);
		break;
	case PORTC_ID:
		*pvalue=GET_BIT(PINC_REG,Pin);
		break;
	case PORTD_ID:
		*pvalue=GET_BIT(PIND_REG,Pin);
		break;
	}
}
void M_DIO_void_TogPinValue(u8 Port, u8 Pin)
{
	switch (Port){
		case PORTA_ID:
			TOG_BIT(PORTA_REG,Pin);
			break;
		case PORTB_ID:
			TOG_BIT(PORTB_REG,Pin);
			break;
		case PORTC_ID:
			TOG_BIT(PORTC_REG,Pin);
			break;
		case PORTD_ID:
			TOG_BIT(PORTD_REG,Pin);
			break;
		}


}
