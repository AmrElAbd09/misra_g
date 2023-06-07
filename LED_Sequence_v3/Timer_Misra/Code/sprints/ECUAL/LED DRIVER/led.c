/*
 * led.c
 *
 * Created: 4/6/2023 2:27:43 AM
 *  Author: Amr
 */ 
#include "led.h"

enu_dio_error_t led_init(enu_ports_t enu_port , enu_pins_t enu_pin){
	enu_dio_error_t loc_errorStatus = dio_init(enu_port,enu_pin,OUTPUT);
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_PinError){
	
		return Dio_PinError;
	
	
	}else if (loc_errorStatus == Dio_DirectionError){
		
		return Dio_DirectionError;
		
	}else{
		return Dio_Ok;
	}
}

enu_dio_error_t led_on (enu_ports_t enu_port , enu_pins_t enu_pin){
	enu_dio_error_t loc_errorStatus = dio_write(enu_port,enu_pin,HIGH);
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_PinError){
	
	return Dio_PinError;
	
	
	}
	else if (loc_errorStatus == Dio_ValueError){
		
		return Dio_ValueError;
		
	}else{
		return Dio_Ok;
	}
}

enu_dio_error_t led_off(enu_ports_t enu_port , enu_pins_t enu_pin){
	enu_dio_error_t loc_errorStatus = dio_write(enu_port,enu_pin,LOW);	
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_ValueError){
		
		return Dio_ValueError;
		
	}else{
		return Dio_Ok;
	}
	
}
	
enu_dio_error_t led_toggle(enu_ports_t enu_port , enu_pins_t enu_pin){
	enu_dio_error_t loc_errorStatus = dio_toggle(enu_port,enu_pin);
	
	if ( loc_errorStatus == Dio_PortError){
		
		return Dio_PortError;
		
	}else if (loc_errorStatus == Dio_PinError){
		
		return Dio_PinError;
		
		
	}else{
		return Dio_Ok;
	}
}


