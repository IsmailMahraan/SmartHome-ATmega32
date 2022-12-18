/*
 * HLM35_Program.c
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#include "HLM35_Interface.h"
//the used pin is adc channel 0
void HLM35Init()
{
MADC_Init();
}
void  HLM35Read(u16* PtrTou16_Data)
{
	u16 Local_u16ADCReading	=	MADC_StartConversion(MADC_CHANNEL_0);
	u16 Local_u16Temp			=	(((u32)Local_u16ADCReading * 500)/1023);
	*PtrTou16_Data = Local_u16Temp;

}
