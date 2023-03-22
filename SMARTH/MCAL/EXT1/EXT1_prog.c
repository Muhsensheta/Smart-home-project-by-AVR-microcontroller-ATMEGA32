/*
 * EXT1_prog.c
 *
 *  Created on: ٠٧‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include<avr/interrupt.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"EXT1_priv.h"
#include"EXT1_config.h"
#include"EXT1_int.h"

//arra of 3 pointers to function ( call back function )
static void (*Arr_CallBack[3]) (void)={NULL,NULL,NULL};
void M_EXTI_void_Enable(u8 copy_u8IntID,u8 copy_u8Sense)
{
	//step1 :config sense
	if(copy_u8Sense>EXTI_TRIG_RAIS_EDGE &&copy_u8Sense<EXTI_TRIG_LOW_LEVEL)
	{
		return;
	}

	switch(copy_u8IntID)
		{
		case EXTI_INT0_ID:
		 //step 1: apply mask
			 MCUCR_REG&=EXTI_INT0_TRIG_MASK ;
			//step 2 : insert value
			 MCUCR_REG|= copy_u8Sense;
		   break;
		case EXTI_INT1_ID:
			//step 1: apply mask
			 MCUCR_REG&=EXTI_INT1_TRIG_MASK ;
			//step 2 : insert value
			 MCUCR_REG|= copy_u8Sense<<EXTI_INT1_TRIG_SHIFT;
			break;
		case EXTI_INT2_ID:
			//step 1: apply mask
			CLR_BIT(MCUSCR_REG,ISC2_BIT);
			//step 2 : insert value
			 MCUCR_REG|= GET_BIT(copy_u8Sense,0)<<EXTI_INT2_TRIG_SHIFT;
				break;
		}

	//step2 :enable PIE
	if (copy_u8IntID>=EXTI_INT2_ID&&copy_u8IntID<=EXTI_INT1_ID)
		SET_BIT(GICR_REG,copy_u8IntID);

}
void M_EXTI_void_Disble(u8 copy_u8IntID)
{
	//METHOD 1
	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
	   CLR_BIT(GICR_REG,INT0_BIT);
	   break;
	case EXTI_INT1_ID:
		   CLR_BIT(GICR_REG,INT1_BIT);
		   break;
	case EXTI_INT2_ID:
		   CLR_BIT(GICR_REG,INT2_BIT);
		   break;
	}
	//METHOD2
	if (copy_u8IntID>=EXTI_INT2_ID&&copy_u8IntID<=EXTI_INT1_ID)
	CLR_BIT(GICR_REG,copy_u8IntID);
}
void M_EXTI_void_setCallback(void (*ptrfn)(void),u8 copy_u8IntID)
{
	switch(copy_u8IntID)
		{
		case EXTI_INT0_ID:
			Arr_CallBack[0]=ptrfn;
		   break;
		case EXTI_INT1_ID:
			Arr_CallBack[1]=ptrfn;
			   break;
		case EXTI_INT2_ID:
			Arr_CallBack[2]=ptrfn;
			   break;
		}
}

ISR(INT0_vect)
{
	if(Arr_CallBack[0]!=NULL)
	{
		Arr_CallBack[0]();
	}
}
ISR(INT1_vect)
{
	if(Arr_CallBack[1]!=NULL)
		{
			Arr_CallBack[1]();
		}
}
ISR(INT2_vect)
{
	if(Arr_CallBack[2]!=NULL)
		{
			Arr_CallBack[2]();
		}
}
