/*
 * MTWI_Interface.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MTWI_MTWI_INTERFACE_H_
#define MCAL_MTWI_MTWI_INTERFACE_H_
#include "MTWI_Private.h"

TWI_ErrorState MTWI_MasterInit(u8 Copy_u8SelfSlaveAddress);
TWI_ErrorState MTWI_SlaveInit(u8 Copy_u8SelfSlaveAddress);
TWI_ErrorState MTWI_SendStartCondition();
TWI_ErrorState MTWI_SendSlaveAddress_WithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorState MTWI_SendSlaveAddress_WithRead(u8 Copy_u8SlaveAddress);
TWI_ErrorState MTWI_MasterSlaveWriteData(u8 Copy_u8DataToWrite);
TWI_ErrorState MTWI_MasterSlaveReadData(u8* Ptr_u8DataToRead);
TWI_ErrorState MTWI_SendStopCondition();
TWI_ErrorState MTWI_SendRepeatedStartCondition();
u8 MTWI_ReadByteNoAck();
void I2C_Init(void);

#endif /* MCAL_MTWI_MTWI_INTERFACE_H_ */
