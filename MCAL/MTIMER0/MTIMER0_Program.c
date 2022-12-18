/*
 * MTIMER_Program.c
 *
 *  Created on: Oct 28, 2022
 *      Author: medo
 */
#include"../../LIB/STD_TYPE.h"
#include"../../LIB/BIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include "MTIMER0_Config.h"
#include "MTIMER0_Private.h"



//Two Global Pointers
void (*Glob_OverflowISR_Ptr)(void)=NULL;
void (*Glob_CTC_ISR_Ptr)(void)=NULL;

/**
 * Init:
 * 1-SetMode of Timer
 * 2-Set OC0 Mode
 * 3-Set Interrupt State
 * 4-Set Prescalar
 */

void MTIMER0_Init()
{
	//SetMode of Timer
	//============================ Normal Mode
#if TIMER0_MODE==TIMER_NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//Set Normal Mode interrupt
#if TIMER0_NORMAL_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_DISABLED
	CLR_BIT(TIMSK,0);
#elif TIMER0_NORMAL_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_ENABLED
	SET_BIT(TIMSK,0);
#endif

	//============================CTC Mode
#elif TIMER0_MODE==TIMER_CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);


	//Set OC0 Mode
#if TIMER0_OC0_MODE==OC0_PIN_DISCONNECTED
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#elif TIMER0_OC0_MODE==OC0_PIN_TOGGLE
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#elif TIMER0_OC0_MODE==OC0_PIN_CLEARED
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_MODE==OC0_PIN_SET
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif



	//Set CTC Mode interrupt
#if TIMER0_CTC_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_DISABLED
	CLR_BIT(TIMSK,1);
#elif TIMER0_CTC_MODE_INTERRUPT_STATE==NORMAL_MODE_INTERRUPT_ENABLED
	SET_BIT(TIMSK,1);
#endif

	//============================FAST PWM MODE
#elif TIMER0_MODE==TIMER_FAST_PWM_MODE
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

		//Set PWM Wave on OC0
	#if TIMER0_FAST_PWM_WAVE_MODE==FAST_PWM_OC0_DISCONNECTED
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	#elif TIMER0_FAST_PWM_WAVE_MODE==FAST_PWM_OC0_NON_INVERTING
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif TIMER0_FAST_PWM_WAVE_MODE==FAST_PWM_OC0_INVERTING
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#endif

		//============================Phase Correct Mode
#elif TIMER0_MODE==TIMER_PWM_PHASE_CORRECT_MODE
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	//Set PWM Wave on OC0
	#if TIMER0_PHASE_CORRECT_PWM_WAVE_MODE==PHASE_CORRECT_PWM_OC0_DISCONNECTED
		CLR_BIT(TCCR0,4);
		CLR_BIT(TCCR0,5);
	#elif TIMER0_PHASE_CORRECT_PWM_WAVE_MODE==PHASE_CORRECT_PWM_OC0_NON_INVERTING
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#elif TIMER0_PHASE_CORRECT_PWM_WAVE_MODE==PHASE_CORRECT_PWM_OC0_INVERTING
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	#endif

#else
#error "Wrong Mode chosen"
#endif

	//SET PRESCALAR
#if TIMER0_CLOCK_SOURCE==NO_CLOCK
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==SYSTEM_CLOCK
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==PRESCALAR_OVER_1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==EXTERNAL_CLOCK_FALLING_EDGE
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif TIMER0_CLOCK_SOURCE==EXTERNAL_CLOCK_RISING_EDGE
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#endif

}

void MTIMER0_SetPreload(u8 Copy_u8Preload)
{
	TCCR0=Copy_u8Preload;

}

void MTIMER0_SetCTC(u8 Copy_u8OCR)
{
	OCR0=Copy_u8OCR;
}


void MTIMER0_OVERFLOW_CALLBACK(void(*Ptr_OverflowApp)(void))
{
	if(Ptr_OverflowApp!=NULL)
	{
		if(Glob_OverflowISR_Ptr==NULL)
		{
			Glob_OverflowISR_Ptr=Ptr_OverflowApp;
		}
	}
}


