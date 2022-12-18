/*
 * MTIMER2_Interface.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MTIMER2_MTIMER2_INTERFACE_H_
#define MCAL_MTIMER2_MTIMER2_INTERFACE_H_
#include"MTIMER2_Config.h"
#include"MTIMER2_Private.h"
#include"../../LIB/STD_TYPE.h"
#include"../../LIB/BIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include"../MGIE/MGIE_Interface.h"




void MTimer2Init();

void MTimer2SetTimer(u32 Local_u32_DesiredTime);

void MTimer2Start();

void MTimer2Stop();

void MPWM2Init();

void MPWM2SetDutyCycle(u8 Local_u8_DesiredDutyCycle);

void MPWM2Start();

void MPWM2Stop();

void MTimer2SetCallBack (void (*Local_void_ptr) (void));


#endif /* MCAL_MTIMER2_MTIMER2_INTERFACE_H_ */
