/*
 * HEEPROM_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Ismail
 */

#ifndef HAL_HEEPROM_HEEPROM_INTERFACE_H_
#define HAL_HEEPROM_HEEPROM_INTERFACE_H_
#include "HEEPROM_Private.h"
u8 HEEPROM_ReadByte(u8 Copy_u8BlockNo,u8 Copy_u8ByteAddress);
void HEEPROM_WriteByte(u8 Copy_u8Data,u8 Copy_u8BlockNo,u8 Copy_u8ByteAddress);

#endif /* HAL_HEEPROM_HEEPROM_INTERFACE_H_ */
