/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/LCD/LCD_interface.h"
#include "util/delay.h"
GPIO_Typedef *mygpio = GPIOC;

int main(void){
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

	while(1){
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_FIRST_ROW, 1);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_SECOND_ROW, 2);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_FIRST_ROW, 3);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_SECOND_ROW, 4);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_FIRST_ROW, 5);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_SECOND_ROW, 6);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_FIRST_ROW, 7);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_SECOND_ROW, 8);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_FIRST_ROW, 9);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_SECOND_ROW, 10);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_FIRST_ROW, 11);
		_delay_ms(200);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		LCD_Send_string_Pos(&LCD2, (uint8*)"Omar", LCD_SECOND_ROW, 12);
		_delay_ms(1000);
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
	}
	return 0;
}

