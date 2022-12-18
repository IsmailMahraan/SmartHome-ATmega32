/*
 * MTWI_Program.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Ismail
 */

#include"../../LIB/STD_TYPE.h"
#include"../../LIB/BIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include"MTWI_Private.h"
#include"MTWI_Config.h"
#include"MTWI_Interface.h"
#include<util\delay.h>


TWI_ErrorState MTWI_MasterInit(u8 Copy_u8SelfSlaveAddress){
	CLR_BIT(TWCR,2);
	TWI_ErrorState ReturnErrorState=NoError;
	//SET_BIT(TWCR,6);
	/*set interrupt mode*/
#if MTWI_INTERUPT_MODE==MTWI_INTERUPT_DISABLED
	CLR_BIT(TWCR,0);

#elif MTWI_INTERUPT_MODE==MTWI_INTERUPT_ENABLED
	SET_BIT(TWCR,0);
#else
#error "Wrong Interrupt Mode Chosen"
#endif
	/*SET BIT RATE OF TWI BUS*/
	/*1-WRITE ON TWSR(1,0)
	 *
	 */
#if MTWI_PRESCALER_MODE==MTWI_PRESCALER_BY_1
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
#elif MTWI_PRESCALER_MODE==MTWI_PRESCALER_BY_4
	SET_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
#elif MTWI_PRESCALER_MODE==MTWI_PRESCALER_BY_16
	CLR_BIT(TWSR,0);
	SET_BIT(TWSR,1);
#elif MTWI_PRESCALER_MODE==MTWI_PRESCALER_BY_64
	SET_BIT(TWSR,0);
	SET_BIT(TWSR,1);
#else
#error "Wrong prescaler Mode Chosen"
#endif
	/*WRITE THE VALUE AT TWBR*/
	TWBR = 12;           // to make Fscl = 400 Khz
	if(Copy_u8SelfSlaveAddress!=0){
		TWAR&=MTWI_TWAR_ADD_MASK;
		TWAR|=(Copy_u8SelfSlaveAddress<<1);
	}
	else{
		ReturnErrorState=WrongAddressPassed;

	}
	/*ENABLE THE TWI*/
	SET_BIT(TWCR,2);
	_delay_ms(10);
	return ReturnErrorState;


}
TWI_ErrorState MTWI_SlaveInit(u8 Copy_u8SelfSlaveAddress){

	TWI_ErrorState ReturnErrorState=NoError;
	/*Enable the ACK [TWEA]*/
		SET_BIT(TWCR,6);

		/*Set Interrupt Mode*/
	#if MTWI_INTERRUPT_MODE==MTWI_INTERRUPT_DISABLED
		CLR_BIT(TWCR,0);
	#elif MTWI_INTERRUPT_MODE==MTWI_INTERRUPT_ENABLED
		SET_BIT(TWCR,0);
	#else
	#error"Wrong Interrupt Mode chosen"
	#endif

		if(Copy_u8SelfSlaveAddress!=0){
				TWAR&=MTWI_TWAR_ADD_MASK;
				TWAR|=(Copy_u8SelfSlaveAddress<<1);
			}
			else{
				ReturnErrorState=WrongAddressPassed;

			}

		/*enable the TWI*/
		SET_BIT(TWCR,2);
		return ReturnErrorState;
		_delay_ms(10);
}

