/*
 * app.c
 *
 * Created: 06-Apr-23 3:02:19 AM
 *  Author: Zerconium
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "app.h"
#include "util/delay.h"
/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
void APP_init()
{
	LED_init(portb, pin0);
	LED_init(portb, pin1);
	LED_init(portb, pin2);
	LED_init(portb, pin3);
	button_init(portc, pin1);
}


void APP_start()
{
	enu_state_t buttonSTATE;
	uint8_t counter = 0;
	while(1){
		button_read(portc,pin1,&buttonSTATE);
		if(buttonSTATE == HIGH)
		{
			counter++;
			while (buttonSTATE == HIGH)
			{
				button_read(portc,pin1,&buttonSTATE);
			}
		}
			if(counter ==1){
				LED_on(portb,pin0);
			}
			else if(counter ==2){
				LED_on(portb,pin1);
			}
			else if(counter ==3){
				LED_on(portb,pin2);
			}
			else if(counter ==4){
				LED_on(portb,pin3);
			}
			else if(counter ==5){
				LED_off(portb,pin0);
			}
			else if(counter ==6){
				LED_off(portb,pin1);
			}
			else if(counter ==7){
				LED_off(portb,pin2);
			}
			else if(counter ==8){
				LED_off(portb,pin3);
				counter =0;
			}
		}
		
	
		
	
}
