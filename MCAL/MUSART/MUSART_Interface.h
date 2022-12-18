/*
 * MUART_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MUSART_MUSART_INTERFACE_H_
#define MCAL_MUSART_MUSART_INTERFACE_H_

void MUSART_Init();
void MUSART_SendChar();
void MUSART_ReceiveChar();
void MUSART_SendString();
void MUSART_ReceiveString();

void M_Uart_Write(u8 Local_u8_Data);
u8  M_Uart_Read(void);

#endif /* MCAL_MUSART_MUSART_INTERFACE_H_ */
