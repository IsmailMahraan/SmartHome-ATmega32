/*
 * MSevenSegment_Interface.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Ismail
 */

#ifndef HAL_HSEVENSEGMENT_INTERFACE_H_
#define HAL_HSEVENSEGMENT_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
/*new data type define for the 7segment*/

typedef struct
{
	u8 PinEnPort;
	u8 PinEn;
	u8 PinAport;
	u8 PinA;
	u8 PinBport;
	u8 PinB;
	u8 PinCport;
	u8 PinC;
	u8 PinDport;
	u8 PinD;
}SevenSeg_t;
#define SEVEN_SEG_ON 1
#define SEVEN_SEG_OFF 0

void HSEVENSEGMENT_Init(SevenSeg_t* Ptr_SevenSegObj);
void HSEVENSEGMENT_SetMode(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegMode);
void HSEVENSEGMENT_Display(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegValue);

#endif /* HAL_HSEVENSEGMENT_INTERFACE_H_ */
