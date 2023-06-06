/*
 * DIO.h
 *
 * Created: 05-Apr-23 11:30:42 PM
 *  Author: Zerconium
 */ 


#ifndef DIO_H_
#define DIO_H_


/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "../../Utilities/manu.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/Types.h"

/*****************************************************************************************************************************************************************
*																		Typedefs																				 *
******************************************************************************************************************************************************************/
typedef enum enu_ports_t {
	porta = 0, 
	portb, 
	portc, 
	portd
	}enu_ports_t;
	
typedef enum enu_pins_t {
	pin0 = 0, 
	pin1, 
	pin2, 
	pin3, 
	pin4, 
	pin5, 
	pin6, 
	pin7
	}enu_pins_t;
	
typedef enum enu_direction_t {
	INPUT = 0, 
	OUTPUT
	}enu_direction_t;
	
typedef enum enu_state_t {
	LOW = 0,
	HIGH
	}enu_state_t;
	
typedef enum enu_return_t {
	OK = 0, 
	NOT_OK
	}enu_return_t;
	
	
/*****************************************************************************************************************************************************************
*																		Functions Prototypes																	 *
******************************************************************************************************************************************************************/
enu_return_t dio_init (enu_ports_t enu_port, enu_pins_t enu_pin, enu_direction_t enu_direction);
enu_return_t dio_write (enu_ports_t enu_port, enu_pins_t enu_pin, enu_state_t enu_state);
enu_return_t dio_read (enu_ports_t enu_port, enu_pins_t enu_pin, uint8_t* enu_value);





#endif /* DIO_H_ */