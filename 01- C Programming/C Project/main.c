/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "main.h"

static main_states main_currState = STATE_INIT;

int main(void){
	int user_entry = 99; // Dummy initialization to avoid exiting system early on
	uint8 quit_flag = 0;
	while(user_entry){
		switch(main_currState){
		case STATE_INIT:
			import_database();
			main_currState = STATE_IDLE;
			break;
		case STATE_IDLE:
			system("cls");
			printf("Welcome to IMT Bank System!\n");
			printf("---------------------------\n\n");
			printf("Press 1 to access admin window\n");
			printf("Press 2 to access client window\n");
			printf("Press 0 to exit the program\n\n");
			printf("Your choice: ");
			FLUSH_BUFFER();
			scanf("%d", &user_entry);
			if(0 == user_entry){
				printf("\nThank you for using our system!\n\n");
				quit_flag = 1;
			}
			else if(1 == user_entry){
				main_currState = STATE_ADMIN;
			}
			else if(2 == user_entry){
				main_currState = STATE_CLIENT;
			}
			else{
				printf("\nWrong choice, please enter a correct option!\n");
				Block_getchar();
			}
			break;
		case STATE_ADMIN:
			admin_main();
			main_currState = STATE_IDLE;
			break;
		case STATE_CLIENT:
			client_main();
			main_currState = STATE_IDLE;
			break;
		default:
			main_currState = STATE_IDLE; // In case of failure, reset to idle state
			break;
		}
		if(quit_flag)
			break;
	};
	return 0;
}
