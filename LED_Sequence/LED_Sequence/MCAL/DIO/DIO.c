/*
 * DIO.c
 *
 * Created: 05-Apr-23 11:30:54 PM
 *  Author: Zerconium
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "DIO.h"
/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
//initialization function
enu_return_t dio_init (enu_ports_t enu_port, enu_pins_t enu_pin, enu_direction_t enu_direction)
{
	enu_return_t enu_retval = OK;
	if ((enu_port > portd) || (enu_pin > pin7))
	{
		enu_retval = NOT_OK;
	}
	else
	{
		switch (enu_port)
		{
			case porta :
			{
				if(enu_direction == INPUT){
					RESET_BIT(DDRA,enu_pin);
				}
				else if(enu_direction == OUTPUT){
					SET_BIT(DDRA, enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			break;
			case portb :
			{
				if(enu_direction == INPUT){
					RESET_BIT(DDRB,enu_pin);
				}
				else if(enu_direction == OUTPUT){
					SET_BIT(DDRB, enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			break;
			case portc :
			{
				if(enu_direction == INPUT)
				{
					RESET_BIT(DDRC,enu_pin);
				}
				else if(enu_direction == OUTPUT){
					SET_BIT(DDRC, enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			break;
			case portd :
			{
				if(enu_direction == INPUT)
				{
					RESET_BIT(DDRD,enu_pin);
				}
				else if(enu_direction == OUTPUT){
					SET_BIT(DDRD, enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			break;
			default:
			{
				enu_retval = NOT_OK;
			}
		}
	}	
	return enu_retval;
}

//writing function
enu_return_t dio_write (enu_ports_t enu_port, enu_pins_t enu_pin, enu_state_t enu_state)
{
	enu_return_t enu_retval = OK;
	if ((enu_port > portd) || (enu_pin > pin7))
	{
		enu_retval = NOT_OK;
	}
	else
	{
		switch(enu_port){
			case porta :
			{
				if(enu_state == HIGH)
				{
					SET_BIT(PORTA, enu_pin);
				}
				else if (enu_state == LOW){
					RESET_BIT(PORTA,enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}		
			break;
			case portb :
			{
				if(enu_state == HIGH)
				{
					SET_BIT(PORTB, enu_pin);
				}
				else if (enu_state == LOW){
					RESET_BIT(PORTB,enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			
			break;
			case portc :
			{
				if(enu_state == HIGH)
				{
					SET_BIT(PORTC, enu_pin);
				}
				else if (enu_state == LOW){
					RESET_BIT(PORTC,enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			
			break;
			case portd :
			{
				if(enu_state == HIGH)
				{
					SET_BIT(PORTD, enu_pin);
				}
				else if (enu_state == LOW){
					RESET_BIT(PORTD,enu_pin);
				}
				else
				{
					enu_retval = NOT_OK;
				}
			}
			break;			
			default:
			{
				enu_retval = NOT_OK;
			}
		}
	}
	return enu_retval;
}

//reading function
enu_return_t dio_read (enu_ports_t enu_port, enu_pins_t enu_pin, uint8_t* value)
{
	enu_return_t enu_retval = OK;
	if ((enu_port > portd) || (enu_pin > pin7))
	{
		enu_retval = NOT_OK;
	}
	else
	{	
		switch (enu_port)
		{
			case porta:
			{
				*value = READ_BIT(PINA,enu_pin);
			}
			break;
			case portb:
			{
				*value = READ_BIT(PINB,enu_pin);
			}
			break;
			case portc:
			{
				*value = READ_BIT(PINC,enu_pin);
			}
			break;
			case portd:
			{
				*value = READ_BIT(PIND,enu_pin);
			}
			break;
			default:
			{
				enu_retval = NOT_OK;
			}
		}
	}
	
return enu_retval ;
}