/*
 * MSPI_Program.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ismail
 */
#include"../../LIB/STD_TYPE.h"
#include"../../LIB/BIT_MATH.h"
#include"../MDIO/MDIO_Interface.h"
#include"MSPI_Private.h"
#include"MSPI_Config.h"

void MSPI_MasterInit()
{
	//Set Data Order
#if MSPI_DORD_MODE==MSPI_DORD_MSB_FIRST
	CLR_BIT(SPCR,5);
#elif MSPI_DORD_MODE==MSPI_DORD_LSB_FIRST
	SET_BIT(SPCR,5);
#endif

	//Set Clock Polarity
#if MSPI_POLARITY_MODE==MSPI_POL_ACTIVE_HIGH
	CLR_BIT(SPCR,3);
#elif MSPI_POLARITY_MODE==MSPI_POL_ACTIVE_LOW
	SET_BIT(SPCR,3);
#endif

	//Set Clock Phase
#if MSPI_PHASE_MODE==MSPI_PHASE_SAMPLE_AT_LEADING
	CLR_BIT(SPCR,2);
#elif MSPI_PHASE_MODE==MSPI_PHASE_SAMPLE_AT_TRAILING
	SET_BIT(SPCR,2);
#endif

	//Set Interrupt Mode
#if MSPI_INTERRUPT_MODE==MSPI_INTERRUPT_OFF
	CLR_BIT(SPCR,7);
#elif MSPI_INTERRUPT_MODE==MSPI_INTERRUPT_ON
	SET_BIT(SPCR,7);
#endif

//Set Clock

//Set Double Speed Bit Mode
#if MSPI_DOUBLE_SPEED_MODE==MSPI_DOUBLE_SPEED_OFF
	CLR_BIT(SPSR,0);
#elif MSPI_DOUBLE_SPEED_MODE==MSPI_DOUBLE_SPEED_ON
	SET_BIT(SPSR,0);
#endif

	//Set Clock in SPSR
	//SPCR|=(MSPI_CLOCK_MODE&CLOCK_MASK);
	//CLR_BIT(SPCR,0);
	//CLR_BIT(SPCR,1);
	SPCR&=(~CLOCK_MASK);
	SPCR|=MSPI_CLOCK_MODE;

	//Set Mode as Master
	SET_BIT(SPCR,4);

	//Enable SPI
	SET_BIT(SPCR,6);

}
void MSPI_SlaveInit()
{
	//Set Data Order
#if MSPI_DORD_MODE==MSPI_DORD_MSB_FIRST
	CLR_BIT(SPCR,5);
#elif MSPI_DORD_MODE==MSPI_DORD_LSB_FIRST
	SET_BIT(SPCR,5);
#endif

	//Set Clock Polarity
#if MSPI_POLARITY_MODE==MSPI_POL_ACTIVE_HIGH
	CLR_BIT(SPCR,3);
#elif MSPI_POLARITY_MODE==MSPI_POL_ACTIVE_LOW
	SET_BIT(SPCR,3);
#endif

	//Set Clock Phase
#if MSPI_PHASE_MODE==MSPI_PHASE_SAMPLE_AT_LEADING
	CLR_BIT(SPCR,2);
#elif MSPI_PHASE_MODE==MSPI_PHASE_SAMPLE_AT_TRAILING
	SET_BIT(SPCR,2);
#endif

	//Set Interrupt Mode
#if MSPI_INTERRUPT_MODE==MSPI_INTERRUPT_OFF
	CLR_BIT(SPCR,7);
#elif MSPI_INTERRUPT_MODE==MSPI_INTERRUPT_ON
	SET_BIT(SPCR,7);
#endif

	//Set Mode as Slave
	CLR_BIT(SPCR,4);

	//Enable SPI
	SET_BIT(SPCR,6);
}

u8 MSPI_SendReceive(u8 Copy_u8TransmittedValue)
{
	//Put Data in SPDR
	SPDR=Copy_u8TransmittedValue;
	//Poll On SPIF Flag
	while(GET_BIT(SPSR,7)==0);
	return SPDR;
}
