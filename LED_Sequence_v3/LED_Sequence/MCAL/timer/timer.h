/*
 * timer.h
 *
 * Created: 10-Apr-23 4:49:24 PM
 *  Author: Zerconium
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/Types.h"
#include "../../Utilities/manu.h"
#include "../../Utilities/registers.h"

/*************************************************************************************************************************
*														Macros															 *
**************************************************************************************************************************/
//TCCR0
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
//TIMSK
#define TOIE0 0
#define OCIE0 1
//TIFR
#define TOV0 0
#define OCF0 1
/*************************************************************************************************************************
*														Typedefs														 *
**************************************************************************************************************************/
typedef enum {
	normal,
	PWM_phaseCorrect,
	fastPWM,
	CTC	
	}EN_timerModes;

typedef enum{
	valid,
	invalid
	}EN_error_t;
	
typedef enum{
	NoClock,         
	NoPrescaling, 
	Prescale_8,    
	Prescale_64,
	Prescale_256,
	Prescale_1024,
	ExternalFallingEdge,
	ExternalRisingEdge
	}EN_clockSelect;
		
/*************************************************************************************************************************
*														Functions declarations											 *
**************************************************************************************************************************/
EN_error_t timer_init(EN_timerModes mode);
void Timer_initialValue(uint8_t timerInitValue);
EN_error_t timer_start(EN_clockSelect clkSelection);
void timer_reset();
EN_error_t TIMER_0_OvfNum(double overflow);
void TIMER_0_DELAY_MS(double _delay);


#endif /* TIMER_H_ */