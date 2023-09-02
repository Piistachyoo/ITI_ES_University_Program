/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/keypad_interface.h"
#include "util/delay.h"
GPIO_Typedef *mygpio = GPIOC;



int main(void){
	uint8 SW1_STATE, SW2_STATE;
	LCD_t LCD2;
	LCD2.mode = LCD_4BIT;
	LCD2.Display_Mode = LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	LCD2.Entry_Mode = LCD_ENTRY_MODE_INC_SHIFT_OFF;
	LCD2.RS_PIN.GPIOx = GPIOD;
	LCD2.RS_PIN.direction = GPIO_OUTPUT;
	LCD2.RS_PIN.pin = GPIO_PIN_3;
	LCD2.RS_PIN.default_state = GPIO_STATE_LOW;
	LCD2.RW_PIN.GPIOx = GPIOD;
	LCD2.RW_PIN.direction = GPIO_OUTPUT;
	LCD2.RW_PIN.pin = GPIO_PIN_4;
	LCD2.RW_PIN.default_state = GPIO_STATE_LOW;
	LCD2.EN_PIN.GPIOx = GPIOD;
	LCD2.EN_PIN.direction = GPIO_OUTPUT;
	LCD2.EN_PIN.pin = GPIO_PIN_5;
	LCD2.EN_PIN.default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[0].GPIOx = GPIOD;
	LCD2.D_PINS[0].direction = GPIO_OUTPUT;
	LCD2.D_PINS[0].pin = GPIO_PIN_6;
	LCD2.D_PINS[0].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[1].GPIOx = GPIOD;
	LCD2.D_PINS[1].direction = GPIO_OUTPUT;
	LCD2.D_PINS[1].pin = GPIO_PIN_7;
	LCD2.D_PINS[1].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[2].GPIOx = GPIOB;
	LCD2.D_PINS[2].direction = GPIO_OUTPUT;
	LCD2.D_PINS[2].pin = GPIO_PIN_7;
	LCD2.D_PINS[2].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[3].GPIOx = GPIOB;
	LCD2.D_PINS[3].direction = GPIO_OUTPUT;
	LCD2.D_PINS[3].pin = GPIO_PIN_6;
	LCD2.D_PINS[3].default_state = GPIO_STATE_LOW;
	LCD_Init(&LCD2);
	LCD_Send_String(&LCD2, (uint8*)"Direction: ");
	pinCfg_t IN1 = {.GPIOx = GPIOC, .direction = GPIO_OUTPUT, .pin = GPIO_PIN_0, .default_state = GPIO_STATE_LOW};
	pinCfg_t IN2 = {.GPIOx = GPIOC, .direction = GPIO_OUTPUT, .pin = GPIO_PIN_1, .default_state = GPIO_STATE_LOW};
	GPIO_PIN_Init(&IN1);
	GPIO_PIN_Init(&IN2);
	pinCfg_t SW1 = {.GPIOx = GPIOA, .direction = GPIO_INPUT, .pin = GPIO_PIN_0, .default_state = GPIO_STATE_LOW};
	pinCfg_t SW2 = {.GPIOx = GPIOA, .direction = GPIO_INPUT, .pin = GPIO_PIN_1, .default_state = GPIO_STATE_LOW};
	GPIO_PIN_Init(&SW1);
	GPIO_PIN_Init(&SW2);
	while(1){
		GPIO_PIN_Read(&SW1, &SW1_STATE);
		GPIO_PIN_Read(&SW2, &SW2_STATE);
		if((GPIO_STATE_LOW == SW1_STATE) && (GPIO_STATE_HIGH == SW2_STATE)){
			GPIO_PIN_Write(&IN1, GPIO_STATE_HIGH);
			GPIO_PIN_Write(&IN2, GPIO_STATE_LOW);
			LCD_Send_string_Pos(&LCD2, (uint8*)"       ", LCD_FIRST_ROW, 11);
			LCD_Send_string_Pos(&LCD2, (uint8*)"Right", LCD_FIRST_ROW, 11);
		}
		else if((GPIO_STATE_HIGH == SW1_STATE) && (GPIO_STATE_LOW == SW2_STATE)){
			GPIO_PIN_Write(&IN1, GPIO_STATE_LOW);
			GPIO_PIN_Write(&IN2, GPIO_STATE_HIGH);
			LCD_Send_string_Pos(&LCD2, (uint8*)"       ", LCD_FIRST_ROW, 11);
			LCD_Send_string_Pos(&LCD2, (uint8*)"Left", LCD_FIRST_ROW, 11);
		}
		else{
			GPIO_PIN_Write(&IN1, GPIO_STATE_LOW);
			GPIO_PIN_Write(&IN2, GPIO_STATE_LOW);
			LCD_Send_string_Pos(&LCD2, (uint8*)"       ", LCD_FIRST_ROW, 11);
			LCD_Send_string_Pos(&LCD2, (uint8*)"Stopped", LCD_FIRST_ROW, 11);
		}
		_delay_ms(250);
	}
	return 0;
}

