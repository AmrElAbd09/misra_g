/*
 * Ext_interrupt.h
 *
 * Created: 4/8/2023 8:29:27 PM
 *  Author: Amr
 */ 


#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "../DIO/DIO.h"


/*************************************************/
//					MACROS
/**************************************************/



#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3


#define sei() __asm__ __volatile__("sei" ::: "memory")
#define cli() __asm__ __volatile__("cli" ::: "memory")

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


// MCUCR PINS FOR SENSE SELECTION OF INT0 , INT 1
#define	ISC00				0		 // INT0
#define	ISC01				1		 // INT0
#define	ISC10				2		 // INT1 
#define	ISC11				3		 // INT1

	
// MCUCSR PINS
#define ISC2				6		 // INT2

		
// GICR SELCTION INTERRUPT PINS
#define INT_2				5
#define INT_0				6
#define INT_1				7


// ENABLE / DISABLE INTERRUPT
#define DISABLE				1
#define ENABLE 				2
	
	
// INTERRUPT SENSE 	
#define LOW_LEVEL 			1
#define ANY_LOGIC			2
#define FALLING_EDGE 		3
#define RAISING_EDGE 		4




//ERROR  TYPES
typedef enum {
	WRONG_SENSE_MODE,
	INT_ENABLE_ERROR,
	NULL_POINTE,
	EXT_INT_OK
	}Ext_intErrorStatus;

/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
Ext_intErrorStatus ExtInt_init();
Ext_intErrorStatus INT0_SetCallback(void(*callback)(void));
Ext_intErrorStatus INT1_SetCallback(void(*callback)(void));
Ext_intErrorStatus INT2_SetCallback(void(*callback)(void));


#endif /* EXT_INTERRUPT_H_ */