/*
 * LED_init.h
 *
 *  Created on: ٣١‏/٠١‏/٢٠٢٣
 *      Author: houras
 */
#include<util/delay.h>
#ifndef LED_INT_H_
#define LED_INT_H_

#define RED_LED 0
#define GRN_LED 1
#define BLU_LED 2

void  H_Led_void_ledInit(u8 LedID);
void  H_Led_void_setON(u8 LedID);
void  H_Led_void_setOFF(u8 LedID);
void  H_Led_void_toggle(u8 LedID);
void Animation1();
void Animation2();
void Animation3();

#endif /* LED_INT_H_ */
