/*
 * HServoMotor_Program.c
 *
 *  Created on: Nov 11, 2022
 *      Author: Ismail
 */


#include"HServoMotor_Private.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../MCAL/MTIMER1/MTIMER1_Interface.h"

void HServoInit()
{
	MDIO_Set_PIN_DIR(MDIO_PORTD,SERVO_OUTPUT_PIN, PIN_OUTPUT);
	MPWM1Init();
	MPWM1SetFrequency(50); // 50HZ FREQUENCY FOR OPERATION
}

void HServoSetAngel	(f32 Localf32DesiredAngel)
{
	//scaling from 180 degrees to 5 to 10 Percents

	Localf32DesiredAngel *= 5;
 	Localf32DesiredAngel /= 180;
	Localf32DesiredAngel += 5;

MPWM1SetDutyCycle(Localf32DesiredAngel);
MPWM1Start();
}

void HServoTurnOff()
{
MPWM1Stop();
}
