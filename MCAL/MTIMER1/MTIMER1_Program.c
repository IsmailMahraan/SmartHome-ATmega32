/*
 * MTIMER1_PROGRAM.C
 *
 *  Created on: Nov 11, 2022
 *      Author: Ismail
 */

#include"MTIMER1_Private.h"
#include"../../MCAL/MDIO/MDIO_Interface.h"
#include"../../LIB/BIT_MATH.h"
#include"MTIMER1_Config.h"
#include"MTIMER1_Interface.h"
#define CRYSTALFREQUENCY 16000000

#define ERROR 		1
#define NO_ERROR 	0


void (*GLOB_VidTimer1OVFPtrCallBack)(void) = NULL;
void (*GLOB_VidTimer1OCAPtrCallBack)(void) = NULL;
void (*GLOB_VidTimer1OCBPtrCallBack)(void) = NULL;
void (*GLOB_VidTimer1CaptureEventPtrCallBack)(void) = NULL;
void Timer1_Init(void)
{
	/* Mode of Operation Configuration */
#if MODE == NORMAL
	CLR_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_CORRECT_8_BIT
	CLR_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_CORRECT_9_BIT
	CLR_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_CORRECT_10_BIT
	CLR_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1AR, WGM11);
	SET_BIT(TCCR1A, WGM10);

#elif MODE == CTC_OCR1A
	CLR_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == FAST_PWM_8_BIT
	CLR_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM10);

#elif MODE == FAST_PWM_9_BIT
	CLR_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == FAST_PWM_10_BIT
	CLR_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_AND_FREQUENCY_CORRECT_ICR1
	SET_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A
	SET_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_CORRECT_ICR1
	SET_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == PHASE_CORRECT_OCR1A
	SET_BIT(TCCR1B, WGM13);
	CLR_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM10);

#elif MODE == CTC_ICR1
	SET_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == FAST_PWM_ICR1
	SET_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);

#elif MODE == FAST_PWM_OCR1A
	SET_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1A, WGM10);

#else
#error "Invalid mode of operation for timer1"
#endif

	/* Output Compare Pins Behavior */
#if MODE == CTC_ICR1 || MODE == CTC_OCR1A || MODE == NORMAL
#if OC1A_NON_PWM == DISCONNECT_OC1A
	CLR_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif OC1A_NON_PWM == TOGGLE_OC1A
	CLR_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#elif OC1A_NON_PWM == CLEAR_OC1A
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif OC1A_NON_PWM == SET_OC1A
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#else
#error "Incorrect output compare pin (OC1A) behavior in case of non-PWM mode"
#endif
#if OC1B_NON_PWM == DISCONNECT_OC1B
	CLR_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif OC1B_NON_PWM == TOGGLE_OC1B
	CLR_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1A, COM1B0);
#elif OC1B_NON_PWM == CLEAR_OC1B
	SET_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif OC1B_NON_PWM == SET_OC1B
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1A, COM1B0);
#else
#error "Incorrect output compare pin (OC1B) behavior in case of non-PWM mode"
#endif
#elif MODE == FAST_PWM_10_BIT || MODE == FAST_PWM_9_BIT || MODE == FAST_PWM_8_BIT \
   || MODE == FAST_PWM_ICR1 || MODE == FAST_PWM_OCR1A
#if OC1A_FAST_PWM == DISCONNECT_OC1A
	CLR_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif OC1A_FAST_PWM == TOGGLE_OC1A
	CLR_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#elif OC1A_FAST_PWM == NON_INVERTED_OC1A
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif OC1A_FAST_PWM == INVERTED_OC1A
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#else
#error "Incorrect output compare pin (OC1A) behavior in case of fast PWM mode"
#endif
#if OC1B_FAST_PWM == DISCONNECT_OC1B
	CLR_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif OC1B_FAST_PWM == NON_INVERTED_OC1B
	SET_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif OC1B_FAST_PWM == INVERTED_OC1B
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1A, COM1B0);
#else
#error "Incorrect output compare pin (OC1B) behavior in case of fast PWM mode"
#endif
#elif MODE == PHASE_AND_FREQUENCY_CORRECT_ICR1 || MODE == PHASE_CORRECT_10_BIT  || \
	  MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A || MODE == PHASE_CORRECT_9_BIT || \
	  MODE == PHASE_CORRECT_8_BIT || MODE == PHASE_CORRECT_ICR1 || MODE == \
	  PHASE_CORRECT_OCR1A
