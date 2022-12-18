/*
 * Dimmer_Program.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Ismail
 */


#include "Dimmer_Interface.h"

void HDimmerLightInit(void)
{
 MPWM1Init();
MPWM1SetDutyCycle(F_PWM);
}



void HDimmerLightSetLightIntense(u16 Local_u8_Intensity)
{
	HDimmerLightStart();

	MPWM1SetDutyCycle(Local_u8_Intensity);
	if(Local_u8_Intensity==0){
		HDimmerLightStop();
	}
}
void HDimmerLightStart(void)
{
	MPWM1Start();
}
void HDimmerLightStop(void)
{
	MPWM1Stop();
}
