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

void flashing(void);
void shift_right(void);
void shift_left(void);
void converge(void);
void diverge(void);
void ping_ping(void);
void snake(void);
void converge_diverge(void);

int main(void){
	GPIO_PORT_Init(GPIOC, 0x00, 0xFF);
	GPIO_PORT_Init(GPIOD, 0xFF, 0x00);
	uint8 port_state;
	while(1){
		GPIO_PORT_Read(GPIOC, &port_state);
		switch(port_state){
		case 0xFE:
			flashing();
			break;
		case 0xFD:
			shift_left();
			break;
		case 0xFB:
			shift_right();
			break;
		case 0xF7:
			converge();
			break;
		case 0xEF:
			diverge();
			break;
		case 0xDF:
			ping_ping();
			break;
		case 0xBF:
			snake();
			break;
		case 0x7F:
			converge_diverge();
			break;
		default:
			GPIO_PORT_Write(GPIOD, 0x00);
			break;
		}
	}
	return 0;
}

void flashing(void){
	GPIO_PORT_Write(GPIOD, 0xFF);
	_delay_ms(500);
	GPIO_PORT_Write(GPIOD, 0x00);
	_delay_ms(500);
}

void shift_right(void){
	uint8 index;
	for(index = 0; index < 8; index++){
		GPIO_PORT_Write(GPIOD, (1U<<(7-index)));
		_delay_ms(250);
	}
	GPIO_PORT_Write(GPIOD, 0x00);
}

void shift_left(void){
	uint8 index;
	for(index = 0; index < 8; index++){
		GPIO_PORT_Write(GPIOD, (1U<<index));
		_delay_ms(250);
	}
	GPIO_PORT_Write(GPIOD, 0x00);
}

void converge(void){
	uint8 index;
	for(index = 0; index < 4; index++){
		GPIO_PORT_Write(GPIOD, ( (1U<<index) | (1U<<(7 - index)) ));
		_delay_ms(300);
	}
	GPIO_PORT_Write(GPIOD, 0x00);
}

void diverge(void){
	sint8 index;
	for(index = 3; index >= 0; index--){
		GPIO_PORT_Write(GPIOD, ( (1U<<index) | (1U<<(7 - index)) ));
		_delay_ms(300);
	}
	GPIO_PORT_Write(GPIOD, 0x00);
}

void ping_ping(void){
	sint8 index;
	for(index = 0; index < 8; index++){
		GPIO_PORT_Write(GPIOD, (1U<<index));
		_delay_ms(250);
	}
	for(index = 0; index < 8; index++){
		GPIO_PORT_Write(GPIOD, (1U<<(7-index)));
		_delay_ms(250);
	}
	GPIO_PORT_Write(GPIOD, 0x00);
}

void snake(void){
	uint8 index;
	for(index = 0; index < 8; index++){
		GPIO_PORT_Write(GPIOD, GPIOD->PORT | (1U<<index));
		_delay_ms(300);
	}
	for(index = 0; index < 8; index++){
		GPIO_PORT_Write(GPIOD, GPIOD->PORT & ~(1U<<index));
		_delay_ms(300);
	}
}

void converge_diverge(void){
	sint8 index;
	for(index = 0; index < 4; index++){
		GPIO_PORT_Write(GPIOD, ( (1U<<index) | (1U<<(7 - index)) ));
		_delay_ms(300);
	}
	for(index = 3; index >= 0; index--){
		GPIO_PORT_Write(GPIOD, ( (1U<<index) | (1U<<(7 - index)) ));
		_delay_ms(300);
	}
	GPIO_PORT_Write(GPIOD, 0x00);
}
