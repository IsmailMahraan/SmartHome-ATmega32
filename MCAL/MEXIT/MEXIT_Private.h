/*
 * MEXIT_Private.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MEXIT_MEXIT_PRIVATE_H_
#define MCAL_MEXIT_MEXIT_PRIVATE_H_
#include "../../LIB/STD_TYPE.h"

#define MEXIT_LOW_LEVEL          0
#define MEXIT_ANY_LOGICAL_CHANGE 1
#define MEXIT_RISING_EDGE        2
#define MEXIT_FALLING_EDGE       3


#define MCUCR *((volatile u8*)(0x55))
#define MCUCSR *((volatile u8*)(0x54))
#define GICR *((volatile u8*)(0x5B))
#define GIFR *((volatile u8*)(0x5A))
#endif /* MCAL_MEXIT_MEXIT_PRIVATE_H_ */
