/*
 * DIO_int.h
 *
 *  Created on: Jan 29, 2023
 *      Author: DELL
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_


#define	PORTA_ID  1
#define	PORTB_ID  2
#define	PORTC_ID  3
#define	PORTD_ID  4

typedef enum{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7
}PIN_T;



typedef enum{
	IN,OUT
}Dir_T;


typedef enum{
	LOW,HIGH
}VALUE_T;


/****************  Function Prototypes  ****************/
void M_DIO_void_setPinDir(u8 Port, PIN_T Pin, Dir_T Dir);
void M_DIO_void_setPinValue(u8 Port, PIN_T Pin, VALUE_T value);
void M_DIO_void_getPinValue(u8 Port, PIN_T Pin, u8 *pvalue);
void M_DIO_void_TogPinValue(u8 Port, PIN_T Pin);
void M_DIO_void_setPortValue(u8 Port, VALUE_T value);
//void M_DIO_void_getPinValue(u8 Port,  u8 *pvalue);



#endif /* MCAL_DIO_DIO_INT_H_ */
