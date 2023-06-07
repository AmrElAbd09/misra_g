/*
 * timer.c
 *
 * Created: 4/10/2023 8:56:06 AM
 *  Author: Amr
 */ 
#include "timer.h"

double g_ovf_num ,g_tick;
	
enu_timer_error_status_t timer_0_init(enu_timer_mode_t mode){
	enu_timer_error_status_t enu_timer_error_status = TIMER_OK;
	if (mode > PWM_PHASE_CORRECT)
	{
		enu_timer_error_status = INVALID_MODE;
	}
	else
	{
		switch(mode){
			
			case NORMAL_MODE :
			{
				CLR_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);
			}
			break;
			
			case PWM_PHASE_CORRECT :
			{
				SET_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);
			}
			break;
			
			case CTC :
			{
				CLR_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
			}
			break;
			
			
			case FAST_PWM :
			{
				SET_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
			}
			break;
			
			default:
			{
				enu_timer_error_status = INVALID_MODE ;
			}
			break;
		}
	}	
	return enu_timer_error_status;
}

enu_timer_error_status_t timer_0_start(enu_timer_prescaler_t prescaler){
	enu_timer_error_status_t enu_timer_error_status = TIMER_OK;
	
	if (prescaler > PRECALER_1024)
	{
		enu_timer_error_status = INVALID_PRESCALER;
	}
	else
	{
		switch(prescaler){
			
			case PRECALER_1 :
			{
				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
			}
			break;
			
			case PRECALER_8 :
			{
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS02);
			}
			break;
			
			case PRECALER_64 :
			{
				SET_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
			}
			break;
			
			case PRECALER_256 :
			{
				SET_BIT(TCCR0,CS02);
				CLR_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS00);
			}
			break;
			
			case PRECALER_1024 :
			{
				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
			}
			break;
			
			default:
			{
				enu_timer_error_status= INVALID_PRESCALER;
			}
			break;
		}
	}	
	return enu_timer_error_status ;
}

void timer_0_stop(void){
	
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);

}


enu_timer_error_status_t timer_0_initial_value(uint8_t value){
	enu_timer_error_status_t enu_timer_error_status = TIMER_OK;

	if(value < TIMR0_MAX_VALUE && value >= 0)
	{	
		TCNT0 = value ;
	}
	else
	{
		enu_timer_error_status = INVALID_VALUE;
	}
	return enu_timer_error_status ;
}


enu_timer_error_status_t timer_0_ovf_num(double a_overflow){
	enu_timer_error_status_t enu_timer_error_status = TIMER_OK;
	double num_ovf = 0;
	if (a_overflow > 0)
	{
		
		while(num_ovf < a_overflow){
			
			while(GET_BIT(TIFR,TOV0)==0);
			SET_BIT(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}
	else if (a_overflow <= 0)
	{
		a_overflow = 1 ;
		while(num_ovf < a_overflow){
			
			while(GET_BIT(TIFR,TOV0)==0);
			SET_BIT(TIFR,TOV0);
			num_ovf++;
		}
		num_ovf = 0;
	}
		
	else
	{
		enu_timer_error_status = INVALID_OVF;
	}
	
	return enu_timer_error_status;
}

void timer_0_delay_ms(double a_time_ms){
	 g_tick = a_time_ms/1000 ;
	g_ovf_num = ceil (g_tick / 0.000256) ;
	timer_0_init(NORMAL_MODE);
	timer_0_initial_value(0);
	timer_0_start(PRECALER_1);
	timer_0_ovf_num(g_ovf_num);	
}
