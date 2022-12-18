/*
 * HC05_Program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */
#include"HC05_Interface.h"

void HHC05_Init(void){
	MUSART_Init();
}
void HHC05_SendChar(u8 Copy_u8Data){
	MUSART_SendChar(Copy_u8Data);
}
void HHC05_SendString(u8 *Copy_u8PtrToData){
MUSART_SendString(Copy_u8PtrToData);
MUSART_SendChar(13);
}
u8 HHC05_RecieveData(void){

	u8 Local_u8_Data = 0;
	Local_u8_Data = M_Uart_Read();
	return Local_u8_Data;

}
