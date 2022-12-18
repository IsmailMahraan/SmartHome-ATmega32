/*
 * HServoMotor_Interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Ismail
 */

#ifndef HAL_HSERVOMOTOR_HSERVOMOTOR_INTERFACE_H_
#define HAL_HSERVOMOTOR_HSERVOMOTOR_INTERFACE_H_


void HServoInit();
void HServoSetAngel(f32 Local_f32DesiredAngel);
void HServoTurnOff();

#endif /* HAL_HSERVOMOTOR_HSERVOMOTOR_INTERFACE_H_ */
