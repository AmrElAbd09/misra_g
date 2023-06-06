/*
 * led.c
 *
 * Created: 06-Apr-23 1:46:58 AM
 *  Author: Zerconium
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "led.h"

/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
EN_return LED_init (EN_ports port, EN_pins pin)
{
	if(port < porta || port > portd || pin < pin0 || pin > pin7){
		return NOT_OK;
	}
	DIO_init(port,pin,OUTPUT);
	return OK;
}

EN_return LED_on (EN_ports port, EN_pins pin)
{
	if(port < porta || port > portd || pin < pin0 || pin > pin7){
		return NOT_OK;
	}
	DIO_write(port,pin,HIGH);
	return OK;
}

EN_return LED_off (EN_ports port, EN_pins pin)
{
	if(port < porta || port > portd || pin < pin0 || pin > pin7){
		return NOT_OK;	
	}
		DIO_write(port,pin,LOW);
		return OK;
}

/*EN_return LED_toggle (EN_ports port, EN_pins pin){
	
}*/