/*
 * led.c
 *
 * Created: 06-Apr-23 1:46:58 AM
 *  Author: Amr
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "led.h"

/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
enu_return_t LED_init (enu_ports_t port, enu_pins_t pin)
{
	if(port < porta || port > portd || pin < pin0 || pin > pin7){
		return NOT_OK;
	}
	dio_init(port,pin,OUTPUT);
	return OK;
}

enu_return_t LED_on (enu_ports_t port, enu_pins_t pin)
{
	if(port < porta || port > portd || pin < pin0 || pin > pin7){
		return NOT_OK;
	}
	dio_write(port,pin,HIGH);
	return OK;
}

enu_return_t LED_off (enu_ports_t port, enu_pins_t pin)
{
	if(port < porta || port > portd || pin < pin0 || pin > pin7){
		return NOT_OK;	
	}
		dio_write(port,pin,LOW);
		return OK;
}

/*enu_return_t LED_toggle (enu_ports_t port, enu_pins_t pin){
	
}*/