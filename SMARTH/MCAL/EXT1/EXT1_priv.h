#ifndef EXT1_EXT1_PRIV_H_
#define EXT1_EXT1_PRIV_H_

#define MCUCR_REG     (*((volatile u8 * )0x55))
#define MCUSCR_REG    (*((volatile u8 * )0x54))
#define GICR_REG      (*((volatile u8 * )0x5B))
#define GIFR_REG      (*((volatile u8 * )0x5A))

//MCUCR REG BITS
#define ISC00_BIT   0
#define ISC01_BIT   1
#define ISC10_BIT   2
#define ISC11_BIT   3

//MCUCSR REG
#define ISC2_BIT  6
//GICR_REG
#define INT2_BIT    5
#define INT0_BIT    6
#define INT1_BIT    7

#define EXTI_INT0_TRIG_MASK    0b11111100//0xFC
#define EXTI_INT1_TRIG_MASK    0b11110011//

#define EXTI_INT1_TRIG_SHIFT   2
#define EXTI_INT2_TRIG_SHIFT   6

#endif /* EXT1_EXT1_PRIV_H_ */
