/*
 * HLM35_Interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef HAL_HLM35_HLM35_INTERFACE_H_
#define HAL_HLM35_HLM35_INTERFACE_H_

#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "../../MCAL/MADC/MADC_Interface.h"
void HLM35Init();
void  HLM35Read(u16* PtrTou16_Data);

#endif /* HAL_HLM35_HLM35_INTERFACE_H_ */
