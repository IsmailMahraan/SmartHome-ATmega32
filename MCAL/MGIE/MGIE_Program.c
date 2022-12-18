/*
 * MGIE_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */
#include "MGIE_Private.h"
#include "MGIE_Interface.h"
#include "../../LIB/BIT_MATH.h"
void MGIE_Enable(void){

SET_BIT(SREG,7);
}



void MGIE_Disable(void){

CLR_BIT(SREG,7);

}




