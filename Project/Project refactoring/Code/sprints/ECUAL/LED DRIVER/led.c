/*
 * led.c
 *
 * Created: 4/6/2023 2:27:43 AM
 *  Author: Amr
 */ 
#include "led.h"

enu_dio_error_t led_init(enu_ports_t enu_port , enu_pins_t enu_pin)
{
	enu_dio_error_t loc_errorStatus = dio_init(enu_port,enu_pin,OUTPUT);
	return loc_errorStatus;
}

enu_dio_error_t led_on (enu_ports_t enu_port , enu_pins_t enu_pin)
{
	enu_dio_error_t loc_errorStatus = dio_write(enu_port,enu_pin,HIGH);
	return loc_errorStatus;
}

enu_dio_error_t led_off(enu_ports_t enu_port , enu_pins_t enu_pin)
{
	enu_dio_error_t loc_errorStatus = dio_write(enu_port,enu_pin,LOW);	
	return loc_errorStatus;
}
	
enu_dio_error_t led_toggle(enu_ports_t enu_port , enu_pins_t enu_pin)
{
	enu_dio_error_t loc_errorStatus = dio_toggle(enu_port,enu_pin);
	return loc_errorStatus;
}


