/*
 * MDIO_Program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Ismail
 */

#include "MDIO_Interface.h"
#include "MDIO_Private.h"

void MDIO_Set_PORT_DIR(u8 Copy_u8PortNumber,u8 Copy_u8PortDirection){

if((Copy_u8PortDirection ==PORT_OUTPUT)|| (Copy_u8PortDirection ==PORT_INPUT)){

	/*valid port direction*/
	switch(Copy_u8PortNumber)
	{
	case MDIO_PORTA:
		DDRA = Copy_u8PortDirection;
		break;
	case MDIO_PORTB:
			DDRB = Copy_u8PortDirection;
			break;
	case MDIO_PORTC:
			DDRC = Copy_u8PortDirection;
			break;
	case MDIO_PORTD:
			DDRD = Copy_u8PortDirection;
			break;
default:
	/*wrong port number passed */
	break;
	}

}
else{
	/*invalid port direction*/
}
}
void MDIO_Set_PIN_DIR(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection){


	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8)){

		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			if(Copy_u8PinDirection==PIN_OUTPUT){
				SET_BIT(DDRA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT){
				CLR_BIT(DDRA,Copy_u8PinNumber);
			}
			else{
				/*invalid port direction*/
			}
			break;

		case MDIO_PORTB:
					if(Copy_u8PinDirection==PIN_OUTPUT){
						SET_BIT(DDRB,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==PIN_INPUT){
						CLR_BIT(DDRB,Copy_u8PinNumber);
					}
					else{
						/*invalid port direction*/
					}
					break;

		case MDIO_PORTC:
					if(Copy_u8PinDirection==PIN_OUTPUT){
						SET_BIT(DDRC,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==PIN_INPUT){
						CLR_BIT(DDRC,Copy_u8PinNumber);
					}
					else{
						/*invalid port direction*/
					}
					break;


		case MDIO_PORTD:
					if(Copy_u8PinDirection==PIN_OUTPUT){
						SET_BIT(DDRD,Copy_u8PinNumber);
					}
					else if(Copy_u8PinDirection==PIN_INPUT){
						CLR_BIT(DDRD,Copy_u8PinNumber);
					}
					else{
						/*invalid port direction*/
					}
					break;


		default:
			/*wrong port number passed */
			break;
		}






	}

	else{
		/*wrong pin number*/

	}


}
void MDIO_Set_PORT_VALUE(u8 Copy_u8PortNumber,u8 Copy_u8PortNumberValue){

/*Ø¨ØªØ®Ù„ÙŠ Ø§Ù„Ø¨ÙˆØ±Øª Ø¨Ø§Ù„Ù�Ø§Ù„ÙŠÙˆ Ø§Ù„Ù„ÙŠ Ø§Ù† Ø¹Ø§ÙˆØ²Ù‡Ø§ Ù…Ø´ Ø¯Ø§ÙŠÙ…Ø§ 11111111Ø§Ùˆ 00000000 Ø¨Ø³ */
	if((Copy_u8PortNumberValue)>=0 && (Copy_u8PortNumberValue)<255){

		/*valid port Value*/
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			PORTA = Copy_u8PortNumberValue;
			break;
		case MDIO_PORTB:
				PORTB = Copy_u8PortNumberValue;
				break;
		case MDIO_PORTC:
				PORTC = Copy_u8PortNumberValue;
				break;
		case MDIO_PORTD:
				PORTD = Copy_u8PortNumberValue;
				break;
	default:
		/*wrong port number passed */
		break;
		}

	}
	else{
		/*invalid port value*/
	}


	}
