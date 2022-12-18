/*
 * HLED_Program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#include"HLED_Interface.h"
//MDIO PORTC FOR LED 0&1  PIN2 PIN3//
//MDIO PORTD FOR LED 2  PIN4 //
void HLED_Init(u8 Local_u8LedNumber){
		switch(Local_u8LedNumber)
		{
		case LED0:
			MDIO_Set_PIN_DIR(MDIO_PORTC,PIN2,PIN_OUTPUT);
			break;
		case LED1:
			MDIO_Set_PIN_DIR(MDIO_PORTC,PIN3,PIN_OUTPUT);
				break;
		case LED2:
			MDIO_Set_PIN_DIR(MDIO_PORTD,PIN4,PIN_OUTPUT);
				break;
	default:
		/*wrong LED number passed */
		break;

}
}
void HLED_ON(u8 Local_u8LedNumber){
	switch(Local_u8LedNumber)
	{
	case LED0:
		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN2,PIN_HIGH);
		break;
	case LED1:
		MDIO_Set_PIN_DIR(MDIO_PORTC,PIN3,PIN_HIGH);
			break;
	case LED2:
		MDIO_Set_PIN_DIR(MDIO_PORTD,PIN4,PIN_HIGH);
			break;
default:
	/*wrong LED number passed */
	break;
}
}
void HLED_OFF(u8 Local_u8LedNumber){
	switch(Local_u8LedNumber)
	{
	case LED0:
		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN2,PIN_LOW);
		break;
	case LED1:
		MDIO_Set_PIN_DIR(MDIO_PORTC,PIN3,PIN_LOW);
			break;
	case LED2:
		MDIO_Set_PIN_DIR(MDIO_PORTD,PIN4,PIN_LOW);
			break;
default:
	/*wrong LED number passed */
	break;
}
}
void HLED_Blink(u8 Local_u8LedNumber){
	switch(Local_u8LedNumber)
	{
	case LED0:
		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN2,PIN_HIGH);
		_delay_ms(500);
		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN2,PIN_LOW);
		break;
	case LED1:
		MDIO_Set_PIN_DIR(MDIO_PORTC,PIN3,PIN_HIGH);
		_delay_ms(500);
		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_LOW);
			break;
	case LED2:
		MDIO_Set_PIN_DIR(MDIO_PORTD,PIN4,PIN_HIGH);
		_delay_ms(500);
		MDIO_Set_PIN_VALUE(MDIO_PORTD,PIN4,PIN_LOW);
			break;
default:
	/*wrong LED number passed */
	break;
}
}
