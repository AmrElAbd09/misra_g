/*
 * button.c
 *
 * Created: 4/6/2023 5:10:53 AM
 *  Author: Amr
 */ 
#include "button.h"

enu_dio_error_t button_init(enu_ports_t enu_port ,enu_pins_t enu_pin)
{
	enu_dio_error_t loc_errorStatus = dio_init(enu_port,enu_pin,INPUT);
	return loc_errorStatus;
}

enu_dio_error_t button_read(enu_ports_t enu_port ,enu_pins_t enu_pin, uint8_t *value)
{
	enu_dio_error_t loc_errorStatus = dio_read(enu_port,enu_pin,value);
	return loc_errorStatus;
}



