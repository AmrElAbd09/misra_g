/*
 * LED_SequenceV1.c
 *
 * Created: 4/7/2023 6:19:18 PM
 *  Author: Amr
 */ 

#include "application.h"

uint8_t u8_leds_flag = 0, u8_mode_flag=0 ,u8_int_error_enu_state_t=0 ,u8_error_enu_state_t2=0 ;
float g_delay_on=100,g_delay_off=900;

static void led_sequence(void)
{
	if(u8_leds_flag <7)
	{	
		u8_leds_flag++;	
	}
	else
	{	
		u8_leds_flag = 0;
	}
}

static void blinking_mode(void)
{
	u8_mode_flag++;
	switch(u8_mode_flag)
	{
		
		case 1 :
		{
			g_delay_on=200;
			g_delay_off=800;
			break;
		}
	
		case 2 :
		{
			g_delay_on=300;
			g_delay_off=700;
			break;
		}
	
		case 3 :
		{
			g_delay_on=500;
			g_delay_off=500;
			break;
		}

		case 4 :
		{
			g_delay_on=800;
			g_delay_off=200;
			break;
		}
		
		default:
		{
			u8_mode_flag = 0 ;
			g_delay_on=100;
			g_delay_off=900;
			break;
		}		
	}	
}


void app_init(void)
{
	 button_init(BUTTON_INT0_PORT,BUTTON_INT0_PIN);
	 button_init(BUTTON_INT1_PORT,BUTTON_INT1_PIN);
	 led_init(PORT_B,PIN_0);
	 led_init(PORT_B,PIN_1);
	 led_init(PORT_B,PIN_2);
	 led_init(PORT_B,PIN_3);	 
	SEI;
	u8_int_error_enu_state_t= ext_int_init(); 
	u8_error_enu_state_t2=int0_set_callback(led_sequence);
	u8_error_enu_state_t2=int1_set_callback(blinking_mode);
}


void app_start()
{
	if (u8_leds_flag == 0)
	{
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);	
	}
	else if(u8_leds_flag == 1)
	{
		led_on(PORT_B,PIN_0);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_0);
		timer_0_delay_ms(g_delay_off);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);	
	}
	else if (u8_leds_flag == 2)
	{
		led_on(PORT_B,PIN_0);
		led_on(PORT_B,PIN_1);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		timer_0_delay_ms(g_delay_off);		
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);		
	}
	else if (u8_leds_flag == 3)
	{
		led_on(PORT_B,PIN_0);
		led_on(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		timer_0_delay_ms(g_delay_off);
		led_off(PORT_B,PIN_3);		
	}
	else if (u8_leds_flag == 4)
	{
		led_on(PORT_B,PIN_0);
		led_on(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_off);
	}
	else if (u8_leds_flag == 5)
	{
		led_off(PORT_B,PIN_0);	
		led_on(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_off);	
	}
	else if (u8_leds_flag == 6)
	{
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_on(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_2);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_off);		
	}
	else if (u8_leds_flag == 7)
	{
		led_off(PORT_B,PIN_0);
		led_off(PORT_B,PIN_1);
		led_off(PORT_B,PIN_2);
		led_on(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_on);
		led_off(PORT_B,PIN_3);
		timer_0_delay_ms(g_delay_off);
	}
}

	
