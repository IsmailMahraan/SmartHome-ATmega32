/*
 * MEXIT_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Ismail
 */

/*1)set the sense control
 * 2)Enable PIE(preferal interrupt enable )
 * 3) ENABLE GIE
 */
#include "MEXIT_Private.h"
#include "MEXIT_Config.h"
#include "../../LIB/BIT_MATH.h"
#define NULL 0
/*GLOBAL POINTER TO FUNCTION to not violate the abstraction of the layered architecture
 *  and to isolate the function from the MCAL*/
void (*Global_Pointer)(void)=NULL;
void MEXIT0_Init(){
#if MEXIT_SENSE_CONTROL_STATE==MEXIT_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif MEXIT_SENSE_CONTROL_STATE==MEXIT_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif MEXIT_SENSE_CONTROL_STATE==MEXIT_RISING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
#elif MEXIT_SENSE_CONTROL_STATE==MEXIT_FALLING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,0);
#endif
/*enable interrupt on int0*/
	SET_BIT(GICR,6);

}
void MEXIT1_Init(){


}

void MEXIT2_Init(){




}

void MEXIT_Callback(void(*Loc_PtrToFunc)(void)){

	if(Loc_PtrToFunc!=NULL){

		Global_Pointer=Loc_PtrToFunc;
	}
}


void __vector_1 (void) {
//function body;
// what will happen when INT0 happen

	if(Global_Pointer!=NULL){
		Global_Pointer();
	}
}