TWI_ErrorState MTWI_SendStartCondition(){
	TWI_ErrorState ReturnErrorState;
	/*send start condition*/

	SET_BIT(TWCR,5);
	//CLEAR THE TWINT FLAG SO THE TWI PERFORM THE LAST ORDERED OPERATION//
	SET_BIT(TWCR,7);
	//WAIT ON FLAG TO BE HIGH//
	while(GET_BIT(TWCR,7)==0);
	//CHECK TWSR
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_START_COND_ACK){
		ReturnErrorState=StartConditionFailed;
	}
	else{
		ReturnErrorState=NoError;
	}
	_delay_ms(10);
	return ReturnErrorState;


}
TWI_ErrorState MTWI_SendSlaveAddress_WithWrite(u8 Copy_u8SlaveAddress){

	TWI_ErrorState ReturnErrorState=NoError;
	u8 Local_u8SlaveAddress=Copy_u8SlaveAddress;
	/*clear the TWISTA BIT*/
	//CLR_BIT(TWCR,5);
	/*SHIFT THE ADDRESS SENT ONE BIT TO THE LEFT*/
	TWDR=Local_u8SlaveAddress<<1;
	/*CLEAR THE TWINT FLAG*/
	SET_BIT(TWCR,7);
	/*WAIT ON THE FLAG TILL THE OPERATION IS COMPLETED*/
	while(GET_BIT(TWCR,7)==0);
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_SLAVE_ADD_WR_ACK){
			ReturnErrorState=SlaveAddressWithWriteFailed;
		}
		else{
			ReturnErrorState=NoError;
		}
		_delay_ms(10);
		return ReturnErrorState;



}
TWI_ErrorState MTWI_SendSlaveAddress_WithRead(u8 Copy_u8SlaveAddress){
	TWI_ErrorState ReturnErrorState=NoError;
	u8 Local_u8SlaveAddress=Copy_u8SlaveAddress;
	/*clear the TWISTA BIT*/
	//CLR_BIT(TWCR,5);
	/*SHIFT THE ADDRESS SENT ONE BIT TO THE LEFT and add a (1) to the local varible to indicate
	 * a read request*/
	Local_u8SlaveAddress=(Local_u8SlaveAddress<<1)|1;
	TWDR=Local_u8SlaveAddress;


	/*CLEAR THE TWINT FLAG*/
	SET_BIT(TWCR,7);
	/*WAIT ON THE FLAG TILL THE OPERATION IS COMPLETED*/
	while(GET_BIT(TWCR,7)==0);
	if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_SLAVE_ADD_R_ACK){
			ReturnErrorState=SlaveAddressWithReadFailed;
		}
		else{
			ReturnErrorState=NoError;
		}
	_delay_ms(10);
		return ReturnErrorState;


}
TWI_ErrorState MTWI_MasterSlaveWriteData(u8 Copy_u8DataToWrite){

	TWI_ErrorState ReturnErrorState=NoError;


		TWDR=Copy_u8DataToWrite;
		CLR_BIT(TWCR,5);
		/*CLEAR THE TWINT FLAG*/
		SET_BIT(TWCR,7);
		/*WAIT ON THE FLAG TILL THE OPERATION IS COMPLETED*/
		while(GET_BIT(TWCR,7)==0);
		_delay_ms(100);
		if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_DATA_SENT_ACK){
				ReturnErrorState=SendingDataFailed;
			}
			else{
				ReturnErrorState=NoError;
			}
		_delay_ms(100);
			return ReturnErrorState;


}
TWI_ErrorState MTWI_MasterSlaveReadData(u8* Ptr_u8DataToRead){


	TWI_ErrorState ReturnErrorState=NoError;

		/*CLEAR THE TWINT FLAG*/
			TWCR = (1<<7)|(1<<2)|(1<<6);
			//SET_BIT(TWCR,7);
			/*WAIT ON THE FLAG TILL THE OPERATION IS COMPLETED*/
			while(GET_BIT(TWCR,7)==0);
			_delay_ms(100);
			if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_DATA_RECIEVED_ACK){
					ReturnErrorState=ReadingDataFailed;
				}
				else{
					*Ptr_u8DataToRead=TWDR;
					ReturnErrorState=NoError;
				}
			    *Ptr_u8DataToRead=TWDR;
			    _delay_ms(100);
				return ReturnErrorState;

}
TWI_ErrorState MTWI_SendStopCondition(){

	TWI_ErrorState ReturnErrorState;
		/*send stop condition*/

		SET_BIT(TWCR,4);
		//CLEAR THE TWINT FLAG SO THE TWI PERFORM THE LAST ORDERED OPERATION//
		SET_BIT(TWCR,7);
		//WAIT ON FLAG TO BE HIGH//
		while(GET_BIT(TWCR,7)==0);
		//CHECK TWSR
		if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_STOP_COND_ACK){
			ReturnErrorState=StopConditionFailed;
		}
		else{
			ReturnErrorState=NoError;
		}
		_delay_ms(10);
		return ReturnErrorState;

}
TWI_ErrorState MTWI_SendRepeatedStartCondition()
{
	u8 ReturnedErrorState=NoError;
		//Send Start condition
		//Note:In the Next Operation you should Clear it by Software
		SET_BIT(TWCR,5);

		//Clear the TWINT Flag So TWI Performs the last ordered operation
		SET_BIT(TWCR,7);

		//Wait On FLag to be High
		while(GET_BIT(TWCR,7)==0);

		//Check Status Code
		if((TWSR&MTWI_TWSR_STATUSCODE_MASK)!=MTWI_STATUS_CODE_REPEATEDSTART_COND_ACK)
		{
			//Repeated Start Condition Error Happens
			ReturnedErrorState=StartConditionFailed;
		}
		else
		{
			//Repeated Start Condition Sent Successfully
			ReturnedErrorState=NoError;
		}
		return ReturnedErrorState;

}
u8 MTWI_ReadByteNoAck(){

	TWCR = (1<<7)|(1<<2);
		while(GET_BIT(TWCR,7) == 0);
		return TWDR;
}


/*low 3awez tefkes kol ely fo2 fel init asta3mel al function de hatengez el init */
void I2C_Init(void){
	CLR_BIT(TWCR,2);
	TWBR = 12;           // to make Fscl = 400 Khz
	SET_BIT(TWCR,2);    // to enable i2c circuit
		_delay_ms(10);

}
