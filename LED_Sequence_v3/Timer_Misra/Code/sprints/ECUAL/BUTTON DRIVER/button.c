/*
 * button.c
 *
 * Created: 4/6/2023 5:10:53 AM
 *  Author: Amr
 */ 
#include "button.h"

enu_dio_error_t button_init(enu_ports_t port ,enu_pins_t pin){
	enu_dio_error_t loc_errorStatus = dio_init(port,pin,INPUT);
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

enu_dio_error_t button_read(enu_ports_t port ,enu_pins_t pin, uint8_t *value){
	
	enu_dio_error_t loc_errorStatus = dio_read(port,pin,value);
	 if (loc_errorStatus == Dio_PortError){
	
		return Dio_PortError;
	
	}else if (loc_errorStatus == Dio_PinError){
	
		return Dio_PinError;
	
	}else if (loc_errorStatus == Dio_NullPointer){
	
		return Dio_NullPointer;
	
	}
	else{
		return Dio_Ok;
	}
}



