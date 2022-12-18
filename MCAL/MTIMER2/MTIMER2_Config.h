/*
 * MTIMER2_Config.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MTIMER2_MTIMER2_CONFIG_H_
#define MCAL_MTIMER2_MTIMER2_CONFIG_H_
#include"MTIMER2_Private.h"

/**************_TIMER2_CLOCK_OPTIONS_******************/
/*
 *	TO CHOOSE TIMER0
 *		OPTION 1		->		NO_CLK				->	For stopping the clock
 *		OPTION 2		->		PRESCALER_1			->	For	starting the clock without a prescaler
 *		OPTION 3		->		PRESCALER_8			->	For starting the clock with prescaler 8
 *		OPTION 4		->		PRESCALER_64	    ->	For starting the clock with prescaler 64
 *		OPTION 5		->		PRESCALER_256		->	For	starting the clock with prescaler 256
 *		OPTION 6		->		PRESCALER_1024		->	For starting the clock with prescaler 1024
 *		OPTION 7		->		CLK_FALLING_EDGE	->	External clock source on T0 pin. Clock on falling edge.
 *		OPTION 8		->		CLK_RISING_EDGE		->	External clock source on T0 pin. Clock on rising edge.
 */

#define MTIMER2_PRESCALER		PRESCALER_1024


/******_TIMER2_MODE_OF_OPERATION_******/
/*
 *	CHOOSE OPERATION MODE FOR TIMER 2
 *		OPTION 1		->		NORMAL
 *		OPTION 2		->		CTC
 */

#define MTIMER2_MODE				NORMAL

/*****_TIMER2_MODE_OF_OPERATION_*****/
/*
 *	CHOOSE OPERATION MODE FOR PWM2
 *		OPTION 1		->		FAST_PWM
 *		OPTION 2		->		PHASE_CORRECT
 */

#define MPWM2_MODE				FAST_PWM

/****************************************_TIMER2_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR PWM2
 *		OPTION 1		->		NON_INVERTED
 *		OPTION 2		->		INVERTED
 */

#define OUTPUT_MODE				NON_INVERTED



#endif /* MCAL_MTIMER2_MTIMER2_CONFIG_H_ */
