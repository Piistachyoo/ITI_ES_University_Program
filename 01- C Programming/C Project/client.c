/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : client.c                                              */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "client.h"

void client_main(void){
	uint8 fail_login_count = 0;
	uint8 user_entry;
	uint64 bank_ID_entry;
	uint16 password_entry;
	account_t *client_account;
	uint8 login_successful_flag = 0;
	system("cls");
	printf("Welcome to client mode\n");
	printf("---------------------\n\n");
	while(MAX_LOGIN_TRIES > fail_login_count){
		printf("Enter your bank ID: ");
		FLUSH_BUFFER();
		scanf("%llu", &bank_ID_entry);
		printf("Enter your password: ");
		FLUSH_BUFFER();
		scanf("%hu", &password_entry);
		get_account_info(bank_ID_entry, &client_account);
		if(NULL != client_account){
			if(password_entry == client_account->password){
				login_successful_flag = 1;
				break;
			}
			else{
				fail_login_count++;
				printf("Wrong login credentials, %d attempts left!\n\n", MAX_LOGIN_TRIES - fail_login_count);
			}
		}
		else{
			fail_login_count++;
			printf("Wrong login credentials, %d attempts left!\n\n", MAX_LOGIN_TRIES - fail_login_count);
		}
	}
	if(MAX_LOGIN_TRIES <= fail_login_count){
		printf("You entered wrong credentials %d times, exiting client mode!\n", MAX_LOGIN_TRIES);
		Block_getchar();
	}
	else if(login_successful_flag){
		do{
			system("cls");
			printf("Welcome to client mode, %s!\n", client_account->name);
			printf("----------------------\n\n");
			printf("Press 1 to make a transaction to another account\n");
			printf("Press 2 to change account password\n");
			printf("Press 3 to withdraw cash from account\n");
			printf("Press 4 to deposit cash to account\n");
			printf("Press 0 to exit client mode\n");
			FLUSH_BUFFER();
			scanf("%d", (int*)&user_entry);
			if(1 == user_entry){
				make_transaction(client_account);
			}
			else if(2 == user_entry){
				change_password(client_account);
			}
			else if(3 == user_entry){
				get_cash(client_account);
			}
			else if(4 == user_entry){
				deposit_cash(client_account);
			}
			else if(0 == user_entry){
				printf("Exiting client mode!\n");
				Block_getchar();
			}
			else{
				printf("\nWrong choice, please enter a correct option!\n\n");
				Block_getchar();
			}
		}while(user_entry);
	}
	else{ /* Do Nothing */ }
}
