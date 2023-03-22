/*
 * TIMER_int.h
 *
 *  Created on: ٠٨‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef TIMER_TIMER_INT_H_
#define TIMER_TIMER_INT_H_


#define TIMER0_OVF_INT_ID  0
#define TIMER0_COMP_INT_ID  1

void M_TIMER0_void_Init(void);//set timer mood,set OC0 pin mood
void M_TIMER0_void_start(void);//set clock prescaler
void M_TIMER0_void_stop(void);// NO CLOCK
void M_TIMER0_void_setTime(u32 copy_u32timeMS);//time in milli seconds;
void M_TIMER0_void_EnableInt(u32 copy_u8IntID);
void M_TIMER0_void_DisableInt(u32 copy_u8IntID);
void M_TIMER0_void_setCallBack(void(*ptrfn)(void),u8 copy_u8IntID);
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty);
void M_TIMER0_void_setPhasecorrectPWM(u8 copy_u8Duty);
#endif /* TIMER_TIMER_INT_H_ */
