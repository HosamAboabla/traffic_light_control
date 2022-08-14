/*
 * application.c
 *
 * Created: 8/12/2022 8:33:26 PM
 *  Author: hosam
 */ 


#include "application.h"


uint32_t cnt = 0;
uint8_t button_pressed = 0;
traffic_light cars_traffic_light;// = {car_green , car_yellow , car_red};
traffic_light pedestrains_traffic_light;// = {pedestrain_green , pedestrain_yellow , pedestrain_red};
	

void app_init(void)
{
	// sei();
	// SET_BIT(GIFR , INTF0);
	SET_BIT(GICR , INT0);
	LED car_green = { CAR_PORT , CAR_GREEN_PIN };
	LED car_yellow = { CAR_PORT , CAR_YELLOW_PIN};
	LED car_red = { CAR_PORT , CAR_RED_PIN};
	LED pedestrain_green = { PEDESTRAIN_PORT , PEDESTRAIN_GREEN_PIN };
	LED pedestrain_yellow = { PEDESTRAIN_PORT , PEDESTRAIN_YELLOW_PIN};
	LED pedestrain_red = { PEDESTRAIN_PORT , PEDESTRAIN_RED_PIN};
	
	cars_traffic_light.green = car_green;
	cars_traffic_light.yellow = car_yellow;
	cars_traffic_light.red = car_red;
	
	pedestrains_traffic_light.green = pedestrain_green;
	pedestrains_traffic_light.yellow = pedestrain_yellow;
	pedestrains_traffic_light.red = pedestrain_red;
	
	
	
	traffic_light_init(&cars_traffic_light);
	traffic_light_init(&pedestrains_traffic_light);
	
	Timer0_with_interrupt_initialization(TIMER0_Normal , PIN_Disconnected);
	Timer0_Start(TIMER0_Prescaler_256);
	Timer0_with_interrupt_set_delay(TIMER0_Normal , 5000 , 0);
}
void app_start(void)
{
	
}