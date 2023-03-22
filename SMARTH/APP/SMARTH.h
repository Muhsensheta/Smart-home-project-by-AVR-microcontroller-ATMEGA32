/*
 * SMARTH.h
 *
 *  Created on: ٢١‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef SMARTH_H_
#define SMARTH_H_

#include<math.h>
#include<util/delay.h>
#include "STD_TYPES.h"
#include"BIT_MATH.h"


#include"DIO_int.h"
#include"KEYPAD_int.h"
#include"LCD_int.h"
#include"GIE_int.h"
#include "ADC_int.h"


#define  True       1
#define   FALSE     0

//FOR MOTOR CONTROL
#define  STOP        1
#define HALF_SPEED   2
#define FULL_SPEED   3


void A_System_init();
void ICU_Init();
void ICU_HW(void);
u8 get_ultras_Reading();
void A_SYS_Welcom_Print();
void  A_SYS_get_entry_pass();
u8  pass_check();
void Light_CONTROL();

void Motor_init();
void motor_SControl(u8 option);


#endif /* SMARTH_H_ */
