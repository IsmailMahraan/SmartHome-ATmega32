/*
 * HPushButton_Interface.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Ismail
 */

#ifndef HAL_HPUSHBUTTON_HPUSHBUTTON_INTERFACE_H_
#define HAL_HPUSHBUTTON_HPUSHBUTTON_INTERFACE_H_

#define PRESSEDBUTTON           1
#define RELEASEDBUTTON			0
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HPushButton_Config.h"
#include"../../LIB/STD_TYPE.h"


void HPushButton_Init(void);
u8 HPushButton_Read (void);

#endif /* HAL_HPUSHBUTTON_HPUSHBUTTON_INTERFACE_H_ */
