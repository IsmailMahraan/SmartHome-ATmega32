/*
 * MTIMER1_Interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MTIMER1_MTIMER1_INTERFACE_H_
#define MCAL_MTIMER1_MTIMER1_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"

#define TIMER1_FALLING_EDGE								0
#define TIMER1_RISING_EDGE								1
/***********************************************************************************/


/************************************************************************************/
/*							 FUNCTIONS PROTOTYPES								    */
/************************************************************************************/

/************************************************************************************/
/* Description: initializes timer1's peripheral	  								    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_Init(void);
/************************************************************************************/

/************************************************************************************/
/* Description: sets a value to start counting from								    */
/* Inputs: value to count from													 	*/
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_Preload(const u16 LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sets a value to overflow at in non-normal modes. The minimum value	*/
/* allowed is 0x0003. 					    										*/
/* Inputs: TOP value												 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_SetCounterTOP(const u16 LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sets the value to be compared with for Output Compare unit A 		*/
/* Inputs: value to compare with									 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_SetOCACompareValue(const u16 LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sets the value to be compared with for Output Compare unit B 		*/
/* Inputs: value to compare with									 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_SetOCBCompareValue(const u16 LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: sends a PWM signal with the received duty cycle (0% - 100%) on		*/
/* OC1A pin.																		*/
/* Inputs: Duty cycle - Counter top value (minimum 0x0003)			 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_OC1ASetDutyCycle( f32 LOC_F32DutyCycle);
/************************************************************************************/

/************************************************************************************/
/* Description: sends a PWM signal with the received duty cycle (0% - 100%) on		*/
/* OC1B pin.																		*/
/* Inputs: Duty cycle - Counter top value (minimum 0x0003)			 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_OC1BSetDutyCycle( f32 LOC_F32DutyCycle);
/************************************************************************************/

/************************************************************************************/
/* Description: returns the value in timer1's counter. Counts are in the range of   */
/* 0 - 65535.					    													*/
/* Inputs: pointer to a variable to receive the value in			 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_GetCounterValue(u16* const LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: activates the Input Capture Noise Canceler. When the Noise			*/
/* Canceler is activated, the input from the Input Capture Pin (ICP1) is filtered.	*/
/* Notice that The input capture is delayed by four Oscillator cycles when the 		*/
/* Noise Canceler is enabled														*/
/* Inputs: nothing			 	 		    										*/
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_EnableNoiseCanceler(void);
/************************************************************************************/

/************************************************************************************/
/* Description: deactivates the Input Capture Noise Canceler. 						*/
/* Inputs: nothing			 	 		    										*/
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_DisableNoiseCanceler(void);
/************************************************************************************/

/************************************************************************************/
/* Description: selects which edge on the Input Capture Pin (ICP1) that is used to	*/
/* trigger a capture event. 														*/
/* Inputs: nothing			 	 		    										*/
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_ICEdgeSelect(const u8 LOC_U8Edge);
/************************************************************************************/

/************************************************************************************/
/* Description: gets the value captured on the Input Capture Pin (ICP1). ICR1		*/
/* should not be used for defining TOP in this case in order to function correctly.	*/
/* Inputs: pointer to a variable to receive the value in							*/
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_GetCapturedValue(u16* const LOC_U16Value);
/************************************************************************************/

/************************************************************************************/
/* Description: enables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_EnableOVFInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_DisableOVFInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare A Match interrupt enable							    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_OCAEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare A Match interrupt disable						    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_OCADisableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare B Match interrupt enable							    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_OCBEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Output Compare B Match interrupt disable						    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_OCBDisableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Capture Event interrupt enable									    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_CaptureEventEnableInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: Capture Event interrupt disable									    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
void Timer1_CaptureEventDisableInterrupt(void);
/************************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 overflow's flag						 			   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_OVFPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 Output Compare A Match flag			 			   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
void  Timer1_OCAPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 Output Compare B Match flag			 			   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
void  Timer1_OCBPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer1 Capture Event flag					 			   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_CaptureEventPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the overflow interrupt.  								 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_OVFSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the Output Compare A Match flag						 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_OCASetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the Output Compare B Match flag						 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_OCBSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the Capture Event flag								 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_CaptureEventSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: restarts timer1's prescaler. Note that this	affects both timer0	   */
/* and timer1						 			   			   					   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
void Timer1_ResetPrescaler(void);
void MPWM1Init();
void MPWM1SetDutyCycle(f32 Local_f32DesiredDutyCycle);
void MPWM1SetFrequency(u16 Local_u16DesiredFrequency);
void MPWM1Start();
void MPWM1Stop();



#endif /* MCAL_MTIMER1_MTIMER1_INTERFACE_H_ */
