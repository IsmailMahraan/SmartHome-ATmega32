/*
 * HEEPROM_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Ismail
 */
#include"../../LIB/STD_TYPE.h"
#include"../../LIB/BIT_MATH.h"
#include "HEEPROM_Interface.h"
#include "HEEPROM_Private.h"
#include <util/delay.h>
#include "../../MCAL/MTWI/MTWI_Interface.h"

u8 HEEPROM_ReadByte(u8 Copy_u8BlockNo, u8 Copy_u8ByteAddress)
{
	u8 Loc_ReturnedValue;
		u8 Loc_u8SlaveAdd;

		Loc_u8SlaveAdd=HEEPROM_FIXED_SLAVE_ADDRESS|(Copy_u8BlockNo);

		/*Send Start Condition*/
		MTWI_SendStartCondition();

		MTWI_SendSlaveAddress_WithWrite(Loc_u8SlaveAdd);

		/*Send the Remainder Byte Address as a Data Byte */
		MTWI_MasterSlaveWriteData(Copy_u8ByteAddress);

		/*Send Repeated Start*/
		MTWI_SendRepeatedStartCondition();

		/*Send Slave Address with Read*/
		/*Same Slave Address Adjusted before
		 * But with changing the LSB from 0==> 1
		 * to signal Read Request
		 */

		/*No Need to Add one as LSB Because Next Function does this*/
		//Loc_u8SlaveAdd|=0x01;

		/*Send Slave Address with Read */
		MTWI_SendSlaveAddress_WithRead(Loc_u8SlaveAdd);

		/*Read Data */
		Loc_ReturnedValue=MTWI_ReadByteNoAck();

		MTWI_SendStopCondition();

		return Loc_ReturnedValue;
}


void HEEPROM_WriteByte(u8 Copy_u8Data,BlockNumber Copy_u8BlockNo,u8 Copy_u8ByteAddress){
	u8 Loc_u8SlaveAdd;

		Loc_u8SlaveAdd=HEEPROM_FIXED_SLAVE_ADDRESS|(Copy_u8BlockNo);

		/*Send Start Condition*/
		MTWI_SendStartCondition();


		MTWI_SendSlaveAddress_WithWrite(Loc_u8SlaveAdd);

		/*Send the Remainder Byte Address as a Data Byte */
		MTWI_MasterSlaveWriteData(Copy_u8ByteAddress);

		/*Send The real data needed to be saved at the previous Address*/
		MTWI_MasterSlaveWriteData(Copy_u8Data);

		/*Send Stop Condition*/
		MTWI_SendStopCondition();

		/*Delay until Write Cycle Finishes*/
		_delay_ms(100);

}
