/*
 * dio.c
 *
 * Created: 4/5/2023 11:36:49 PM
 *  Author: Amr
 */ 

#include "dio.h"

enu_dio_error_t dio_init(enu_ports_t enu_port, enu_pins_t enu_pin , enu_pin_direction_t enu_direction){
	enu_dio_error_t loc_ErrorStatus = Dio_Ok;
	
	if(enu_pin<PIN_0 || enu_pin>PIN_7)
	{
		loc_ErrorStatus = Dio_PinError ;
	}
	else
	{	
		switch (enu_port)
		{

			case PORT_A :
			{
				if (enu_direction == INPUT)
				{
					CLR_BIT(DDRA,enu_pin);
					}else if ( enu_direction == OUTPUT){
					SET_BIT(DDRA,enu_pin);
					}else{
					// error handling
					loc_ErrorStatus = Dio_DirectionError;
				}
				break;
			}	
			case PORT_B :
			{
				if (enu_direction == INPUT)
				{
					CLR_BIT(DDRB,enu_pin);
					}else if ( enu_direction == OUTPUT){
					SET_BIT(DDRB,enu_pin);
					}else{
					// error handling
					loc_ErrorStatus = Dio_DirectionError;

				}
				break;
			}		
			case PORT_C :
			{
				if (enu_direction == INPUT)
				{
					CLR_BIT(DDRC,enu_pin);
					}else if ( enu_direction == OUTPUT){
					SET_BIT(DDRC,enu_pin);
					}else{
					// error handling
					loc_ErrorStatus = Dio_DirectionError;
				}
				break;
			}	
			case PORT_D :
			{
				if (enu_direction == INPUT)
				{
					CLR_BIT(DDRD,enu_pin);
					}else if ( enu_direction == OUTPUT){
					SET_BIT(DDRD,enu_pin);
					}else{
					// error handling
					loc_ErrorStatus = Dio_DirectionError;
				}
				break;
			}	
			default:
			{
				loc_ErrorStatus = Dio_PortError;
				break;
			}
		}
	}
	return loc_ErrorStatus ;
}


enu_dio_error_t dio_write(enu_ports_t enu_port, enu_pins_t enu_pin , enu_state_t enu_value){
	enu_dio_error_t loc_errorStatus = Dio_Ok ;
	
	if(enu_pin<PIN_0 || enu_pin>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{
		switch (enu_port)
		{
			case PORT_A :
			{
				if (enu_value == LOW)
				{
					CLR_BIT(PORTA,enu_pin);
					
					}else if ( enu_value == HIGH){
					
					SET_BIT(PORTA,enu_pin);
					}else{
					// error handling
					loc_errorStatus = Dio_ValueError ;
				}
				break;
			}
			case PORT_B :
			{
				if (enu_value == LOW)
				{
					CLR_BIT(PORTB,enu_pin);
					
					}else if ( enu_value == HIGH){
					
					SET_BIT(PORTB,enu_pin);
					}else{
					// error handling
					loc_errorStatus = Dio_ValueError ;
				}
				break;
			}
			case PORT_C :
			{
				if (enu_value == LOW)
				{
					CLR_BIT(PORTC,enu_pin);
					
					}else if ( enu_value == HIGH){
					
					SET_BIT(PORTC,enu_pin);
					}else{
					// error handling
					loc_errorStatus = Dio_ValueError ;
				}
				break;
			}
			case PORT_D :
			{
				if (enu_value == LOW)
				{
					CLR_BIT(PORTD,enu_pin);
					
					}else if ( enu_value == HIGH){
					
					SET_BIT(PORTD,enu_pin);
					
					}else{
					// error handling
					loc_errorStatus = Dio_ValueError ;
				}
				break;
			}	
			default:
			{
				loc_errorStatus = Dio_PortError ;
				break;
			}						
		}
	}
	return loc_errorStatus;
}



enu_dio_error_t dio_read(enu_ports_t enu_port, enu_pins_t enu_pin , uint8_t* value){
	enu_dio_error_t loc_errorStatus = Dio_Ok ;
	
	if(enu_pin<PIN_0 || enu_pin>PIN_7)
	{
		loc_errorStatus = Dio_PinError ;
	}
	else
	{
	
		if(value == 0)
		{
			loc_errorStatus = Dio_NullPointer;
		}
		else
		{
			switch (enu_port)
			{
				case PORT_A :
				{
					*value = GET_BIT(PINA,enu_pin);
					break;
				}
				case PORT_B :
				{
					*value = GET_BIT(PINB,enu_pin);
					break;
				}			
				case PORT_C :
				{
					*value = GET_BIT(PINC,enu_pin);
					break;
				}
				case PORT_D :
				{
					*value = GET_BIT(PIND,enu_pin);
					break;
				}
				default:
				{
					loc_errorStatus = Dio_PortError;
					break;
				}
			}
		}
	}
	return loc_errorStatus;
}


enu_dio_error_t dio_toggle(enu_ports_t enu_port, enu_pins_t enu_pin ){
	enu_dio_error_t loc_errorStatus = Dio_Ok ;
	if(enu_pin<PIN_0 || enu_pin>PIN_7){
		loc_errorStatus = Dio_PinError ;
	}
	else{	
		switch (enu_port)
		{
			case PORT_A :
			{
				TGL_BIT(PORTA,enu_pin);
				break;
			}		
			case PORT_B :
			{
				TGL_BIT(PORTB,enu_pin);
				break;
			}	
			case PORT_C :
			{
				TGL_BIT(PORTC,enu_pin);
				break;
			}	
			case PORT_D :
			{
				TGL_BIT(PORTD,enu_pin);
				break;
			}	
			default:
			{
				loc_errorStatus = Dio_PortError;
				break;
			}			
		}
	}
	return loc_errorStatus;
}

