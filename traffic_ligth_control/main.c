/*
 * traffic_ligth_control.c
 *
 * Created: 8/12/2022 6:40:38 PM
 * Author : hosam
 */ 


#include "APPLICATION/application.h"


	
extern uint32_t Number_OVF;
extern uint32_t init_val;

extern uint32_t cnt;// = 0;
extern uint8_t button_pressed;// = 0;
extern traffic_light cars_traffic_light;// = {car_green , car_yellow , car_red};
extern traffic_light pedestrains_traffic_light;// = {pedestrain_green , pedestrain_yellow , pedestrain_red};
	
int main(void)
{
	
	
	// app_init();
	
    /* Replace with your application code */
    while (1) 
    {
		DIO_TogglePinValue(CAR_PORT , CAR_GREEN_PIN);
		_delay_ms(1000);
		// app_start();
    }
}




ISR(TIMER0_OVF_vect){
	
	
	
	// if( (cnt == Number_OVF / 5) || (cnt == Number_OVF * 2 / 5) || (cnt == Number_OVF * 3 / 5) || (cnt == Number_OVF * 4 / 5))
	if( cnt % (Number_OVF/5) ==0 )
	{

		if(cars_traffic_light.status == traffic_status_yellow)
		{
			LED_Toggle(&cars_traffic_light.yellow);
		}
		if(pedestrains_traffic_light.status == traffic_status_yellow)
		{
			LED_Toggle(&pedestrains_traffic_light.yellow);
		}

		
	}

	if(cnt==Number_OVF){		//if counter reach number of overflows
		// LED_Toggle(&led1);
		TCNT0 = init_val;
		next_state(&cars_traffic_light);
		
		if(pedestrains_traffic_light.status != traffic_status_red)
		{
			next_state(&pedestrains_traffic_light);
		}
		else
		{
			button_pressed = 0;			
		}

		cnt=0;					//make  counter =0
	}
	else
	{
		cnt++;
	}
		
}




ISR(INT0_vect){
	
	if(cars_traffic_light.status == traffic_status_red && button_pressed == 0)
	{
		Timer0_Stop();
		Timer0_Start(TIMER0_Prescaler_256);
		cnt = 0;
		go(&pedestrains_traffic_light);
	}
	else if(cars_traffic_light.status == traffic_status_green && button_pressed == 0)
	{
		Timer0_Stop();
		Timer0_Start(TIMER0_Prescaler_256);
		cnt = 0;
		next_state(&cars_traffic_light);
		next_state(&pedestrains_traffic_light);
	}
	else if(cars_traffic_light.status == traffic_status_yellow && button_pressed == 0)
	{
		Timer0_Stop();
		Timer0_Start(TIMER0_Prescaler_256);
		cnt = 0;
		cars_traffic_light.previous_status = traffic_status_green;
		next_state(&pedestrains_traffic_light);
	}
	button_pressed = 1;
}