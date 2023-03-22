/*
 * GIE_prog.c
 *
 *  Created on: ٠٧‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GIE_priv.h"
#include"GIE_config.h"
#include"GIE_int.h"

void M_GIE_void_enable(void)
{
SET_BIT(SREG_REG,I_BIT);
asm("SEI");

}
void M_GIE_void_disable(void)
{
	//CLR_BIT(SREG_REG ,I_BIt);
	asm("CLI");
}
