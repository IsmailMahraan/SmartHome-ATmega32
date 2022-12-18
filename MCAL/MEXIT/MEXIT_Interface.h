/*
 * MEXIT_Interface.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MEXIT_MEXIT_INTERFACE_H_
#define MCAL_MEXIT_MEXIT_INTERFACE_H_
/*prototypes*/
void MEXIT0_Init();
void MEXIT1_Init();
void MEXIT2_Init();

void MEXIT2_Set_Sense_Control(u8 Copy_u8Interrupt_ID, u8 Copy_u8Mode);//during run time to change//
void __vector_1 (void) __attribute__((signal));//interrupt writing in c
void MEXIT_Callback(void(*Loc_PtrToFunc)(void));
#endif /* MCAL_MEXIT_MEXIT_INTERFACE_H_ */
