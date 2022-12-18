/*
 * MSPI_Private.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_

#define SPCR  *((volatile u8*)0x2D)
#define SPSR  *((volatile u8*)0x2E)
#define SPDR  *((volatile u8*)0x2F)

/*OPTIONS FOR MSPI_MODE*/
#define MSPI_MASTER_MODE  0
#define MSPI_SLAVE_MODE   1
/*OPTIONS FOR INTRUUPT*/
#define MSPI_INTERRUPT_MODE_ENABLED   0
#define MSPI_INTERRUPT_MODE_DISABLED   1
/*OPTIONS FOR POLARITY*/
#define MSPI_POL_ACTIVE_HIGH         1
#define MSPI_POL_ACTIVE_LOW          0


/*OPTIONS FOR PHASE*/
#define MSPI_PHASE_SAMPLE_AT_LEADING     0
#define MSPI_PHASE_SAMPLE_AT_TRAILLING   1
/*OPTIONS FOR DATA ORDER*/
#define MSPI_DORD_MSB_FIRST                    0
#define MSPI_DORD_LSB_FIRST                    1
/*OPTIONS FOR DOUBLESPEED CLK OFF (SPI2X) IS LOW*/
#define MSPI_CLOCK_FCPU_4                      0
#define MSPI_CLOCK_FCPU_16                     1
#define MSPI_CLOCK_FCPU_64                     2
#define MSPI_CLOCK_FCPU_128                    3


/*OPTIONS FOR DOUBLE SPEED CLK ON* WHEN (SPI2X) IS HIGH*/
#define MSPI_DCLOCK_FCPU_2                     0
#define MSPI_DCLOCK_FCPU_8                     1
#define MSPI_DCLOCK_FCPU_32                    2
#define MSPI_DCLOCK_FCPU_64                    3


#define MSPI_CLOCK_MODE_DOUBLE_SPEED_ON        0
#define MSPI_CLOCK_MODE_DOUBLE_SPEED_OFF       1
#define CLOCK_MASK                             0b00000011

#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
