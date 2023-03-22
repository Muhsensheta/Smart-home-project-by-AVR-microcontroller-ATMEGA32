/*
 * TIMER_proj.c
 *
 *  Created on: ٠٨‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include<avr/interrupt.h>
#include<stdlib.h>

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"TIMER_priv.h"
#include"TIMER_conig.h"
#include"TIMER_int.h"

static u32 NumberOfOverflows=0;
static u32  NumberOfRemainingTicks=0;
static void(*Arr_Call_Back[2])(void)={NULL,NULL};
void M_TIMER0_void_Init(void)//set timer mood,set OC0 pin mood
{
#if (TIMER0_MODE==TIMER0_NORMAL_MODE)
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
      #if(TIMER0_OC0_MODE>=TIMER0_OC0_MODE_DISSCONECTED&&TIMER0_OC0_MODE<=TIMER0_OC0_MODE_SET)
	    //step1: apply mask
	      TCCR0_REG&=TIMER0_OC0_MASK;
	   //insert value
	      TCCR0_REG|=TIMER0_OC0_MODE<<TIMER0_OC0_SHIFT;
     #else
         #error ("wrong insert node")
     #endif

#elif  (TIMER0_MODE==TIMER0_CTC_MODE)
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
	//step2 choose OC0 mpde
       #if(TIMER0_OC0_MODE>=TIMER0_OC0_MODE_DISSCONECTED&&TIMER0_OC0_MODE<=TIMER0_OC0_MODE_SET)
	      //step1: apply mask
	     TCCR0_REG&=TIMER0_OC0_MASK;
	      //insert value
	     TCCR0_REG|=TIMER0_OC0_MODE<<TIMER0_OC0_SHIFT;
       #else
          #error ("wrong insert node")
       #endif
 #elif  (TIMER0_MODE==TIMER0_FAST_PWM_MODE)

	SET_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
    #if(TIMER0_OC0_MODE==TIMER0_PWM_NON_INVERTED||TIMER0_OC0_MODE== TIMER0_PWM_INVERTED)
	//step1 apply mask
	TCCR0_REG&= TIMER0_OC0_MASK;
	 TCCR0_REG|=TIMER0_OC0_MODE;
    #else
        #error ("wrong insert node")
    #endif
#elif  (TIMER0_MODE==TIMER0_PHASECORRECT_MODE)
	SET_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
	//step2 choose OC0 mpde
      #if(TIMER0_OC0_MODE==TIMER0_PWM_NON_INVERTED||TIMER0_OC0_MODE== TIMER0_PWM_INVERTED)
	 //step1 apply mask
	  TCCR0_REG&= TIMER0_OC0_MASK;
	 //insert value
	   TCCR0_REG|=TIMER0_OC0_MODE;
    #else
     #error ("wrong insert node")
    #endif


#else
#error();
#endif
}
void M_TIMER0_void_start(void)//set clock prescaler
{
#if(TIMER0_PRESCALER>=TIMER0_PRESCALER_NO_CLK&&TIMER0_PRESCALER<=TIMER0_PRESCALER_EXTCLK_RAIS_EDGE)
	TCCR0_REG &=TIMER0_PRESCALER_MASK;
	TCCR0_REG |=TIMER0_PRESCALER;
#else
#error("invalid prescaler")
#endif
}
void M_TIMER0_void_stop(void)// NO CLOCK
{
	TCCR0_REG &=TIMER0_PRESCALER_MASK;
}
void M_TIMER0_void_setTime(u32 copy_u32timeMS)//time in milli seconds;
{
	u32 Loc_prescalerArr[]={1,8,64,256,1024};
	f32 Locticktime=(f32)Loc_prescalerArr[TIMER0_PRESCALER-1]/FCPU;
	u32  NoOfDesiredTicks=(copy_u32timeMS*1000)/Locticktime;
#if(TIMER0_MODE ==  TIMER0_NORMAL_MODE)
	NumberOfOverflows  =  NoOfDesiredTicks/256;
	NumberOfRemainingTicks   =NoOfDesiredTicks%256;
	if(NumberOfRemainingTicks!=0)
	{
		TCNT0_REG=256-NumberOfRemainingTicks;
		NumberOfOverflows++;
	}
#elif  (TIMER0_MODE == TIMER0_CTC_MODE)

#endif
}
void M_TIMER0_void_EnableInt(u32 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_COMP_INT_ID:
	SET_BIT(TIMSK_REG,OCIE0_BIT);
			break;
	}
	//METHOD 2
	if(copy_u8IntID >= TIMER0_OVF_INT_ID && copy_u8IntID <= TIMER0_COMP_INT_ID )
		{
			SET_BIT(TIMSK_REG,copy_u8IntID);
		}

}
void M_TIMER0_void_DisableInt(u32 copy_u8IntID)
{
	/*switch(copy_u8IntID)
		{
		case TIMER0_OVF_INT_ID:
			CLR_BIT(TIMSK_REG;TOIE0_BIT)
			break;
		case TIMER0_CMP_INT_ID:
		CLR_BIT(TIMSK_REG;OCIE0_BIT)
				break;
		}*/
	//METHOD 2

	CLR_BIT(TIMSK_REG,copy_u8IntID);
  }
void M_TIMER0_void_setCallBack(void(*ptrfn)(void),u8 copy_u8IntID)
{
	switch (copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		Arr_Call_Back[0]=ptrfn;
		break;
	case TIMER0_COMP_INT_ID:
		Arr_Call_Back[1]=ptrfn;
		break;
	}
	//method 2
	Arr_Call_Back[copy_u8IntID]=ptrfn;
}
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE ==TIMER0_FAST_PWM_MODE)
     #if(TIMER0_OC0_MODE ==TIMER0_PWM_NON_INVERTED)
	 OCR0_REG=abs(((copy_u8Duty*256)/100)-1);
     #elif(TIMER0_OC0_MODE ==TIMER0_PWM_INVERTED)
	 OCR0_REG=255-(((copy_u8Duty*256)/100)-1);
      #else
        #error("wrong insert mode")
      #endif
#endif
}
void M_TIMER0_void_setPhasecorrectPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE ==TIMER0_PHASECORRECT_MODE)
     #if(TIMER0_OC0_MODE ==TIMER0_PWM_NON_INVERTED)
	 OCR0_REG=((copy_u8Duty*255)/100);
     #elif(TIMER0_OC0_MODE ==TIMER0_PWM_INVERTED)
	 OCR0_REG=(255-(copy_u8Duty*255)/100);
      #else
        #error("wrong insert mode")
      #endif
#endif
}
ISR(TIMER0_OVF_vect)
{
	static u32 Loc_Overflow_Count=0;
		Loc_Overflow_Count++;
		if(Loc_Overflow_Count==NumberOfOverflows)
		{
			TCNT0_REG=256-NumberOfRemainingTicks;
			Loc_Overflow_Count=0;
	       if(Arr_Call_Back[TIMER0_OVF_INT_ID]!=NULL)
	         {
	            	Arr_Call_Back[TIMER0_OVF_INT_ID]();
	         }
	}
}
ISR(TIMER0_COMP_vect)
{

	if(Arr_Call_Back[TIMER0_COMP_INT_ID]!=NULL)
	{
		Arr_Call_Back[TIMER0_COMP_INT_ID]();
	}

}