#if OC1A_PHASE == DISCONNECT_OC1A
	CLR_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif OC1A_PHASE == TOGGLE_OC1A
	CLR_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#elif OC1A_PHASE == NON_INVERTED_OC1A
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);
#elif OC1A_PHASE == INVERTED_OC1A
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, COM1A0);
#else
#error "Incorrect output compare pin (OC1A) behavior in case of phase correct or phase and frequency correct PWM modes"
#endif
#if OC1B_PHASE == DISCONNECT_OC1B
	CLR_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif OC1B_PHASE == NON_INVERTED_OC1B
	SET_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1B0);
#elif OC1B_PHASE == INVERTED_OC1B
	SET_BIT(TCCR1A, COM1B1);
	SET_BIT(TCCR1A, COM1B0);
#else
#error "Incorrect output compare pin (OC1B) behavior in case of phase correct or phase and frequency correct PWM modes"
#endif
#endif

#if CLOCK_SELECT == NO_CLOCK_SOURCE
	CLR_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == NO_PRESCALER
	CLR_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == PRESCALER_8
	CLR_BIT(TCCR1B, CS12);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == PRESCALER_64
	CLR_BIT(TCCR1B, CS12);
	SET_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == PRESCALER_256
	SET_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == PRESCALER_1024
	SET_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == EXTERNAL_T0_FALLING_EDGE
	SET_BIT(TCCR1B, CS12);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS10);
#elif CLOCK_SELECT == EXTERNAL_T0_RISING_EDGE
	SET_BIT(TCCR1B, CS12);
	SET_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
#else
#error "Incorrect clock selection"
#endif
}

void Timer1_Preload(const u16 LOC_U16Value)
{
	TCNT1 = LOC_U16Value;

}

void Timer1_SetCounterTOP(const u16 LOC_U16Value)
{
	if (LOC_U16Value >= MINIMUM_RESOLUTION)
	{
#if MODE == CTC_OCR1A || MODE == FAST_PWM_OCR1A || MODE == PHASE_CORRECT_OCR1A \
		|| MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A
		OCR1A = LOC_U16Value;
#elif MODE == CTC_ICR1 || MODE == FAST_PWM_ICR1 || MODE == PHASE_CORRECT_ICR1 \
		|| MODE == PHASE_AND_FREQUENCY_CORRECT_ICR1
		ICR1 = LOC_U16Value;
#elif MODE == NORMAL || MODE == PHASE_CORRECT_10_BIT || MODE == PHASE_CORRECT_8_BIT    \
		|| MODE == PHASE_CORRECT_9_BIT || MODE == FAST_PWM_10_BIT || MODE == FAST_PWM_9_BIT \
		|| MODE == FAST_PWM_8_BIT
		/* Trying to set TOP value while using a fixed-TOP mode. */
#else
#error "Invalid mode of operation for timer1"
#endif
	}

}

void Timer1_SetOCACompareValue( u16 LOC_U16Value)
{
#if MODE == CTC_OCR1A || MODE == PHASE_AND_FREQUENCY_CORRECT_OCR1A || MODE == \
		PHASE_CORRECT_OCR1A
	/* Trying to set the OCR1A value as a compare value while using OCR1A as a TOP */
#else
	OCR1A = LOC_U16Value;

#endif
}

void Timer1_SetOCBCompareValue( u16 LOC_U16Value)
{
	OCR1B = LOC_U16Value;

}

void Timer1_OC1ASetDutyCycle( f32 LOC_F32DutyCycle)
{
	if (LOC_F32DutyCycle >= MINIMUM_DUTYCYCLE && LOC_F32DutyCycle <= MAXIMUM_DUTYCYCLE && 1024 >= MINIMUM_RESOLUTION)
	{
		Timer1_SetCounterTOP(1024);
		Timer1_SetOCACompareValue( ( LOC_F32DutyCycle / 100 ) * ( 1024 ) );

	}
	else
	{

	}
}

void Timer1_OC1BSetDutyCycle( f32 LOC_F32DutyCycle)
{
	if (LOC_F32DutyCycle <= MAXIMUM_DUTYCYCLE && 1024 >= MINIMUM_RESOLUTION)
	{
		Timer1_SetCounterTOP(1024);
		Timer1_SetOCBCompareValue( ( LOC_F32DutyCycle / 100 ) * ( 1024 ) );

	}
	else
	{
	}
}

void Timer1_GetCounterValue(u16* const LOC_U16Value)
{
	if (LOC_U16Value != NULL)
	{
		*LOC_U16Value = TCNT1;

	}
	else
	{

	}
}

