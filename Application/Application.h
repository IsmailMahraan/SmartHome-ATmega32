/*
 * Application.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Ismail
 */

#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

#include <util/delay.h>
#include"../HAL/HDimmer/Dimmer_Interface.h"
#include "../HAL/HsevenSegment/HSevenSegment_Interface.h"
#include "../HAL/HCLCD/HCLCD_Interface.h"
#include "../HAL/HDCMotor/HDC_Motor_Interface.h"
#include "../HAL/HKPD/HKPD_Interface.h"
#include "../HAL/HBUZZER/HBUZZER_Interface.h"
#include "../HAL/HEEPROM/HEEPROM_Interface.h"
#include "../HAL/HHC05/HC05_Interface.h"
#include "../HAL/HLED/HLED_Interface.h"
#include "../HAL/HLM35/HLM35_Interface.h"
#include "../HAL/HRELAY/HRELAY_Interface.h"
#include "../HAL/HServoMotor/HServoMotor_Interface.h"
#include "../HAL/HPushButton/HPushButton_Interface.h"
#include "../MCAL/MTWI/MTWI_Private.h"
#include "../MCAL/MTWI/MTWI_Interface.h"


#define FIRSTPAGE			'0'
#define ADMINLOGINPAGE    '1'
#define USERLOGINPAGE     '2'
#define WELCOME  			 0
#define ADMINSECONDPAGE      1
#define USERSECONDPAGE       2
#define IDLE_STATE			 5
#define ADMINMODE			 8
#define USERMODE			 9
#define IDLENGTH             3
#define PASSWORDLENGTH       4
#define MAXTEMPERATURE      26
#define MINTEMPERATURE      21
#define MAXTRIALS           3

void InputID(u8* ID, u8 UserMode);
void InputPassword(u8* Password, u8 UserMode);
u8 AdminLogin(u8* ID, u8* Password);
u8 UserLogin( u8* ID, u8* Password);
void AddUser(u8* ID, u8* Password);
void DeleteUser(u8 NumberOfUsers, u8* ID);
void CheckEEPROM(void);
void DeleteAll(void);
void ACSwitch(u8* ACState);
void DoorSwitch(u8* DoorState);
void RelaySwitch(u8* RelayState);
void CloseTheDoor(void);
void Door(u8 DoorState);
void AC(u8 ACState);
void Relay(u8 RelayState);
void AppInit(void);
void Welcoming(void);
void Reset(u8* ACState, u8* DoorState, u8* RelayState);




#endif /* APPLICATION_APPLICATION_H_ */
