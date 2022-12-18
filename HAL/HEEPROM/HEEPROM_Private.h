/*
 * HEEPROM_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Ismail
 */

#ifndef HAL_HEEPROM_HEEPROM_PRIVATE_H_
#define HAL_HEEPROM_HEEPROM_PRIVATE_H_

typedef enum{
	Block0,
	Block1,
	Block2,
	Block3,
	Block4,
	Block5,
	Block6,
	Block7

}BlockNumber;
#define HEEPROM_FIXED_SLAVE_ADDRESS 0b01010000

#endif /* HAL_HEEPROM_HEEPROM_PRIVATE_H_ */
