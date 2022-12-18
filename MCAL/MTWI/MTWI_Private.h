/*
 * MTWI_Private.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MTWI_MTWI_PRIVATE_H_
#define MCAL_MTWI_MTWI_PRIVATE_H_

#define TWDR  *((volatile u8*)0x23)
#define TWAR  *((volatile u8*)0x22)
#define TWSR  *((volatile u8*)0x21)
#define TWBR  *((volatile u8*)0x20)
#define TWCR  *((volatile u8*)0x56)

#define MTWI_INTERUPT_DISABLED  0
#define MTWI_INTERUPT_ENABLED   1

#define MTWI_PRESCALER_BY_1   0
#define MTWI_PRESCALER_BY_4   1
#define MTWI_PRESCALER_BY_16  2
#define MTWI_PRESCALER_BY_64  3
#define MTWI_TWAR_ADD_MASK    0x01
#define MTWI_TWSR_STATUSCODE_MASK    0xF8
/*status codes*/

#define MTWI_STATUS_CODE_START_COND_ACK          0x08
#define MTWI_STATUS_CODE_REPEATEDSTART_COND_ACK  0x10
#define MTWI_STATUS_CODE_SLAVE_ADD_WR_ACK        0x18
#define MTWI_STATUS_CODE_DATA_SENT_ACK           0x28
#define MTWI_STATUS_CODE_SLAVE_ADD_R_ACK         0x40
#define MTWI_STATUS_CODE_DATA_RECIEVED_ACK       0x50
#define MTWI_STATUS_CODE_STOP_COND_ACK           0xA0



#define GENERALCALL 0B0000000

typedef enum
{
	NoError,
WrongAddressPassed,
StartConditionFailed,
RepeatedStartConditionFailed,
SlaveAddressWithWriteFailed,
SlaveAddressWithReadFailed,
SendingDataFailed,
RecevingDataFailed,
ReadingDataFailed,
StopConditionFailed



}TWI_ErrorState;

#endif /* MCAL_MTWI_MTWI_PRIVATE_H_ */