void Timer1_EnableNoiseCanceler()
{
	SET_BIT(TCCR1B, ICNC1);

}

void Timer1_DisableNoiseCanceler()
{
	CLR_BIT(TCCR1B, ICNC1);
}

void Timer1_ICEdgeSelect(const u8 LOC_U8Edge)
{
	switch (LOC_U8Edge)
	{
		case FALLING_EDGE:
		CLR_BIT(TCCR1B, ICES1);
		break;

		case RISING_EDGE:
		SET_BIT(TCCR1B, ICES1);
		break;
		default:{
			////
		}

	}
}

void Timer1_GetCapturedValue(u16* const LOC_U16Value)
{
	if (LOC_U16Value != NULL)
	{

		*LOC_U16Value = ICR1;

	}
	else
	{

	}
}

void Timer1_EnableOVFInterrupt()
{
	SET_BIT(TIMSK, TOIE1);
}

void Timer1_DisableOVFInterrupt()
{
	CLR_BIT(TIMSK,TOIE1);
}

void Timer1_OCAEnableInterrupt()
{
	SET_BIT(TIMSK, OCIE1A);
}

void Timer1_OCADisableInterrupt()
{
	CLR_BIT(TIMSK, OCIE1A);

}

void Timer1_OCBEnableInterrupt()
{
	SET_BIT(TIMSK, OCIE1B);
}

void Timer1_OCBDisableInterrupt()
{
	CLR_BIT(TIMSK, OCIE1B);

}

void Timer1_CaptureEventEnableInterrupt()
{
	SET_BIT(TIMSK, TICIE1);

}

void Timer1_CaptureEventDisableInterrupt()
{
	CLR_BIT(TIMSK, TICIE1);

}

void Timer1_OVFPollingOnFlag()
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR, TOV1) );
	/* Clear flag */
	SET_BIT(TIFR, TOV1);
}

void Timer1_OCAPollingOnFlag()
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR, OCF1A) );
	/* Clear flag */
	SET_BIT(TIFR, OCF1A);

}

void Timer1_OCBPollingOnFlag()
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR, OCF1B) );
	/* Clear flag */
	SET_BIT(TIFR, OCF1B);

}

void Timer1_CaptureEventPollingOnFlag()
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR, ICF1) );
	/* Clear flag */
	SET_BIT(TIFR, ICF1);

}

void Timer1_OVFSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1OVFPtrCallBack = ptrToFun;

	}
	else
	{
	}
}

void Timer1_OCASetCallBack( void (*ptrToFun)(void) ){
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1OCAPtrCallBack = ptrToFun;

	}
	else
	{

	}
}

void Timer1_OCBSetCallBack( void (*ptrToFun)(void) ){
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1OCBPtrCallBack = ptrToFun;

	}
	else
	{
	}
}

void Timer1_CaptureEventSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer1CaptureEventPtrCallBack = ptrToFun;

	}
	else
	{

	}
}

void Timer1_ResetPrescaler(void)
{
	SET_BIT(SFIOR, PSR10);

}
void MPWM1Init(){
	MDIO_Set_PIN_DIR(MDIO_PORTD,PWM1PIN,PIN_OUTPUT);
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);
	Timer1_Init();
}
void MPWM1SetDutyCycle(f32 Local_f32DesiredDutyCycle){
Timer1_OC1ASetDutyCycle(Local_f32DesiredDutyCycle);
}

void MPWM1SetFrequency(u16 Local_u16DesiredFrequency)
{

	ICR1 = (CRYSTALFREQUENCY) / (Local_u16DesiredFrequency * CLOCK_SELECT);
}
void MPWM1Start()
{
	#if		CLOCK_SELECT == PRESCALER_64
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);

	#elif	CLOCK_SELECT == PRESCALER_256
	SET_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);

	#elif	CLOCK_SELECT == PRESCALER_1024
	SET_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);

	#endif

}
void MPWM1Stop()
{
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
}

void __vector_9(void)
{
	if (GLOB_VidTimer1OVFPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1OVFPtrCallBack)();
	}
}

void __vector_8(void)
{
	if (GLOB_VidTimer1OCBPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1OCBPtrCallBack)();
	}
}

void __vector_7(void)
{
	if (GLOB_VidTimer1OCAPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1OCAPtrCallBack)();
	}
}

void __vector_6(void)
{
	if (GLOB_VidTimer1CaptureEventPtrCallBack != NULL)
	{
		(*GLOB_VidTimer1CaptureEventPtrCallBack)();
	}
}
