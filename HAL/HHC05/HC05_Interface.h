/*
 * HC05_Interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef HAL_HHC05_HC05_INTERFACE_H_
#define HAL_HHC05_HC05_INTERFACE_H_
#include<util/delay.h>
#include"../../LIB/STD_TYPE.h"
#include"../../MCAL/MUSART/MUSART_Interface.h"

void HHC05_Init(void);
void HHC05_SendChar(u8 Copy_u8Data);
void HHC05_SendString(u8 *Copy_u8PtrToData);
u8 HHC05_RecieveData(void);
#endif /* HAL_HHC05_HC05_INTERFACE_H_ */
