/*
 * SMARTH.c
 *
 *  Created on: ٢١‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#include<math.h>
#include<util/delay.h>
#include "STD_TYPES.h"
#include"BIT_MATH.h"


#include"DIO_int.h"
#include"KEYPAD_int.h"
#include"LCD_int.h"
#include"GIE_int.h"
#include "ADC_int.h"
#include "LED_int.h"
#include "SMARTH.h"
#include"TIMER1_int.h"
#include"TIMER_int.h"


static u16 Reading1=0;
static u16 Reading2=0;
static u8 stateCounter=0;
u16 NumberOfTicks=0;
f32 time =0;
u32 Distance =0;


u8 Password[]={'1','2','3','4','5'};
static u8 Entry_Pass[5];
void A_System_init()
{
	H_KEYPAD_void_init();
	H_LCD_void_Init();
	H_Led_void_ledInit(GRN_LED);
	H_Led_void_ledInit(RED_LED);
	H_Led_void_ledInit(BLU_LED);
    M_DIO_void_setPinDir(PORTC_ID,PIN4,OUT);//to set relay
}
void ICU_Init()
{
	    //SET DIR FOR PWM PIN TO BE OUT
		M_DIO_void_setPinDir(PORTB_ID,PIN3, OUT);
		//SET DIR FOR ICU PIN TO BE IN
		M_DIO_void_setPinDir(PORTD_ID,PIN6, IN);
		//SET DIR FOR trigger PIN TO BE out
		M_DIO_void_setPinDir(PORTC_ID,PIN5, OUT);
		//ICU INIT
		M_TIMER1_ICU_void_Init();

		// ENABLE INTERRUPT
		M_TIMER1_ICU_void_INTEnable();
		M_TIMER1_ICU_void_setCallback(ICU_HW);
		// GIE ENABLE
		M_GIE_void_enable();
	    //TIMER 1 INITIALIZAION
		M_TIMER1_void_Init();
}
void ICU_HW(void)
{
	if (stateCounter==0)
	{
		//take reading 1
		Reading1=M_TIMER1_ICU_u16_takeReading();
		//change trigger to fallin edge
		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_FALL_TRIGG);
	}
	else if (stateCounter==1)
	{
		//take reading 2
		Reading2=M_TIMER1_ICU_u16_takeReading();

		M_TIMER1_ICU_void_setTrigg(TIMER1_ICU_RISING_TRIGG);
	}

	stateCounter++;
}
u8  get_ultras_Reading()
{
	 //send trigger
		 M_DIO_void_setPinValue(PORTC_ID,PIN5, HIGH);
		 _delay_ms(10);
		 M_DIO_void_setPinValue(PORTC_ID,PIN5, LOW);

		 while (stateCounter<=1);//busy waitind untill all reading are ready
		 stateCounter=0;
		 NumberOfTicks=Reading2-Reading1;
		 time =(NumberOfTicks*16)/1000000.0;
		 Distance =ceil((time/2)*34300);

return  Distance;
}


void A_SYS_Welcom_Print()
{
	    H_LCD_void_sendString("HELLO MR ");
		_delay_ms(500);
		H_LCD_void_clear();
		H_LCD_void_sendString("Enter password");
		_delay_ms(500);
		H_LCD_void_gotXY(1,0);
}
void  A_SYS_get_entry_pass()
{

	u8 i = 0;
	u8 KP_Pressed =NUM_PRESSED_KEY ;

	while(i<5)
		{
			KP_Pressed=H_KEYPAD_void_getPressedKey();


			if(KP_Pressed !=NUM_PRESSED_KEY)// to ensure that user already pressed any key
			{
				//get password from user
				Entry_Pass[i]=KP_Pressed;
				//send this pattern on lcd to hide my pass
				H_LCD_void_sendData('*');
				i++;
			}

		}
      H_LCD_void_clear();
}
u8  pass_check()
{
	u8 Try_Num=0;
	u8 check = True ;
	u8 i;
	do
	{
		 A_SYS_get_entry_pass();
		 check = True;
	  for(i=0;i<5;i++)
	  {
       //compare entry data with the password
		if(Entry_Pass[i]!=Password[i])
		{

			H_LCD_void_sendString("Wrong");
			H_LCD_void_gotXY(1,0);
			H_LCD_void_sendString("re entre pass");
			_delay_ms(300);
			H_LCD_void_clear();
			check=FALSE;
			// A_SYS_get_entry_pass();
			Try_Num++;
			H_LCD_void_clear();
			break;

		}
	}
	}while(Try_Num<3  && check == FALSE);

	return check;
}

void Light_CONTROL()
{

		u8 KP_Pressed =NUM_PRESSED_KEY ;
		KP_Pressed=H_KEYPAD_void_getPressedKey();

        //control lights with keypad as button
					if(KP_Pressed !=NUM_PRESSED_KEY)
					{
						switch (KP_Pressed)
						{
						case '1':
							H_Led_void_setON(BLU_LED);
							H_Led_void_setON(GRN_LED);
							H_LCD_void_sendString("^LIGHT ON ^");
							break;
						case '2':
							H_LCD_void_clear();
							H_Led_void_setOFF(BLU_LED);
							H_Led_void_setOFF(GRN_LED);
							H_LCD_void_sendString("^LIGHT OFF ^");
							_delay_ms(300);
							H_LCD_void_clear();

							break;


						}

					}


}
void Motor_init()
{
	// set 2 output  pin to be input for the motor
	M_DIO_void_setPinDir(PORTD_ID,PIN0,OUT);
	M_DIO_void_setPinDir(PORTD_ID,PIN1,OUT);
	//init timer0 to get pwm from oco pin
	M_TIMER0_void_Init();
	M_TIMER0_void_start();
	// set oco pin as output to enable motor
	M_DIO_void_setPinDir(PORTB_ID,PIN3,OUT);

}
void motor_SControl(u8 option)
{
	switch (option){
	case STOP :
		M_TIMER0_void_setFastPWM(0);
		M_DIO_void_setPinValue(PORTD_ID,PIN0,LOW);
		M_DIO_void_setPinValue(PORTD_ID,PIN1,LOW);

		break;
	case HALF_SPEED:
		// set pwm 50% to get half speed
		M_TIMER0_void_setFastPWM(50);
		M_DIO_void_setPinValue(PORTD_ID,PIN0,LOW);
		M_DIO_void_setPinValue(PORTD_ID,PIN1,HIGH);


		break;
	case FULL_SPEED :
		// set pwm 100% to get full speed
		M_TIMER0_void_setFastPWM(100);
		M_DIO_void_setPinValue(PORTD_ID,PIN0,LOW);
		M_DIO_void_setPinValue(PORTD_ID,PIN1,HIGH);

		break;
	}

}

