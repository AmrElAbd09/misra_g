/*
 * timer.c
 *
 * Created: 10-Apr-23 4:49:08 PM
 *  Author: Amr
 */ 


#include "timer.h"
#include <math.h>

double ovfNum  ;
double t ;

EN_error_t timer_init(EN_timerModes mode)
{
	switch(mode)
	{
		case normal:
		{
			RESET_BIT(TCCR0,WGM00);
			RESET_BIT(TCCR0,WGM01);
		}
		break;
		case PWM_phaseCorrect:
		{
			SET_BIT(TCCR0,WGM00);
			RESET_BIT(TCCR0,WGM01);
		}	
		break;
		case CTC:
		{
			RESET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		}
		break;
		case fastPWM:
		{
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		}
		break;
		default:
		{
			
		}
	}
return valid;
}

void Timer_initialValue(uint8_t timerInitValue)
{
	TCNT0 = timerInitValue;
}

EN_error_t timer_start(EN_clockSelect clkSelection)
{
	switch(clkSelection)
	{
		case NoClock:
		RESET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
		break;
		case NoPrescaling:
		SET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
		break;
		case Prescale_8:
		RESET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
		break;
		case Prescale_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		RESET_BIT(TCCR0,CS02);
		break;
		case Prescale_256:
		RESET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case Prescale_1024:
		SET_BIT(TCCR0,CS00);
		RESET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case ExternalFallingEdge:
		RESET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
		case ExternalRisingEdge:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	}
	return valid;
}

void timer_reset()
{
	TCCR0 &= 0x00;
	RESET_BIT(TIFR, 0);
	TCNT0 = 0;
}

EN_error_t TIMER_0_OvfNum(double overflow){
	double num_ovf = 0;
	if (overflow > 0)
	{	
		while(num_ovf < overflow){
			while(READ_BIT(TIFR,TOV0)==0);
			SET_BIT(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}else if (overflow <= 0)
	{
		overflow = 1 ;
		while(num_ovf<overflow){
			
			while(READ_BIT(TIFR,TOV0)==0);
			SET_BIT(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}
	return valid;
	}


void TIMER_0_DELAY_MS(double time_ms){
	t = time_ms/1000 ;
	ovfNum = ceil (t / 0.000256) ;
	timer_init(normal);
	Timer_initialValue(0);
	timer_start(NoPrescaling);
	TIMER_0_OvfNum(ovfNum);
	
}