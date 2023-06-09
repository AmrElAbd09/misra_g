/*
 * LED_Sequence.h
 *
 * Created: 4/7/2023 6:23:18 PM
 *  Author: Amr
 */ 


#ifndef	APPLICATION_H_
#define APPLICATION_H_


#include "../ECUAL/LED DRIVER/led.h"
#include "../ECUAL/BUTTON DRIVER/button.h"
#include "../MCAL/EXT_INTERRUPT/Ext_IntCnfg.h"
#include "../MCAL/timer/timer.h"



/**************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
extern void app_init	(void);
extern void app_start	(void);

#endif /* APPLICATION_H_ */