/*
 * HServo_Motor_Program.c
 *
 *  Created on: Nov 11, 2022
 *      Author: Ismail
 */
#include"../../MCAL/MTIMER2/MTIMER2_Interface.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include "../HDCMotor/HDC_Motor_Interface.h"
#include "../HDCMotor/HDC_Motor_Private.h"


void HDCMotorInit()
{

	MDIO_Set_PIN_DIR(MDIO_PORTD,DC_MOTOR_PIN_0,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(MDIO_PORTD,DC_MOTOR_PIN_1,PIN_OUTPUT);
	MPWM2Init();

}


void HDCMotorSetDirection(u8 Local_u8_Direction)
{


	switch(Local_u8_Direction)
	{
		case CW:
			MDIO_Set_PIN_VALUE(MDIO_PORTD,DC_MOTOR_PIN_0,PIN_HIGH);
			MDIO_Set_PIN_VALUE(MDIO_PORTD,DC_MOTOR_PIN_1,PIN_LOW);
			break;
		case ACW:
			MDIO_Set_PIN_VALUE(MDIO_PORTD,DC_MOTOR_PIN_1,PIN_HIGH);
			MDIO_Set_PIN_VALUE(MDIO_PORTD,DC_MOTOR_PIN_0,PIN_LOW);
			break;
			default:
			break;
	}
}


void HDCMotorSpeed(f32 Local_f32_Speed)
{
MPWM2SetDutyCycle(Local_f32_Speed);
}


void HDCMotorStart()
{
	MPWM2Start();
}
void HDCMotorStop()
{
	MPWM2Stop();
}


