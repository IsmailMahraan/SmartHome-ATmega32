/*
 * HPushButton_Program.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Ismail
 */

#include"HPushButton_Interface.h"
#include"HPushButton_Config.h"
void HPushButton_Init(void)
{
	MDIO_Set_PIN_DIR(MDIO_PORTD,PUSH_BUTTON,PIN_INPUT);
}
u8   HPushButton_Read(void)
{
	u8 *Local_u8_Reading = 0;
	 MDIO_Read_PIN(MDIO_PORTD,PUSH_BUTTON,Local_u8_Reading);
	return *Local_u8_Reading;
}
