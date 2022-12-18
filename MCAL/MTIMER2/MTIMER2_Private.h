/*
 * MTIMER2_Private.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Ismail
 */

#ifndef MCAL_MTIMER2_MTIMER2_PRIVATE_H_
#define MCAL_MTIMER2_MTIMER2_PRIVATE_H_


#define TCCR2		(*(volatile u8*)0x45)
#define FOC2		7
#define WGM20		6
#define COM21		5
#define	COM20		4
#define WGM21		3
#define CS22		2
#define	CS21		1
#define	CS20		0
#define TIMSK		(*(volatile u8*)0x59)
#define OCIE2		7
#define TOIE2		6
#define TICIE1		5
#define	OCIE1A		4
#define OCIE1B		3
#define TOIE1		2
#define	OCIE0		1
#define	TOIE0		0

#define TCNT0		(*(volatile u8*)0x52)

#define OCR0		(*(volatile u8*)0x5C)


#define TCNT2		(*(volatile u8*)0x44)

#define OCR2		(*(volatile u8*)0x43)

#define NO_CLK									0
#define PRESCALER_1								1
#define PRESCALER_8								8
#define PRESCALER_64							64
#define PRESCALER_256							256
#define PRESCALER_1024							1024
#define CLK_FALLING_EDGE						0
#define CLK_RISING_EDGE							1

#define NORMAL									0
#define CTC										1

#define FAST_PWM								0
#define PHASE_CORRECT							1

#define NON_INVERTED							0
#define INVERTED								1




#endif /* MCAL_MTIMER2_MTIMER2_PRIVATE_H_ */
