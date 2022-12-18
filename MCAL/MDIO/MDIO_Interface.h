/*
 * DIO_Interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Ismail
 */

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPE.h"
#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3
#define PIN_HIGH 1
#define PIN_LOW 0
#define PORT_OUTPUT 255
#define PORT_INPUT 0
#define PIN_OUTPUT 1
#define PIN_INPUT 0
#define NULL 0
typedef enum{

	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7

}Pin_t;


void MDIO_Set_PORT_DIR(u8 Copy_u8PortNumber,u8 Copy_u8PortDirection);
void MDIO_Set_PIN_DIR(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PinDirection);
void MDIO_Set_PORT_VALUE(u8 Copy_u8PortNumber,u8 Copy_u8PortNumberValue);
void MDIO_Set_PIN_VALUE(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 Copy_u8PortNumberValue);
void MDIO_Read_PORT(u8 Copy_u8PortNumber,u8 * P_u8PortReading);
void MDIO_Read_PIN(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 * P_u8PortReading);
void MDIO_Toggle_PIN(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
void MDIO_SetNibbleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber, u8 Copy_u8Value);
u8 MDIO_Return_PINValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber);
#endif /* DIO_INTERFACE_H_ */