void MDIO_Set_PIN_VALUE(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber ,u8 Copy_u8PinValue){


	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8)){

		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			if(Copy_u8PinValue==PIN_HIGH){
				SET_BIT(PORTA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==PIN_LOW){
				CLR_BIT(PORTA,Copy_u8PinNumber);
			}
			else{
				/*invalid port direction*/
			}
			break;

		case MDIO_PORTB:
					if(Copy_u8PinValue==PIN_HIGH){
						SET_BIT(PORTB,Copy_u8PinNumber);
					}
					else if(Copy_u8PinValue==PIN_LOW){
						CLR_BIT(PORTB,Copy_u8PinNumber);
					}
					else{
						/*invalid port direction*/
					}
					break;

		case MDIO_PORTC:
					if(Copy_u8PinValue==PIN_HIGH){
						SET_BIT(PORTC,Copy_u8PinNumber);
					}
					else if(Copy_u8PinValue==PIN_LOW){
						CLR_BIT(PORTC,Copy_u8PinNumber);
					}
					else{
						/*invalid port direction*/
					}
					break;


		case MDIO_PORTD:
					if(Copy_u8PinValue==PIN_HIGH){
						SET_BIT(PORTD,Copy_u8PinNumber);
					}
					else if(Copy_u8PinValue==PIN_LOW){
						CLR_BIT(PORTD,Copy_u8PinNumber);
					}
					else{
						/*invalid port direction*/
					}
					break;


		default:
			/*wrong port number passed */
			break;
		}
	}

	else{
		/*wrong pin number*/

	}



}
void MDIO_Read_PORT(u8 Copy_u8PortNumber,u8 * P_u8PortReading){
if(P_u8PortReading !=NULL){
	switch(Copy_u8PortNumber){
	case MDIO_PORTA:
	*P_u8PortReading = PINA;
	break;
	case MDIO_PORTB:
	*P_u8PortReading = PINB;
	break;
	case MDIO_PORTC:
	*P_u8PortReading = PINC;
	break;
	case MDIO_PORTD:
	*P_u8PortReading = PIND;
	break;
	default:
		break;
		/*WRONG PORT CHOSEN*/
	}

}
else{
	/* NULL POINTER*/
}
}
void MDIO_Read_PIN(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 * P_u8PortReading){

	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8)){

			switch(Copy_u8PortNumber)
			{
			case MDIO_PORTA:
				*P_u8PortReading =GET_BIT(PINA,Copy_u8PinNumber);
				break;

			case MDIO_PORTB:
				*P_u8PortReading =GET_BIT(PINB,Copy_u8PinNumber);
						break;

			case MDIO_PORTC:
				*P_u8PortReading =GET_BIT(PINC,Copy_u8PinNumber);
						break;


			case MDIO_PORTD:
				*P_u8PortReading =GET_BIT(PIND,Copy_u8PinNumber);
						break;


			default:
				/*wrong port number passed */
				break;
			}


		}
	else{

		/*wrong pin number*/
	}



}
void MDIO_Toggle_PIN(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){

	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8)){

				switch(Copy_u8PortNumber)
				{
				case MDIO_PORTA:
					TOGGLE_BIT(PORTA,Copy_u8PinNumber);
					break;

				case MDIO_PORTB:
					TOGGLE_BIT(PORTB,Copy_u8PinNumber);
							break;

				case MDIO_PORTC:
					TOGGLE_BIT(PORTC,Copy_u8PinNumber);
							break;


				case MDIO_PORTD:
					TOGGLE_BIT(PORTD,Copy_u8PinNumber);
							break;


				default:
					/*wrong port number passed */
					break;
				}


			}
		else{

			/*wrong pin number*/
		}







}
void MDIO_SetNibbleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value){
	 u8 Loc_u8Value =Copy_u8Value;
	 Loc_u8Value=((Loc_u8Value&(0x0F))<<Copy_u8PinStart);
	if((Copy_u8PinStart<=4)&&(Copy_u8PinStart>=0)){
	switch (Copy_u8PortNumber){
	case MDIO_PORTA :
		//mask port A
		PORTA&=(~((0x0F)<<Copy_u8PinStart));
		PORTA|=Loc_u8Value;
		break;
		case MDIO_PORTB:
			PORTB&=(~(0X0F<<Copy_u8PinStart));
			PORTB|=Loc_u8Value;
		break;
		case MDIO_PORTC:
			PORTC&=(~(0X0F<<Copy_u8PinStart));
			PORTC|=Loc_u8Value;
		break;
		case MDIO_PORTD:
			PORTD&=(~(0X0F<<Copy_u8PinStart));
			PORTD|=Loc_u8Value;
		break;
		default:{

		break;	/*WRONG PORT PASSED*/
		}


	}
	}
	else{
		/*wrong PINStartNumber*/
	}

}

u8 MDIO_Return_PINValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	u8  P_u8PortReading =0;
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8)){

			switch(Copy_u8PortNumber)
			{
			case MDIO_PORTA:
				P_u8PortReading =GET_BIT(PINA,Copy_u8PinNumber);
				return P_u8PortReading;
				break;

			case MDIO_PORTB:
				P_u8PortReading =GET_BIT(PINB,Copy_u8PinNumber);
				return P_u8PortReading;
						break;

			case MDIO_PORTC:
				P_u8PortReading =GET_BIT(PINC,Copy_u8PinNumber);
				return P_u8PortReading;
						break;


			case MDIO_PORTD:
				P_u8PortReading =GET_BIT(PIND,Copy_u8PinNumber);
				return P_u8PortReading;
						break;


			default:
				/*wrong port number passed */
				return P_u8PortReading;
				break;
			}


		}
	else{
		return P_u8PortReading;
		/*wrong pin number*/
	}



}


