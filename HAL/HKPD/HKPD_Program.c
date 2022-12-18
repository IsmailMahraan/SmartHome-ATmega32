/*
 * HKPD_Program.c
 *
 *  Created on: Oct 14, 2022
 *      Author: medo
 */


#include"HKPD_Interface.h"
#include"HKPD_Private.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include <util/delay.h>

void HKPD_Init()
{
	/*Set Columns Pins Direction Output*/
	MDIO_Set_PIN_DIR(HKPD_COLUMN_PORT,PIN5,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(HKPD_COLUMN_PORT,PIN6,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(HKPD_COLUMN_PORT,PIN7,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(MDIO_PORTB,PIN3,PIN_OUTPUT);

	/*Set Row Pins Direction Input*/
	MDIO_Set_PIN_DIR(HKPD_ROW_PORT,HKPD_ROW_0_PIN,PIN_INPUT);
	MDIO_Set_PIN_DIR(HKPD_ROW_PORT,HKPD_ROW_1_PIN,PIN_INPUT);
	MDIO_Set_PIN_DIR(HKPD_ROW_PORT,HKPD_ROW_2_PIN,PIN_INPUT);
	MDIO_Set_PIN_DIR(HKPD_ROW_PORT,HKPD_ROW_3_PIN,PIN_INPUT);

	/*Activate Pull up Resistor */
MDIO_Set_PIN_VALUE(HKPD_ROW_PORT,HKPD_ROW_0_PIN,PIN_HIGH);
MDIO_Set_PIN_VALUE(HKPD_ROW_PORT,HKPD_ROW_1_PIN,PIN_HIGH);
MDIO_Set_PIN_VALUE(HKPD_ROW_PORT,HKPD_ROW_2_PIN,PIN_HIGH);
MDIO_Set_PIN_VALUE(HKPD_ROW_PORT,HKPD_ROW_3_PIN,PIN_HIGH);
/*DEACTIVATE COULMNS*/
MDIO_Set_PIN_VALUE(HKPD_COLUMN_PORT,PIN5,PIN_HIGH);
MDIO_Set_PIN_VALUE(HKPD_COLUMN_PORT,PIN6,PIN_HIGH);
MDIO_Set_PIN_VALUE(HKPD_COLUMN_PORT,PIN7,PIN_HIGH);
MDIO_Set_PIN_VALUE(MDIO_PORTB,PIN3,PIN_HIGH);

}



u8 HKPD_GetPressedButton()
{//EDITED SO THAT THE USED PINS DOESN'T CONLICT WITH OTHER PERIPHERALS
	/*u8 Loc_u8ColumnCounter=0;
	u8 Loc_u8RowCounter=0;

	u8 Loc_u8ReturnValue=HKPD_NOT_PRESSED;

	u8 Loc_u8PinState=0;

	for (Loc_u8ColumnCounter=HKPD_COL_START;Loc_u8ColumnCounter<HKPD_COL_END;Loc_u8ColumnCounter++)
	{
		/Activate the column//
		MDIO_Set_PIN_VALUE(Loc_u8ColumnCounter,HKPD_COLUMN_PORT,PIN_LOW);


		for(Loc_u8RowCounter=HKPD_ROW_START;Loc_u8RowCounter<HKPD_ROW_END;Loc_u8RowCounter++)
		{
			MDIO_Read_PIN(HKPD_ROW_PORT,Loc_u8RowCounter,&Loc_u8PinState);

			if(Loc_u8PinState==0)
			{
				// Retrieve the Key Value
				Loc_u8ReturnValue=HKPD_SwitchValues[Loc_u8ColumnCounter-HKPD_COL_START][Loc_u8RowCounter-HKPD_ROW_START];

				while(Loc_u8PinState==0)
				{
					MDIO_Read_PIN(HKPD_ROW_PORT,Loc_u8RowCounter,&Loc_u8PinState);
				}
				//Further Update : Put a delay here
			}
			else
			{
				//Do Nothing
			}
		}

		//Deactivate Column
		MDIO_Set_PIN_VALUE(Loc_u8ColumnCounter,HKPD_COLUMN_PORT,PIN_HIGH);
	}
	return Loc_u8ReturnValue;
	*/






	u8 Local_u8_KeypadReading		=0;
		u8 Local_u8_KeyPadArr [4][4]	={{'7','8','9','/'},
											{'4','5','6','*'},
											{'1','2','3','-'},
											{'C','0','=','+'}};


		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_LOW);

		if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][0];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][1];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][2];}}
		if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) {while(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][3];}}

		 MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN3,PIN_HIGH);

		 MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN5,PIN_LOW);

		if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN5,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][0];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN5,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][1];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN7)==0 )  { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0); MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN5,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][2];}}
		if(MDIO_Return_PINValue(MDIO_PORTB,PIN3)==0 )  { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) {while(MDIO_Return_PINValue(MDIO_PORTB,PIN3)==0) ;  MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN5,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][3];}}

		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN5,PIN_HIGH);


		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN6,PIN_LOW);

		if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN6,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][0];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN6,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][1];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN6,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][2];}}
		if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) {while(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN6,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][3];}}

		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN6,PIN_HIGH);


		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN7,PIN_LOW);

		if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN5) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN7,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][0];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN6) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN7,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][1];}}
		if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0) {while(MDIO_Return_PINValue(MDIO_PORTA,PIN7) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN7,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][2];}}
		if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) { _delay_ms(30);if(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0) {while(MDIO_Return_PINValue(MDIO_PORTB,PIN3) == 0);MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN7,PIN_HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][3];}}

		MDIO_Set_PIN_VALUE(MDIO_PORTC,PIN7,PIN_HIGH);

		return Local_u8_KeypadReading ;























}
