/*
 * DIO_pvt.h
 *
 *  Created on: Jan 29, 2023
 *      Author: DELL
 */

#ifndef MCAL_DIO_DIO_PVT_H_
#define MCAL_DIO_DIO_PVT_H_

/*************  Port A Register  *************/
#define	PORTA_REG		*((volatile u8 *)0x3B)
#define	DDRA		*((volatile u8 *)0x3A)
#define	PINA_REG		*((volatile u8 *)0x39)

/*************  Port B Register  *************/
#define	PORTB_REG		*((volatile u8 *)0x38)
#define	DDRB		*((volatile u8 *)0x37)
#define	PINB_REG		*((volatile u8 *)0x36)

/*************  Port C Register  *************/
#define	PORTC_REG		*((volatile u8 *)0x35)
#define	DDRC		*((volatile u8 *)0x34)
#define	PINC_REG		*((volatile u8 *)0x33)

/*************  Port D Register  *************/
#define	PORTD_REG		*((volatile u8 *)0x32)
#define	DDRD		*((volatile u8 *)0x31)
#define	PIND_REG		*((volatile u8 *)0x30)

#endif /* MCAL_DIO_DIO_PVT_H_ */
