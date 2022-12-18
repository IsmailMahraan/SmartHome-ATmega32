/*
 * Dimmer_Interface.h
 *
 *  Created on: Dec 18, 2022
 *      Author: Ismail
 */

#ifndef HAL_HDIMMER_DIMMER_INTERFACE_H_
#define HAL_HDIMMER_DIMMER_INTERFACE_H_


#include "../../MCAL/MTIMER1/MTIMER1_Interface.h"
#include <util/delay.h>

/**************************************************_MACROS_*********************************************/
#define NORMAL          0
#define F_PWM      50
#define MED        10
#define LOW        20
#define  Control        3
/************************************************_PROTOTYPES_********************************************/
void HDimmerLightInit(void);
void HDimmerLightSetLightIntense(u16);
void HDimmerLightStart(void);
void HDimmerLightStop(void);
#endif /* HAL_HDIMMER_DIMMER_INTERFACE_H_ */
