/*
 * HCLCD_Program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Ismail
 */

#include "HCLCD_Interface.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "HCLCD_Config.h"
#include <util/delay.h>
void HCLCDInit4BitMode(){

_delay_ms(30);

//SET DIRECTION OF THE used PINS


	MDIO_Set_PIN_DIR(DATA_PORT,PIN4,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(DATA_PORT,PIN5,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(DATA_PORT,PIN6,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(DATA_PORT,PIN7,PIN_OUTPUT);

//SET DIRECTION OF THE CONTROL PINS
MDIO_Set_PIN_DIR(CONTROL_PORT,RS,PIN_OUTPUT);
MDIO_Set_PIN_DIR(CONTROL_PORT,RW,PIN_OUTPUT);
MDIO_Set_PIN_DIR(CONTROL_PORT,E,PIN_OUTPUT);

//START OF THE INTIALIZATION SEQUENCE
//SEND FUNCTION SET COMMAND
MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,FUNCTION_SET_MODE_COMMAND>>4);
//SEND THE FALLING EDGE ENABLE
	MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_HIGH);
	_delay_ms(2);
	MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_LOW);

HCLCD_WriteCommand4Bit(FUNCTION_SET_MODE_COMMAND);
//SEND DISPLAY CONTROL COMMAND
_delay_ms(1); //SHOULD BE 39US
HCLCD_WriteCommand4Bit(DISPALY_ON_OFF_COMMAND);
//SEND CLEAR COMMAND
_delay_ms(1); //SHOULD BE 39US
HCLCD_WriteCommand4Bit(DISPLAY_CLEAR_COMMAND);
//SEND ENRTYMODE COMMAND
_delay_ms(2);
HCLCD_WriteCommand4Bit(ENTRY_MODE_COMMAND);

}
void HCLCD_WriteCommand4Bit(u8 Copy_u8Command){
	//SET RW TO ZERO
	MDIO_Set_PIN_VALUE(CONTROL_PORT,RW,PIN_LOW);
	//SET RS TO ZERO
	MDIO_Set_PIN_VALUE(CONTROL_PORT,RS,PIN_LOW);
	//set high nibble value of command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Command>>4);
	//SEND THE FALLING EDGE ENABLE
	MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_HIGH);
	_delay_ms(2);
	MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_LOW);
	//set LOW nibble value of command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Command);
	//SEND THE FALLING EDGE ENABLE
		MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_HIGH);
		_delay_ms(2);
		MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_LOW);
}
void HCLCD_WriteChar4Bit(u8 Copy_u8Data){
	//SET RW TO low
	MDIO_Set_PIN_VALUE(CONTROL_PORT,RW,PIN_LOW);
	//SET RS TO high
	MDIO_Set_PIN_VALUE(CONTROL_PORT,RS,PIN_HIGH);
	//set high nibble value of DATA
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Data>>4);
	//SEND THE FALLING EDGE ENABLE
	MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_HIGH);
	_delay_ms(2);
	MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_LOW);
	//set LOW nibble value of DATA
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT,Copy_u8Data);
	//SEND THE FALLING EDGE ENABLE
		MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_HIGH);
		_delay_ms(2);
		MDIO_Set_PIN_VALUE(CONTROL_PORT,E,PIN_LOW);

}
void HCLCD_WriteString(char *u8Copy_u8String){
	u8 Loc_u8Counter=0;
	u8 Copy_u8Data_SizeofString =0;
	for (Loc_u8Counter = 0; u8Copy_u8String[Loc_u8Counter] != '\0'; Loc_u8Counter++){
		Copy_u8Data_SizeofString =Loc_u8Counter+1;
	}
	if(Copy_u8Data_SizeofString>32){
		HCLCD_WriteString("string supported is 32chars!");

	}
	else{
	Loc_u8Counter =0;
	while(Copy_u8Data_SizeofString>0){
		if(Loc_u8Counter<HCLCD_LINE_LENGTH){
			 HCLCD_WriteChar4Bit(u8Copy_u8String[Loc_u8Counter]);
		     Loc_u8Counter++;
			 Copy_u8Data_SizeofString--;
		}
		else{
			 HCLCD_SetCursorPosition(HCLCD_LINE_1, Loc_u8Counter-HCLCD_LINE_LENGTH);
			 HCLCD_WriteChar4Bit(u8Copy_u8String[Loc_u8Counter]);
			 Loc_u8Counter++;
			 Copy_u8Data_SizeofString--;
		}
	}
	}

}
void HCLCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber)
{
if((Copy_u8LineNumber==HCLCD_LINE_0)||(Copy_u8LineNumber==HCLCD_LINE_1))
{
	if(Copy_u8PositionNumber<16)
	{
		if(Copy_u8LineNumber==HCLCD_LINE_0)
		{
			HCLCD_WriteCommand4Bit(Copy_u8PositionNumber+HCLCD_LINE0_OFFSET);
		}
		else
		{
			HCLCD_WriteCommand4Bit(Copy_u8PositionNumber+HCLCD_LINE1_OFFSET);
		}
	}
}
else
{
	//Wrong Line Chosen
}
}
void HCLCD_WriteNumber(u32 Copy_u32Number)
{
	/*Define an array of 10 elements to hold the number digits
	size is 10 because larger number in u32 is 4,294,967,295
	which is 10 digits
	 */
	u8 Loc_u8Arr_Digits[10];

	/*Define a Local Counter to traverse the array*/
	u8 Loc_Counter=0;

	/*Check on the upcoming number*/
	if(Copy_u32Number>0)
	{
		/*Parsing the number into the array*/
		while(Copy_u32Number!=0) //Exit Condition means number is done parsing
		{
			//Extract the Least Significant Digit and Put it in the
			//Array
			Loc_u8Arr_Digits[Loc_Counter]=Copy_u32Number%10 ;

			//Removing the Extracted digit from the number
			Copy_u32Number=Copy_u32Number/10 ;

			//Increasing the counter so the digits are saved in next array element
			Loc_Counter++;

		}

		//Here the parsing is finished and the digits are saved
		//in the array but backwards

		//Take Care Loc_forCounter is signed
		//because we are decrementing it
		s8 Loc_forCounter;
		for(Loc_forCounter=Loc_Counter-1;Loc_forCounter>=0;Loc_forCounter--)
		{
			//Write the digits to the screen in their right order
			//Notice the addition of the number to the ASCII Code
			//of the number 0 because our Function takes ASCII of character
			//to Print on the LCD
			HCLCD_WriteChar4Bit(Loc_u8Arr_Digits[Loc_forCounter]+'0');
		}

	}
	else
	{
		/*if the number is zero so we have to send ASCII Code of Zero*/
		HCLCD_WriteChar4Bit('0');
	}

}

