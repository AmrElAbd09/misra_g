/*
 * IncFile1.h
 *
 * Created: 4/6/2023 2:27:17 AM
 *  Author: Amr
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../../MCAL/DIO DRIVER/dio.h"


/*********************************************************/
//				FUNCTIONS PROTOTYPES
/*********************************************************/

enu_dio_error_t led_init(enu_ports_t enu_port , enu_pins_t enu_pin);
enu_dio_error_t led_on (enu_ports_t enu_port , enu_pins_t enu_pin);
enu_dio_error_t led_off(enu_ports_t enu_port , enu_pins_t enu_pin);
enu_dio_error_t led_toggle(enu_ports_t enu_port , enu_pins_t enu_pin);



#endif /* INCFILE1_H_ */