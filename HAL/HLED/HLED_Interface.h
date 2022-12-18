/*
 * HLED_Interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef HAL_HLED_HLED_INTERFACE_H_
#define HAL_HLED_HLED_INTERFACE_H_

#include "HLED_Private.h"
#include <util/delay.h>
#include "../../MCAL/MDIO/MDIO_Interface.h"

void HLED_Init(u8 Local_u8_Led_Number);
void HLED_ON(u8 Local_u8_Led_Number);
void HLED_OFF(u8 Local_u8_Led_Number);
void HLED_Blink(u8 Local_u8_Led_Number);


#endif /* HAL_HLED_HLED_INTERFACE_H_ */
