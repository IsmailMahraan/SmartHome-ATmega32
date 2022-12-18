/*
 * MSevenSegment_Program.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Ismail
 */
#include"HSevenSegment_Interface.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"HevenSegment_Private.h"
void HSEVENSEGMENT_Init(SevenSeg_t* Ptr_SevenSegObj){

	MDIO_Set_PIN_DIR(Ptr_SevenSegObj->PinEnPort,Ptr_SevenSegObj->PinEn,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_OUTPUT);
	MDIO_Set_PIN_DIR(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_OUTPUT);
}

void HSEVENSEGMENT_SetMode(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegMode){
	if(Copy_u8SevenSegMode==SEVEN_SEG_ON){

		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinEnPort,Ptr_SevenSegObj->PinEn,PIN_HIGH);
	}
	else if(Copy_u8SevenSegMode==SEVEN_SEG_OFF){
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinEnPort,Ptr_SevenSegObj->PinEn,PIN_LOW);

	}
	else {

		// wrong Mode ordered
	}

}
void HSEVENSEGMENT_Display(SevenSeg_t* Ptr_SevenSegObj,u8 Copy_u8SevenSegValue){
if(Copy_u8SevenSegValue>=0 && Copy_u8SevenSegValue<10){
	switch (Copy_u8SevenSegValue){
	case 0:
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

		break;
	case 1:
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_HIGH);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

		break;
	case 2:
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_HIGH);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
		MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

		break;
		case 3:
			MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_HIGH);
			MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_HIGH);
			MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
			MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

			break;
			case 4:
				MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_LOW);
				MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
				MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_HIGH);
				MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

				break;
				case 5:
					MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_HIGH);
					MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
					MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_HIGH);
					MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

					break;
					case 6:
						MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_LOW);
						MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_HIGH);
						MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_HIGH);
						MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

						break;
						case 7:
							MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_HIGH);
							MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_HIGH);
							MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_HIGH);
							MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);

							break;
							case 8:
								MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_LOW);
								MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
								MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
								MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_HIGH);


								break;
								case 9:
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_HIGH);
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_HIGH);

									break;

								default :
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinAport,Ptr_SevenSegObj->PinA,PIN_LOW);
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinBport,Ptr_SevenSegObj->PinB,PIN_LOW);
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinCport,Ptr_SevenSegObj->PinC,PIN_LOW);
									MDIO_Set_PIN_VALUE(Ptr_SevenSegObj->PinDport,Ptr_SevenSegObj->PinD,PIN_LOW);
									break;
	}
}
else{

}

}
