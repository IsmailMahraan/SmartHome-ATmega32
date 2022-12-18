/*
 * HCLCD_Interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Ismail
 */

#ifndef HAL_HCLCD_HCLCD_INTERFACE_H_
#define HAL_HCLCD_HCLCD_INTERFACE_H_
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HCLCD_Config.h"
#include "HCLCD_Private.h"
#define RS 0
#define	RW 1
#define E  2
#define HCLCD_PIN_START 4
#define CONTROL_PORT MDIO_PORTB
#define DATA_PORT MDIO_PORTB

/*Macros For Users*/
#define HCLCD_LINE_0 0
#define HCLCD_LINE_1 1


void HCLCDInit4BitMode();
void HCLCD_WriteCommand4Bit(u8 Copy_u8Command);
void HCLCD_WriteChar4Bit(u8 Copy_u8Data);
void HCLCD_WriteString(char *u8Copy_u8String);
void HCLCD_SetCursorPosition(u8 Copy_u8LineNumber,u8 Copy_u8PositionNumber);
void HCLCD_WriteNumber(u32 Copy_u8Number);
#endif /* HAL_HCLCD_HCLCD_INTERFACE_H_ */
