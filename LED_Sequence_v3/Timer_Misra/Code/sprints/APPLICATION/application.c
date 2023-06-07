/*
 * LED_SequenceV1.c
 *
 * Created: 4/7/2023 6:19:18 PM
 *  Author: Amr
 */ 

#include "applicarion.h"

uint8_t u8_leds_flag = 0, u8_mode_flag=0 ,u8_int_error_enu_state_t=0 ,u8_error_enu_state_t2=0 ;
float delay_on=100,delay_off=900;

static void set_led_flag(){
	
	if(u8_leds_flag <7){
		
		u8_leds_flag++;
		
	}else{
		
		u8_leds_flag = 0;
	}
	
	
}

static void set_delay(){
	
	u8_mode_flag++;
	switch(u8_mode_flag){
	
		
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
		u8_mode_flag = 0 ;
		delay_on=100;
		delay_off=900;
		break;
	}
	
	
}
void app_init(void){
	
	 button_init(BUTTON_INT0_PORT,BUTTON_INT0_PIN);
	 button_init(BUTTON_INT1_PORT,BUTTON_INT1_PIN);

	 led_init(PORT_B,PIN_0);
	 led_init(PORT_B,PIN_1);
	 led_init(PORT_B,PIN_2);
	 led_init(PORT_B,PIN_3);
	 
	 // INTERRUPT
	 SEI;
	u8_int_error_enu_state_t= ext_int_init(); 
	u8_error_enu_state_t2=int0_set_callback(set_led_flag);
	int1_set_callback(set_delay);
}


void app_start(){
	if (u8_leds_flag == 0){
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);	

	}
	else if(u8_leds_flag == 1){
		led_on(PORT_B,PIN_0);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_0);
		timer_0_delay_ms(delay_off);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		
		
	}else if (u8_leds_flag == 2){
		led_on(PORT_B,PIN_0);
		led_on(PORT_B,PIN_1);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		timer_0_delay_ms(delay_off);
		
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		
		
	}else if (u8_leds_flag == 3){
		led_on(PORT_B,PIN_0);
		led_on(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		timer_0_delay_ms(delay_off);
		led_off(PORT_B,PIN_3);
		
		
	}else if (u8_leds_flag == 4){
		led_on(PORT_B,PIN_0);
		led_on(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(delay_off);
	}else if (u8_leds_flag == 5){
		led_off(PORT_B,PIN_0);
		
		led_on(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(delay_off);
		
	}else if (u8_leds_flag == 6){
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		
		led_on(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(delay_off);
		
	}
	else if (u8_leds_flag == 7){
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(delay_on);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(delay_off);
	}
}

	
