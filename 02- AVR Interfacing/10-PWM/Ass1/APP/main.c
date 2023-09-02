/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : LEC10_ASS1                                    	 	 */
/* File          : main.c                           					 */
/* Date          : Sep 2, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/SERVO/servo_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/keypad_interface.h"
#include <string.h>
#define F_CPU	8000000UL


int main(){
	LCD_t LCD2;
	LCD2.mode = LCD_4BIT;
	LCD2.Display_Mode = LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	LCD2.Entry_Mode = LCD_ENTRY_MODE_INC_SHIFT_OFF;
	LCD2.RS_PIN.GPIOx = GPIOC;
	LCD2.RS_PIN.direction = GPIO_OUTPUT;
	LCD2.RS_PIN.pin = GPIO_PIN_0;
	LCD2.RS_PIN.default_state = GPIO_STATE_LOW;
	LCD2.RW_PIN.GPIOx = GPIOC;
	LCD2.RW_PIN.direction = GPIO_OUTPUT;
	LCD2.RW_PIN.pin = GPIO_PIN_1;
	LCD2.RW_PIN.default_state = GPIO_STATE_LOW;
	LCD2.EN_PIN.GPIOx = GPIOC;
	LCD2.EN_PIN.direction = GPIO_OUTPUT;
	LCD2.EN_PIN.pin = GPIO_PIN_2;
	LCD2.EN_PIN.default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[0].GPIOx = GPIOC;
	LCD2.D_PINS[0].direction = GPIO_OUTPUT;
	LCD2.D_PINS[0].pin = GPIO_PIN_3;
	LCD2.D_PINS[0].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[1].GPIOx = GPIOC;
	LCD2.D_PINS[1].direction = GPIO_OUTPUT;
	LCD2.D_PINS[1].pin = GPIO_PIN_4;
	LCD2.D_PINS[1].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[2].GPIOx = GPIOC;
	LCD2.D_PINS[2].direction = GPIO_OUTPUT;
	LCD2.D_PINS[2].pin = GPIO_PIN_5;
	LCD2.D_PINS[2].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[3].GPIOx = GPIOC;
	LCD2.D_PINS[3].direction = GPIO_OUTPUT;
	LCD2.D_PINS[3].pin = GPIO_PIN_6;
	LCD2.D_PINS[3].default_state = GPIO_STATE_LOW;
	KPD_t KPD1;
	KPD1.row[0].GPIOx = GPIOA;
	KPD1.row[0].direction = GPIO_INPUT;
	KPD1.row[0].pin = GPIO_PIN_0;
	KPD1.row[0].default_state = GPIO_STATE_HIGH;
	KPD1.row[1].GPIOx = GPIOA;
	KPD1.row[1].direction = GPIO_INPUT;
	KPD1.row[1].pin = GPIO_PIN_1;
	KPD1.row[1].default_state = GPIO_STATE_HIGH;
	KPD1.row[2].GPIOx = GPIOA;
	KPD1.row[2].direction = GPIO_INPUT;
	KPD1.row[2].pin = GPIO_PIN_2;
	KPD1.row[2].default_state = GPIO_STATE_HIGH;
	KPD1.row[3].GPIOx = GPIOA;
	KPD1.row[3].direction = GPIO_INPUT;
	KPD1.row[3].pin = GPIO_PIN_3;
	KPD1.row[3].default_state = GPIO_STATE_HIGH;
	KPD1.col[0].GPIOx = GPIOA;
	KPD1.col[0].direction = GPIO_OUTPUT;
	KPD1.col[0].pin = GPIO_PIN_4;
	KPD1.col[0].default_state = GPIO_STATE_LOW;
	KPD1.col[1].GPIOx = GPIOA;
	KPD1.col[1].direction = GPIO_OUTPUT;
	KPD1.col[1].pin = GPIO_PIN_5;
	KPD1.col[1].default_state = GPIO_STATE_LOW;
	KPD1.col[2].GPIOx = GPIOA;
	KPD1.col[2].direction = GPIO_OUTPUT;
	KPD1.col[2].pin = GPIO_PIN_6;
	KPD1.col[2].default_state = GPIO_STATE_LOW;
	KPD1.col[3].GPIOx = GPIOA;
	KPD1.col[3].direction = GPIO_OUTPUT;
	KPD1.col[3].pin = GPIO_PIN_7;
	KPD1.col[3].default_state = GPIO_STATE_LOW;
	SERVO_PWM_cfg_t SERVO1 = {
			.ServoPWM.PWM_TimerChannel = TIMER1_FastICR,
			.ServoPWM.PWM_TimerPrescale  = PRE_64,
			.ServoPWM.PWM_ToggleMode  = PWM_OCmode,
			.ServoPWM.PWM_InvertOrNot   = PWM_NonInvertingMode,
			.ServoInitialDirection = SERVO_0,
			.ICR_Value = 2500,
			.OCR_0degree_Value = 100,
			.OCR_90degree_Value = 188,
			.OCR_180degree_Value = 250
	};
	keypad_init(&KPD1);
	LCD_Init(&LCD2);
	SERVO_vInit(&SERVO1);
	SERVO_vStart(&SERVO1);
	u8 key_buffer, result;
	u8 buffer_array[10];
	u8 array_len=0;
	while(1){
		memset(buffer_array, 0, 10);
		result = 0;
		array_len = 0;
		LCD_Send_Command(&LCD2, LCD_CLEAR_DISPLAY);
		do{
			keypad_Get_Pressed_Key(&KPD1, &key_buffer);
			if(key_buffer != 'F'){
				LCD_Send_Char(&LCD2, key_buffer);
				buffer_array[array_len] = key_buffer;
				array_len++;
			}
		}while(key_buffer != '=');
		/*for(int i = 0; i < array_len; i++){
			result += buffer_array[i];
			result *= 10;
		}*/
		//result /= 10;
		result = atoi(buffer_array);
		if(result == 0){
			SERVO_vChangeDirection(&SERVO1, SERVO_0);
		}
		else if(result == 90){
			SERVO_vChangeDirection(&SERVO1, SERVO_90);
		}
		else if(result == 180){
			SERVO_vChangeDirection(&SERVO1, SERVO_180);
		}

	}
	return 0;
}
