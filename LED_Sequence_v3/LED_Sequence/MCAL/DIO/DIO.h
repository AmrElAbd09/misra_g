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
typedef enum EN_ports {porta, portb, portc, portd}EN_ports;
typedef enum EN_pins {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7}EN_pins;
typedef enum EN_direction {INPUT, OUTPUT}EN_direction;
typedef enum EN_state {LOW, HIGH}EN_state;
typedef enum EN_return {OK, NOT_OK}EN_return;
/*****************************************************************************************************************************************************************
*																		Functions Prototypes																	 *
******************************************************************************************************************************************************************/
EN_return DIO_init (EN_ports port, EN_pins pin, EN_direction direction);
EN_return DIO_write (EN_ports port, EN_pins pin, EN_state state);
EN_return DIO_read (EN_ports port, EN_pins pin, uint8_t* value);





#endif /* DIO_H_ */