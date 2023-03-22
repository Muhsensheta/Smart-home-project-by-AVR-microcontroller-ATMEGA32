/*
 * KEYPAD_prog.c
 *
 *  Created on: ٠٢‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_int.h"

#include"KEYPAD_priv.h"
#include"KEYPAD_config.h"
#include"KEYPAD_int.h"

void H_KEYPAD_void_init()
{
  //set all rows  direction as output
	M_DIO_void_setPinDir(KEYPAD_R0_PORT, KEYPAD_R0_PIN, OUT);
	M_DIO_void_setPinDir(KEYPAD_R1_PORT, KEYPAD_R1_PIN, OUT);
	M_DIO_void_setPinDir(KEYPAD_R2_PORT, KEYPAD_R2_PIN, OUT);
	M_DIO_void_setPinDir(KEYPAD_R3_PORT, KEYPAD_R3_PIN, OUT);

	//set all collums direction as input
	M_DIO_void_setPinDir(KEYPAD_C0_PORT,KEYPAD_C0_PIN, IN);
	M_DIO_void_setPinDir(KEYPAD_C1_PORT, KEYPAD_C1_PIN, IN);
	M_DIO_void_setPinDir(KEYPAD_C2_PORT, KEYPAD_C2_PIN, IN);
	M_DIO_void_setPinDir(KEYPAD_C3_PORT, KEYPAD_C3_PIN, IN);

	M_DIO_void_setPinValue(KEYPAD_C0_PORT,KEYPAD_C0_PIN,HIGH);
		M_DIO_void_setPinValue(KEYPAD_C1_PORT,KEYPAD_C1_PIN,HIGH);
		M_DIO_void_setPinValue(KEYPAD_C2_PORT,KEYPAD_C2_PIN,HIGH);
		M_DIO_void_setPinValue(KEYPAD_C3_PORT,KEYPAD_C3_PIN,HIGH);

	//deactivate rows (high)
	M_DIO_void_setPinValue(KEYPAD_R0_PORT,KEYPAD_R0_PIN,HIGH);
	M_DIO_void_setPinValue(KEYPAD_R1_PORT,KEYPAD_R1_PIN,HIGH);
	M_DIO_void_setPinValue(KEYPAD_R2_PORT,KEYPAD_R2_PIN,HIGH);
	M_DIO_void_setPinValue(KEYPAD_R3_PORT,KEYPAD_R3_PIN,HIGH);

  }
u8 H_KEYPAD_void_getPressedKey()
{
	u8 loc_state= NUM_PRESSED_KEY ;
	u8 loc_row_indx;
	u8 loc_col_indx;
	u8 loc_keypad_arr [4][4]=KEYPAD_ARR_MAP;
	u8 read;
	 for(loc_row_indx=KEYPAD_R0_PIN;loc_row_indx<=KEYPAD_R3_PIN;loc_row_indx++)
	{
		 M_DIO_void_setPinValue(KEYPAD_ROW_PORTS,loc_row_indx,LOW);
		   for (loc_col_indx=KEYPAD_C0_PIN;loc_col_indx<=KEYPAD_C3_PIN;loc_col_indx ++)
		   {
			   M_DIO_void_getPinValue(KEYPAD_COLS_PORTS, loc_col_indx, &read);
			   if(read==ACTIVE_LOW_PRESSED)
			   {
				   //debouncing delay
				   _delay_ms(100);
			 M_DIO_void_getPinValue(KEYPAD_COLS_PORTS, loc_col_indx, &read);
			 if(read==ACTIVE_LOW_PRESSED)
			 {


				 while(read==ACTIVE_LOW_PRESSED)
					 {
						 M_DIO_void_getPinValue(KEYPAD_COLS_PORTS, loc_col_indx, &read);
					 }
					 read= loc_keypad_arr[loc_row_indx - KEYPAD_R0_PIN ][ loc_col_indx -  KEYPAD_C0_PIN ];
					 	return read;

			 }

		 }
	  }//deactivate rows
		   M_DIO_void_setPinValue(KEYPAD_ROW_PORTS,loc_row_indx,HIGH);


	}
	 return  loc_state;
}



