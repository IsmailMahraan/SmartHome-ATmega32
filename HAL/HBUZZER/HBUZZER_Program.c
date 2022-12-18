/*
 * HBUZZER_Program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */
#include"HBUZZER_Interface.h"
#include"HBUZZER_Private.h"
void HBUZZERInit(){
MDIO_Set_PIN_DIR(MDIO_PORTD,HBUZZERPIN,PIN_OUTPUT);
}
void HBUZZERON(){
MDIO_Set_PIN_VALUE(MDIO_PORTD,HBUZZERPIN,PIN_HIGH);
}
void HBUZZEROFF(){
	MDIO_Set_PIN_VALUE(MDIO_PORTD,HBUZZERPIN,PIN_LOW);
}
void HBUZZERALARM(){
	HBUZZERON();
	_delay_ms(2000);
	HBUZZEROFF();

}
void HBUZZERToggle(){
MDIO_Toggle_PIN(MDIO_PORTD,HBUZZERPIN);
}
