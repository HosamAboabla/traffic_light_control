/*
 * traffic_ligth_control.c
 *
 * Created: 8/12/2022 6:40:38 PM
 * Author : hosam
 */ 


#include "APPLICATION/application.h"


	
extern uint32_t Number_OVF;
extern uint32_t init_val;



traffic_light cars_traffic_light;// = {car_green , car_yellow , car_red};
traffic_light pedestrains_traffic_light;// = {pedestrain_green , pedestrain_yellow , pedestrain_red};
	
int main(void)
{
	
	
	LED car_green = { CAR_PORT , CAR_GREEN_PIN };
	LED car_yellow = { CAR_PORT , CAR_YELLOW_PIN};
	LED car_red = { CAR_PORT , CAR_RED_PIN};
	LED pedestrain_green = { PEDESTRAIN_PORT , PEDESTRAIN_GREEN_PIN };
	LED pedestrain_yellow = { PEDESTRAIN_PORT , PEDESTRAIN_YELLOW_PIN};
	LED pedestrain_red = { PEDESTRAIN_PORT , PEDESTRAIN_RED_PIN};
		
	cars_traffic_light.green = car_green;
	cars_traffic_light.yellow = car_yellow;
	cars_traffic_light.green = car_red;
	
	pedestrains_traffic_light.green = pedestrain_green;
	pedestrains_traffic_light.yellow = pedestrain_yellow;
	pedestrains_traffic_light.red = pedestrain_red;
	
	
		
	traffic_light_init(&cars_traffic_light);
	traffic_light_init(&pedestrains_traffic_light);
	
	Timer0_with_interrupt_initialization(TIMER0_Normal , PIN_Disconnected);
	Timer0_Start(TIMER0_Prescaler_256);
	Timer0_with_interrupt_set_delay(TIMER0_Normal , 1000 , 0);
	
	
    /* Replace with your application code */
    while (1) 
    {
		// go(&cars_traffic_light);
		// stop(&pedestrains_traffic_light);
		// _delay_ms(5000);
		// ready(&cars_traffic_light);
		// ready(&pedestrains_traffic_light);
		// _delay_ms(5000);
		// stop(&cars_traffic_light);
		// go(&pedestrains_traffic_light);
		// _delay_ms(5000);

    }
}




ISR(TIMER0_OVF_vect){
	
	static uint32_t cnt=0;

	if(cnt==Number_OVF){		//if counter reach number of overflows
		// LED_Toggle(&led1);
		TCNT0 = init_val;
		if(cars_traffic_light.status == traffic_status_green)
		{
			ready(&cars_traffic_light);
		}
		else if(cars_traffic_light.status == traffic_status_yellow)
		{
			stop(&cars_traffic_light);
		}
		else if(cars_traffic_light.status == traffic_status_red)
		{
			go(&cars_traffic_light);
		}
		cnt=0;					//make  counter =0
	}
	else
	{
		cnt++;
	}
		
}
