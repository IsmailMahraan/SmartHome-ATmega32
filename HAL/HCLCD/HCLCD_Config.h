/*
 * HCLCD_Config.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Ismail
 */

#ifndef HAL_HCLCD_HCLCD_CONFIG_H_
#define HAL_HCLCD_HCLCD_CONFIG_H_
#include "HCLCD_Private.h"


/* FUNCTION_SET_4BIT_MODE_2LINE_5BY8_SIZE  0010 1000
* FUNCTION_SET_4BIT_MODE_2LINE_5BY11_SIZE  0010 1100
* FUNCTION_SET_4BIT_MODE_1LINE_5BY8_SIZE  0010 0000
* FUNCTION_SET_4BIT_MODE_1LINE_5BY11_SIZE 0010 0100
 */
#define FUNCTION_SET_MODE_COMMAND FUNCTION_SET_4BIT_MODE_2LINE_5BY8_SIZE

/*Options For Function Set Command
 *1-DISPALY_OFF  0b00001000
 *2-DISPALY_ON  0b00001100
 *3-DISPALY_ON_CURSOR_ON 0b00001111
 *4-DISPALY_ON_CURSOR_BLINKING_ON  0b00001111
 */
#define DISPALY_ON_OFF_COMMAND DISPALY_ON_CURSOR_BLINKING_ON

/*options for EntryMode
 *1-ENTRY_MODE_INCREASE_NO_SHIFT  0b00000110
 *2-ENTRY_MODE_INCREASE_WITH_SHIFT  0b00000111
 *3-ENTRY_MODE_DECREASE_NO_SHIFT    0b00000100
 *4-ENTRY_MODE_DECREASE_WITH_SHIFT 0b00000101
 */
#define ENTRY_MODE_COMMAND    ENTRY_MODE_INCREASE_NO_SHIFT


#endif /* HAL_HCLCD_HCLCD_CONFIG_H_ */