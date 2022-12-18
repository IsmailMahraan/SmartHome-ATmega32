/*
 * HBUZZER_Interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef HAL_HBUZZER_HBUZZER_INTERFACE_H_
#define HAL_HBUZZER_HBUZZER_INTERFACE_H_

#include "../../MCAL/MDIO/MDIO_Interface.h"
#include <util/delay.h>

void HBUZZERInit();
void HBUZZERON();
void HBUZZEROFF();
void HBUZZERALARM();
void HBUZZERToggle();

#endif /* HAL_HBUZZER_HBUZZER_INTERFACE_H_ */
