/*
 * EXT1_int.h
 *
 *  Created on: ٠٧‏/٠٢‏/٢٠٢٣
 *      Author: houras
 */

#ifndef EXT1_EXT1_INT_H_
#define EXT1_EXT1_INT_H_

#define EXTI_INT0_ID  6
#define EXTI_INT1_ID  7
#define EXTI_INT2_ID  5

#define EXTI_TRIG_LOW_LEVEL    0
#define EXTI_TRIG_ANY_CHANGE   1
#define EXTI_TRIG_FALL__EDGE   2
#define EXTI_TRIG_RAIS_EDGE    3


void M_EXTI_void_Enable(u8 copy_u8IntID,u8 copy_u8Sense);
void M_EXTI_void_Disble(u8 copy_u8IntID);
void M_EXTI_void_setCallback(void (*ptrfn)(void),u8 copy_u8IntID);


#endif /* EXT1_EXT1_INT_H_ */