void MTIMER0_CTC_CALLBACK(void(*Ptr_CTCApp)(void))
{
	if(Ptr_CTCApp !=NULL)
	{
		if(Glob_CTC_ISR_Ptr==NULL)
		{
			Glob_CTC_ISR_Ptr=Ptr_CTCApp;
		}
	}
}


//CTC ISR
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(Glob_CTC_ISR_Ptr!=NULL)
	{
		Glob_CTC_ISR_Ptr();
	}
}

//Overflow TIMER0 ISR
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(Glob_OverflowISR_Ptr!=NULL)
	{
		Glob_OverflowISR_Ptr();
	}
}



void M_Pwm0_Init  (void)
{
	MDIO_Set_PIN_DIR(MDIO_PORTB,3,PIN_OUTPUT);

	#if			TIMER0_MODE		==		TIMER_FAST_PWM_MODE
	SET_BIT(TCCR0,3); SET_BIT(TCCR0,6);
	#elif		TIMER0_MODE		==		TIMER_PWM_PHASE_CORRECT_MODE
	CLR_BIT(TCCR0,3); SET_BIT(TCCR0,6);
	#endif

	#if			TIMER0_FAST_PWM_WAVE_MODE		==		FAST_PWM_OC0_NON_INVERTING
	SET_BIT(TCCR0,5); CLR_BIT(TCCR0,4);
	#elif		TIMER0_FAST_PWM_WAVE_MODE		==		FAST_PWM_OC0_INVERTING
	SET_BIT(TCCR0,5); SET_BIT(TCCR0,4);
	#endif

}

void M_Pwm0_SetDutyCycle		(u8 Local_u8_DesiredDutyCycle)
{
	#if			TIMER0_FAST_PWM_WAVE_MODE		==		FAST_PWM_OC0_NON_INVERTING

	if(Local_u8_DesiredDutyCycle == 0)
	{
		SET_BIT(TCCR0,5); SET_BIT(TCCR0,4);
		OCR0 = (255 - ((Local_u8_DesiredDutyCycle *255)/100));
	}
	else
	{
		SET_BIT(TCCR0,5); CLR_BIT(TCCR0,4);
		OCR0 = (((Local_u8_DesiredDutyCycle * 25) / 100) - 1);
	}

	#elif		TIMER0_FAST_PWM_WAVE_MODE		==		FAST_PWM_OC0_INVERTING
	if(Local_u8_DesiredDutyCycle == 100)
	{
		SET_BIT(TCCR0,5); CLR_BIT(TCCR0,4);
		OCR0 = (((Local_u8_DesiredDutyCycle * 256) / 100) - 1);
	}
	else
	{
		SET_BIT(TCCR0,5); SET_BIT(TCCR0,4);
		OCR0 = (255 - ((Local_u8_DesiredDutyCycle *256)/100));
	}
	#endif

}

void M_Timer0_Start			(void)
{
	#if			TIMER0_CLOCK_SOURCE	==		PRESCALAR_OVER_1
	CLR_BIT(TCCR0,2); CLR_BIT(TCCR0,1);	SET_BIT(TCCR0,0);
	#elif		TIMER0_CLOCK_SOURCE	==		PRESCALAR_OVER_8
	CLR_BIT(TCCR0,2); SET_BIT(TCCR0,1);	CLR_BIT(TCCR0,0);
	#elif		TIMER0_CLOCK_SOURCE	==		PRESCALAR_OVER_64
	CLR_BIT(TCCR0,2); SET_BIT(TCCR0,1);	SET_BIT(TCCR0,0);
	#elif		TIMER0_CLOCK_SOURCE	==		PRESCALAR_OVER_256
	SET_BIT(TCCR0,2); CLR_BIT(TCCR0,1);	SET_BIT(TCCR0,0);
	#elif		TIMER0_CLOCK_SOURCE	==		PRESCALAR_OVER_1024
	SET_BIT(TCCR0,2); CLR_BIT(TCCR0,1);	SET_BIT(TCCR0,0);
	#endif
}

void M_Timer0_Stop			(void)
{
	CLR_BIT(TCCR0,2); CLR_BIT(TCCR0,1);	CLR_BIT(TCCR0,0);
}

void M_Pwm0_Start(void)
{
	M_Timer0_Start();
}

void M_Pwm0_Stop(void)
{
	M_Timer0_Stop();
}
