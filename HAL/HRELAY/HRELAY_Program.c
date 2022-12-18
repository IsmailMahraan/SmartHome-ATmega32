/*
 * HRELAY_Program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#include"HRELAY_Interface.h"
#include"HRELAY_Private.h"


void HRELAYInit()
{
	MDIO_Set_PIN_DIR(MDIO_PORTA,HRELAYPIN,PIN_OUTPUT);
}

void HRELAYON()
{
	MDIO_Set_PIN_VALUE(MDIO_PORTA,HRELAYPIN,PIN_HIGH);
}

void HRELAYOFF()
{
	MDIO_Set_PIN_VALUE(MDIO_PORTA,HRELAYPIN,PIN_LOW);
}


