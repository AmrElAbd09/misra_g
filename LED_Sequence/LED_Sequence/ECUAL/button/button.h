/*
 * button.h
 *
 * Created: 06-Apr-23 2:09:09 AM
 *  Author: Zerconium
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "../../MCAL/DIO/dio.h"

/*****************************************************************************************************************************************************************
*																		Typdefs																				 *
******************************************************************************************************************************************************************/
typedef struct ST_button{
	enu_ports_t ST_port;
	enu_pins_t ST_pin;
	}ST_button;

/*****************************************************************************************************************************************************************
*																		Functions Prototypes																	 *
******************************************************************************************************************************************************************/
enu_return_t button_init(enu_ports_t port, enu_pins_t pin);
enu_return_t button_read(enu_ports_t port,enu_pins_t pin, enu_state_t* state);



#endif /* BUTTON_H_ */