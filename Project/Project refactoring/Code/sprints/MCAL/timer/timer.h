/*
 * timer.h
 *
 * Created: 4/10/2023 8:55:51 AM
 *  Author: Amr
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"


#define CS00				0
#define CS01				1
#define CS02				2
#define WGM01				3
#define WGM00				6

#define TOV0				0

#define TIMR0_MAX_VALUE		256


typedef enum {
	INVALID_PRESCALER,
	INVALID_MODE,
	INVALID_OVF,
	INVALID_VALUE,
	TIMER_OK
	}enu_timer_error_status_t;

typedef enum {
	NORMAL_MODE,
	FAST_PWM,
	CTC,
	PWM_PHASE_CORRECT
	}enu_timer_mode_t;
	
typedef enum{
	PRECALER_1,
	PRECALER_8,
	PRECALER_64,
	PRECALER_256,
	PRECALER_1024,
	}enu_timer_prescaler_t;

extern enu_timer_error_status_t timer_0_init(enu_timer_mode_t mode);
extern enu_timer_error_status_t timer_0_start(enu_timer_prescaler_t prescaler);
extern enu_timer_error_status_t timer_0_initial_value(uint8_t value);
extern enu_timer_error_status_t timer_0_ovf_num(double a_overflow);
extern void timer_0_delay_ms(double a_time_ms);
extern void timer_0_stop(void);

#endif /* TIMER_H_ */