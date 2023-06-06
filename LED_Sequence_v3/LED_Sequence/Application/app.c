/*
 * app.c
 *
 * Created: 06-Apr-23 3:02:19 AM
 *  Author: Amr
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "app.h"
/*****************************************************************************************************************************************************************
*																		Global variables																		 *
******************************************************************************************************************************************************************/
uint8_t flag = 0,flag2=0 ,error_value=0 ,error_value2=0 ;
float delay_on=100,delay_off=900;
/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
void SetFlag(){
	
	if(flag <7){
		
		flag++;
		
		}else{
		
		flag = 0;
	}
}

void SetDelay(){
	
	flag2++;
	switch(flag2){
		
		
		case 1 :
		delay_on=200;
		delay_off=800;
		break;
		
		case 2 :
		delay_on=300;
		delay_off=700;
		break;
		
		case 3 :
		delay_on=500;
		delay_off=500;
		break;
		
		case 4 :
		delay_on=800;
		delay_off=200;
		break;
		
		
		default:
		flag2 = 0 ;
		delay_on=100;
		delay_off=900;
		break;
	}
	
	
}
void APP_init(void)
{
	
	LED_init(portb, pin0);
	LED_init(portb, pin1);
	LED_init(portb, pin2);
	LED_init(portb, pin3);

	button_init(portd, pin2);
	button_init(portd, pin3);
	
	 // INTERRUPT
	 sei();
	 error_value= ExtInt_init();
	 error_value2=INT0_SetCallback(SetFlag);
	 INT1_SetCallback(SetDelay);
}


void APP_start(void){
	if (flag == 0){
		LED_off(portb,pin0);
		LED_off(portb,pin1);
		LED_off(portb,pin2);
		LED_off(portb,pin3);

	}
	else if(flag == 1){
		LED_on(portb,pin0);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin0);
		TIMER_0_DELAY_MS(delay_off);
		LED_off(portb,pin1);
		LED_off(portb,pin2);
		LED_off(portb,pin3);
		
		
		}else if (flag == 2){
		LED_on(portb,pin0);
		LED_on(portb,pin1);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin0);
		LED_off(portb,pin1);
		TIMER_0_DELAY_MS(delay_off);
		
		LED_off(portb,pin2);
		LED_off(portb,pin3);
		
		
		}else if (flag == 3){
		LED_on(portb,pin0);
		LED_on(portb,pin1);
		LED_on(portb,pin2);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin0);
		LED_off(portb,pin1);
		LED_off(portb,pin2);
		TIMER_0_DELAY_MS(delay_off);
		LED_off(portb,pin3);
		
		
		}else if (flag == 4){
		LED_on(portb,pin0);
		LED_on(portb,pin1);
		LED_on(portb,pin2);
		LED_on(portb,pin3);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin0);
		LED_off(portb,pin1);
		LED_off(portb,pin2);
		LED_off(portb,pin3);
		TIMER_0_DELAY_MS(delay_off);
		}else if (flag == 5){
		LED_off(portb,pin0);
		
		LED_on(portb,pin1);
		LED_on(portb,pin2);
		LED_on(portb,pin3);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin1);
		LED_off(portb,pin2);
		LED_off(portb,pin3);
		TIMER_0_DELAY_MS(delay_off);
		
		}else if (flag == 6){
		LED_off(portb,pin0);
		LED_off(portb,pin1);
		
		LED_on(portb,pin2);
		LED_on(portb,pin3);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin2);
		LED_off(portb,pin3);
		TIMER_0_DELAY_MS(delay_off);
		
	}
	else if (flag == 7){
		LED_off(portb,pin0);
		LED_off(portb,pin1);
		LED_off(portb,pin2);
		LED_on(portb,pin3);
		TIMER_0_DELAY_MS(delay_on);
		LED_off(portb,pin3);
		TIMER_0_DELAY_MS(delay_off);
	}
}