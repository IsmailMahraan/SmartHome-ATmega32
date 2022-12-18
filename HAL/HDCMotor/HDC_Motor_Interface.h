/*
 * HServo_Motor_Interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Ismail
 */

#ifndef HAL_HDCMOTOR_HDC_MOTOR_INTERFACE_H_
#define HAL_HDCMOTOR_HDC_MOTOR_INTERFACE_H_
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPE.h"
#include "../HDCMotor/HDC_Motor_Private.h"

void HDCMotorInit();
void HDCMotorSetDirection(u8 Local_u8_Direction);
void HDCMotorSpeed(f32 Local_u8_Speed);
void HDCMotorStart();
void HDCMotorStop();

#endif /* HAL_HDCMOTOR_HDC_MOTOR_INTERFACE_H_ */
