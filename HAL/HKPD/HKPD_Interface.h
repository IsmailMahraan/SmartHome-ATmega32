/*
 * HKPD_Interface.h
 *
 *  Created on: Oct 14, 2022
 *      Author: medo
 */

#ifndef HAL_HKPD_HKPD_INTERFACE_H_
#define HAL_HKPD_HKPD_INTERFACE_H_

#include"../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"


#define HKPD_COLUMN_PORT 	MDIO_PORTA
#define HKPD_ROW_PORT		MDIO_PORTC

typedef enum
{
	HKPD_COLUMN_0_PIN,
		HKPD_COLUMN_1_PIN,
		HKPD_COLUMN_2_PIN,
		HKPD_COLUMN_3_PIN,
		HKPD_ROW_0_PIN,
		HKPD_ROW_1_PIN,
		HKPD_ROW_2_PIN,
		HKPD_ROW_3_PIN



}HKPD_Pins;
#define HKPD_NOT_PRESSED 255

#define HKPD_ROW_START	4
#define HKPD_COL_START	0	/**ADD 1TO THE REAL PIN NUMBER**/
#define HKPD_ROW_END	8
#define HKPD_COL_END	4
/*Prototypes for The Functions*/
void HKPD_Init();
u8 HKPD_GetPressedButton();


#endif /* HAL_HKPD_HKPD_INTERFACE_H_ */
