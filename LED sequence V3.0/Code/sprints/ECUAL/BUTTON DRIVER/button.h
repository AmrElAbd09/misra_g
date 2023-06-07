/*
 * button.h
 *
 * Created: 4/6/2023 5:10:40 AM
 *  Author: Amr
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO DRIVER/dio.h"


/**************************************************/
//					MACROS
/**************************************************/

// BUTTONS CONFIG
#define BUTTON_1_PORT		PORT_C
#define BUTTON_1_PIN		PIN_1

#define BUTTON_INT0_PORT	PORT_D
#define BUTTON_INT0_PIN		PIN_2

#define BUTTON_INT1_PORT	PORT_D
#define BUTTON_INT1_PIN		PIN_3

#define BUTTON_INT2_PORT	PORT_B
#define BUTTON_INT2_PIN		PIN_3






/**************************************************/
//			 FUNCTIONS PROTOTYPES
/**************************************************/
enu_dio_error_t button_init(enu_ports_t port ,enu_pins_t pin);

enu_dio_error_t button_read(enu_ports_t port ,enu_pins_t pin, uint8_t *value);



#endif /* BUTTON_H_ */