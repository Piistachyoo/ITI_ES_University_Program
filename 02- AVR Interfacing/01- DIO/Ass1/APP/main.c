/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/Seven_Segment/SS_interface.h"
#include "../HAL/LED/LED_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main(void){
	SS_t SS1, SS2;
	sint8 index;
	for(index = 0; index < 7; index++){
		SS1.PIN[index].GPIOx = GPIOC;
		SS1.PIN[index].direction = GPIO_OUTPUT;
		SS1.PIN[index].pin = index;
	}
	SS1.mode = SS_MODE_CommonAnode;

	for(index = 0; index < 7; index++){
		SS2.PIN[index].GPIOx = GPIOD;
		SS2.PIN[index].direction = GPIO_OUTPUT;
		SS2.PIN[index].pin = index;
	}
	SS2.mode = SS_MODE_CommonCathode;

	SS_Init(&SS1);
	SS_Init(&SS2);

	LED_t RED, YELLOW, GREEN;
	RED.led_mode = LED_MODE_ActiveLow;
	RED.led_pin.GPIOx = GPIOA;
	RED.led_pin.default_state = GPIO_STATE_HIGH;
	RED.led_pin.direction = GPIO_OUTPUT;
	RED.led_pin.pin = GPIO_PIN_0;
	LED_Init(&RED);
	YELLOW.led_mode = LED_MODE_ActiveLow;
	YELLOW.led_pin.GPIOx = GPIOA;
	YELLOW.led_pin.default_state = GPIO_STATE_HIGH;
	YELLOW.led_pin.direction = GPIO_OUTPUT;
	YELLOW.led_pin.pin = GPIO_PIN_1;
	LED_Init(&YELLOW);
	GREEN.led_mode = LED_MODE_ActiveLow;
	GREEN.led_pin.GPIOx = GPIOA;
	GREEN.led_pin.default_state = GPIO_STATE_HIGH;
	GREEN.led_pin.direction = GPIO_OUTPUT;
	GREEN.led_pin.pin = GPIO_PIN_2;
	LED_Init(&GREEN);
	while(1){
		LED_TurnOn(&RED);
		for(index = 10; index >= 0; index--){
			SS_Display(&SS1, index%10);
			SS_Display(&SS2, index/10);
			_delay_ms(1000);
		}
		LED_TurnOff(&RED);
		LED_TurnOn(&YELLOW);
		for(index = 3; index >= 0; index--){
			SS_Display(&SS1, index%10);
			SS_Display(&SS2, index/10);
			_delay_ms(1000);
		}
		LED_TurnOff(&YELLOW);
		LED_TurnOn(&GREEN);
		for(index = 10; index >= 0; index--){
			SS_Display(&SS1, index%10);
			SS_Display(&SS2, index/10);
			_delay_ms(1000);
		}
		LED_TurnOff(&GREEN);
	}
	return 0;
}
