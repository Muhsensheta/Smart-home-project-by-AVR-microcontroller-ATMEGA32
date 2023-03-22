/*
 * main.c
 *
 *  Created on: ٢١‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#define F_CPU 16000000UL

#include<math.h>
#include<util/delay.h>
#include "STD_TYPES.h"
#include"BIT_MATH.h"


#include"DIO_int.h"
#include"KEYPAD_int.h"
#include"LCD_int.h"
#include "LED_int.h"
#include"GIE_int.h"
#include "ADC_int.h"
#include"SMARTH.h"


int main()
{
	u8 check=FALSE;
	u8 Temp,Distance;


	A_System_init();
	H_TEMPSENSOR_void_Init();
	ICU_Init();
	Motor_init();

	// this loop to wait  for the user get in distance range (front of door,15cm);
	/*while(get_ultras_Reading()>15)
     {
    	 H_LCD_void_gotXY(0, 0);
    	 H_LCD_void_sendString("SMART HOME");
     }*/

	H_LCD_void_clear();
	A_SYS_Welcom_Print();

	check = pass_check();
	// this loop to return to main menue  after 3 false tries ;
	while(!check)
	{
		H_LCD_void_clear();


		if (check==FALSE)
		{
			H_LCD_void_sendString("SYSTEM hold");
			H_Led_void_setON(RED_LED);
			_delay_ms(5000);
			H_LCD_void_clear();
			H_Led_void_setOFF(RED_LED);
			H_LCD_void_sendString("RE ENTRE PASS");
			_delay_ms(1000);
			H_LCD_void_clear();
		}

		check = pass_check();

	}
	H_LCD_void_sendString("WELCOME DEAR !");
	_delay_ms(1000);
	H_LCD_void_clear();
	// set relay to open the  door if user enter the right pass
	M_DIO_void_setPinValue(PORTC_ID,PIN4, HIGH);


	while(1)
	{

		H_LCD_void_gotXY(0, 0);
		Light_CONTROL();
		Temp= H_TEMPSENSOR_u8_readTemp();

		H_LCD_void_gotXY(1, 2);
		H_LCD_void_sendString("TEMP :");
		H_LCD_void_sendIntNum(Temp);
		_delay_ms(500);
		H_LCD_void_clear();

		if(Temp<=25)
		{
			motor_SControl(STOP);
		}
		else if(Temp>25 && Temp<35)

		{
			motor_SControl(HALF_SPEED);
		}
		else if (Temp>=35)
		{
			motor_SControl(FULL_SPEED);
		}

	}

	return 0 ;
}




