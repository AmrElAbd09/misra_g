/*
 * dio.h
 *
 * Created: 4/5/2023 11:36:36 PM
 *  Author: Amr
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/types.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include <util/delay.h>


/*************************************************/
//					MACROS
/**************************************************/

// PORTS
typedef enum {
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
	
	}enu_ports_t;

// PINS
typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7		
	}enu_pins_t;

// DIRECTIONS
typedef enum {
	INPUT,
	OUTPUT	
	}enu_pin_direction_t;

// state
typedef enum {
	LOW,
	HIGH
	}enu_state_t;

// Error Status

typedef enum {
	Dio_Ok = 0,
	Dio_PortError,
	Dio_PinError,
	Dio_ValueError,
	Dio_DirectionError,
	Dio_NullPointer,
	
} enu_dio_error_t;


/*************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/

enu_dio_error_t dio_init(enu_ports_t enu_port, enu_pins_t enu_pin , enu_pin_direction_t enu_direction);
enu_dio_error_t dio_write(enu_ports_t enu_port, enu_pins_t enu_pin , uint8_t value);
enu_dio_error_t dio_read(enu_ports_t enu_port, enu_pins_t enu_pin , uint8_t* value);
enu_dio_error_t dio_toggle(enu_ports_t enu_port, enu_pins_t enu_pin );



#endif /* DIO_H_ */