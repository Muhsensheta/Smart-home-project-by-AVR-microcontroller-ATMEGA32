/*
 * TIMER1_int.h
 *
 *  Created on: ١٤‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_


#define TIMER1_ICU_FALL_TRIGG   0
#define TIMER1_ICU_RISING_TRIGG   1

void M_TIMER1_void_Init();//mode normal  ,prescaler
void M_TIMER1_ICU_void_Init();//setup initial trigger for ICU
void M_TIMER1_ICU_void_INTEnable(void);
void M_TIMER1_ICU_void_INTDisable(void);
void M_TIMER1_ICU_void_setTrigg(u8 copy_u8Trigg);
u16 M_TIMER1_ICU_u16_takeReading(void);
void M_TIMER1_ICU_void_setCallback(void(*ptrfn)(void));

#endif /* TIMER1_TIMER1_INT_H_ */
