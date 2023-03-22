/*
 * TIMER1_priv.h
 *
 *  Created on: ١٤‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER1_TIMER1_PRIV_H_
#define TIMER1_TIMER1_PRIV_H_

#define TCNT1L_REG     (*((volatile u16*)0x4C))
#define TCCR1A_REG     (*((volatile u8*)0x4F))
#define TCCR1B_REG     (*((volatile u8*)0x4E))

#define ICR1_REG        (*((volatile u16*)0x46))

#define TIMSK_REG     (*((volatile u8*)0x59))


//TCCR1A_REG

#define  WGM10_BIT     0
#define WGM11_BIT      1
//TCCR1B_REG

//PRESCLAER BITS
#define CS10_BIT       0
#define CS11_BIT       1
#define CS12_BIT       2

//MOOD BITS
#define  WGM12_BIT     3
#define  WGM13_BIT     4


//ICU BITS
#define  ICES1_BIT     6
#define  ICNC1_BIT     7


//TIMSK_REG
#define TICIE1_BIT       5



#endif /* TIMER1_TIMER1_PRIV_H_ */
