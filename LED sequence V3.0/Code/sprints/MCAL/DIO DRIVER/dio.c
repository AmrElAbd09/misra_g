/*
 * dio.c
 *
 * Created: 4/5/2023 11:36:49 PM
 *  Author: Amr
 */ 

#include "dio.h"

enu_dio_error_t dio_init(enu_ports_t port, enu_pins_t pin , enu_pin_direction_t direction){
	enu_dio_error_t loc_ErrorStatus = Dio_Ok;
	
	if(pin<PIN_0 || pin>PIN_7){
		loc_ErrorStatus = Dio_PinError ;
	}
	else{	
		switch (port)
		{

			case PORT_A :
					if (direction == INPUT)
					{
						CLR_BIT(DDRA,pin);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRA,pin);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;
					}
					break;
		
		
			case PORT_B :
					if (direction == INPUT)
					{
						CLR_BIT(DDRB,pin);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRB,pin);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;

					}
					break;
		
		
		
			case PORT_C :
					if (direction == INPUT)
					{
						CLR_BIT(DDRC,pin);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRC,pin);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;
					}
					break;
		
		
		
			case PORT_D :
					if (direction == INPUT)
					{
						CLR_BIT(DDRD,pin);
					}else if ( direction == OUTPUT){
						SET_BIT(DDRD,pin);
					}else{
						// error handling
						loc_ErrorStatus = Dio_DirectionError;
					}
					break;
		
			default:
			//error handling
					loc_ErrorStatus = Dio_PortError;
					break;
		
		}
					}
	
	return loc_ErrorStatus ;

}


enu_dio_error_t dio_write(enu_ports_t port, enu_pins_t pin , enu_state_t value){
	enu_dio_error_t loc_errorStatus = Dio_Ok ;
	
	if(pin<PIN_0 || pin>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{
		switch (port)
		{
			case PORT_A :
			
					if (value == LOW)
					{
						CLR_BIT(PORTA,pin);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTA,pin);
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
			case PORT_B :
					if (value == LOW)
					{
						CLR_BIT(PORTB,pin);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTB,pin);
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
			case PORT_C :
					if (value == LOW)
					{
						CLR_BIT(PORTC,pin);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTC,pin);
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
			case PORT_D :
					if (value == LOW)
					{
						CLR_BIT(PORTD,pin);
			
					}else if ( value == HIGH){
			
						SET_BIT(PORTD,pin);
			
					}else{
						// error handling
						loc_errorStatus = Dio_ValueError ;
					}
					break;
		
		
			default:
			//error handling
				loc_errorStatus = Dio_PortError ;
				break;
		
				}
		}
	return loc_errorStatus;
	}



enu_dio_error_t dio_read(enu_ports_t port, enu_pins_t pin , uint8_t* value){
	enu_dio_error_t loc_errorStatus = Dio_Ok ;
	
	if(pin<PIN_0 || pin>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{
	
		if(value == 0){
			loc_errorStatus = Dio_NullPointer;
		}
		else{
			switch (port)
			{
				case PORT_A :
						*value = GET_BIT(PINA,pin);
						break;
		
				case PORT_B :
						*value = GET_BIT(PINB,pin);
						break;
				
				case PORT_C :
						*value = GET_BIT(PINC,pin);
						break;
		
				case PORT_D :
						*value = GET_BIT(PIND,pin);
						break;
		
				default:
				//error handling
						loc_errorStatus = Dio_PortError;
						break;
	
			}
	}
	}
	return loc_errorStatus;
}


enu_dio_error_t dio_toggle(enu_ports_t port, enu_pins_t pin ){
	enu_dio_error_t loc_errorStatus = Dio_Ok ;
	if(pin<PIN_0 || pin>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{	
		switch (port)
		{
			case PORT_A :
				 TGL_BIT(PORTA,pin);
				break;
			
			case PORT_B :
				 TGL_BIT(PORTB,pin);
				break;
			
			case PORT_C :
				 TGL_BIT(PORTC,pin);
				break;
			
			case PORT_D :
				 TGL_BIT(PORTD,pin);
				 break;
			
			default:
			//error handling
				loc_errorStatus = Dio_PortError;
				break;
			
		}
	}
	return loc_errorStatus;
}

