/*
 * registers.h
 *
 * Created: 05-Apr-23 11:17:31 PM
 *  Author: Zerconium
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Types.h"
/*****************************************************************************************************************************************************************
*																		Registers macros																		 *
******************************************************************************************************************************************************************/
//Port A registers
#define PORTA	(*((volatile uint8_t *)(0x3B)))
#define DDRA	(*((volatile uint8_t *)(0x3A)))
#define PINA	(*((volatile uint8_t *)(0x39)))
//Port B registers
#define PORTB	(*((volatile uint8_t *)(0x38)))
#define DDRB	(*((volatile uint8_t *)(0x37)))
#define PINB	(*((volatile uint8_t *)(0x36)))
//Port C registers
#define PORTC	(*((volatile uint8_t *)(0x35)))
#define DDRC	(*((volatile uint8_t *)(0x34)))
#define PINC	(*((volatile uint8_t *)(0x33)))
//Port D registers
#define PORTD	(*((volatile uint8_t *)(0x32)))
#define DDRD	(*((volatile uint8_t *)(0x31)))
#define PIND	(*((volatile uint8_t *)(0x30)))

//interrupt registers
#define MCUCR	(*((volatile uint8_t *)(0x55)))
#define MCUCSR	(*((volatile uint8_t *)(0x54)))
#define GICR	(*((volatile uint8_t *)(0x5B)))

//timer registers
#define TCNT0   (*((volatile uint8_t *)(0x52)))
#define TCCR0   (*((volatile uint8_t *)(0x53)))
#define TIMSK   (*((volatile uint8_t *)(0x59)))
#define GIFR    (*((volatile uint8_t *)(0x5A)))
#define TIFR    (*((volatile uint8_t *)(0x58)))
#define OCR0    (*((volatile uint8_t *)(0x5C)))





#endif /* REGISTERS_H_ */