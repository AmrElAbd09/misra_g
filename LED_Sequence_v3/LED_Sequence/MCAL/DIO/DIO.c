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
EN_return DIO_init (EN_ports port, EN_pins pin, EN_direction direction)
{
	switch (port)
	{
//PORTA
		case porta :
		if(direction == INPUT){
			RESET_BIT(DDRA,pin);
		}
		else if(direction == OUTPUT){
			SET_BIT(DDRA, pin);
		}
		else{return NOT_OK;}
		break;
//PORTB
				case portb :
				if(direction == INPUT){
					RESET_BIT(DDRB,pin);
				}
				else if(direction == OUTPUT){
					SET_BIT(DDRB, pin);
				}
				else{return NOT_OK;}
				break;
//PORTC
						case portc :
						if(direction == INPUT){
							RESET_BIT(DDRC,pin);
						}
						else if(direction == OUTPUT){
							SET_BIT(DDRC, pin);
						}
						else{return NOT_OK;}
						break;
//PORTD
									case portd :
									if(direction == INPUT){
										RESET_BIT(DDRD,pin);
									}
									else if(direction == OUTPUT){
										SET_BIT(DDRD, pin);
									}
									else{return NOT_OK;}
									break;
	}
	return OK;
}

//writing function
EN_return DIO_write (EN_ports port, EN_pins pin, EN_state state)
{
	switch(port){
//PORTA
		case porta :
		if(state == HIGH){
			SET_BIT(PORTA, pin);
		}
		else if (state == LOW){
			RESET_BIT(PORTA,pin);
		}
		else{return NOT_OK;}
		break;
//PORTB
				case portb :
				if(state == HIGH){
					SET_BIT(PORTB, pin);
				}
				else if (state == LOW){
					RESET_BIT(PORTB,pin);
				}
				else{return NOT_OK;}
				break;
//PORTC
						case portc :
						if(state == HIGH){
							SET_BIT(PORTC, pin);
						}
						else if (state == LOW){
							RESET_BIT(PORTC,pin);
						}
						else{return NOT_OK;}
						break;
//PORTD
								case portd :
								if(state == HIGH){
									SET_BIT(PORTD, pin);
								}
								else if (state == LOW){
									RESET_BIT(PORTD,pin);
								}
								else{return NOT_OK;}
								break;
		}
	return OK;
}

//reading function
EN_return DIO_read (EN_ports port, EN_pins pin, uint8_t* value)
{
	switch (port)
	{
		case porta: *value = READ_BIT(PINA,pin);break;
		case portb: *value = READ_BIT(PINB,pin);break;
		case portc: *value = READ_BIT(PINC,pin);break;
		case portd: *value = READ_BIT(PIND,pin);break;
		default: return NOT_OK;
	}
return OK;
}