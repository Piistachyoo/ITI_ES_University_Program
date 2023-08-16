/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : admin.c                                               */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "admin.h"

//----------------------------------------------
// Section: Static APIs Declarations
//----------------------------------------------
static void Create_New_Account(void);
static void Open_Existing_Account(void);

//----------------------------------------------
// Section: APIs Definitions
//----------------------------------------------
void admin_main(void){
	uint8 user_entry;
	uint8 login_successful_flag = 0;
	uint8 fail_login_count = 0;
	uint16 username_entry, password_entry;
	system("cls");
	printf("Welcome to admin mode\n");
	printf("---------------------\n\n");
	while(MAX_LOGIN_TRIES > fail_login_count){
		printf("Enter admin username: ");
		FLUSH_BUFFER();
		scanf("%hu", &username_entry);
		printf("Enter admin password: ");
		FLUSH_BUFFER();
		scanf("%hu", &password_entry);
		if( (ADMIN_USERNAME == username_entry) && (ADMIN_PASSWORD == password_entry) ){
			login_successful_flag = 1;
			break;
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
		printf("Welcome to admin mode!\n");
		printf("----------------------\n\n");
		printf("Press 1 to create a new account\n");
		printf("Press 2 to open an existing account\n");
		printf("Press 3 to display all accounts\n");
		printf("Press 0 to exit admin mode\n\n");
		FLUSH_BUFFER();
		scanf("%d", (int*)&user_entry);
		if(1 == user_entry){
			Create_New_Account();
		}
		else if(2 == user_entry){
			Open_Existing_Account();
		}
		else if(3 == user_entry){
			display_all_accounts();
		}
		else if(0 == user_entry){
			printf("Exiting admin mode!\n");
			Block_getchar();
		}
		else{
			printf("\nWrong choice, please enter a correct option!\n\n");
			Block_getchar();
		}
	}while(user_entry);
	}
}

static void Create_New_Account(void){
	uint8 index, space_counter;
	uint8 valid_flag = 0;
	uint64 temp_number;
	account_t new_acc = {0};
	system("cls");
	printf("Welcome to admin mode!\n");
	printf("----------------------\n\n");
	printf("Create a new account :-\n");
	printf("Enter address: ");
	FLUSH_BUFFER();
	getchar();
	gets((char*)new_acc.address);
	printf("Enter age: ");
	FLUSH_BUFFER();
	scanf("%d", (int*)&new_acc.age);
	valid_flag = 0;
	while(!valid_flag){
		printf("Enter full name (four names or more): ");
		FLUSH_BUFFER();
		getchar();
		gets((char*)new_acc.name);
		/* Check if user entered 4 names */
		space_counter = 0;
		for(index = 0; ( (index < 100) && ('\0' != new_acc.name[index]) ); index++){
			if(' ' == new_acc.name[index])
				space_counter++;
		}
		if(3 > space_counter){
			printf("ERROR: Name must be four names or more!\n\n");
			valid_flag = 0;
		}
		else
			valid_flag = 1;
	}
/*	printf("Enter address: ");
	getchar();
	FLUSH_BUFFER();
	gets((char*)new_acc.name);*/

//	strcpy((char*)new_acc.name, (char*)temp_array);


	printf("Enter National ID: ");
	FLUSH_BUFFER();
	scanf("%llu", &new_acc.national_ID);
	new_acc.guardian = (21 > new_acc.age) ? 1 : 0;
	if(new_acc.guardian){
		printf("Enter guardian ID: ");
		FLUSH_BUFFER();
		scanf("%llu", &new_acc.guardian_ID);
	}
	else
		new_acc.guardian_ID = 0;
	printf("Enter balance: ");
	FLUSH_BUFFER();
	scanf("%lf", &new_acc.balance);
	/* Generate 4 digit password (pin) */
	temp_number = 0;
	srand(time(0));
	for(index = 0; index < 4; index++){
		temp_number += ((rand() % 9) + 1);
		temp_number *= 10;
	}
	temp_number /= 10;
	new_acc.password = (uint16)temp_number;

	/* Generate 10 digit bank ID */
	/* Make sure it is not repeated */
	do{
		temp_number = 0;
		for(index = 0; index < 10; index++){
			temp_number += ((rand() % 9) + 1);
			temp_number *= 10;
		}
		temp_number /= 10;
	}while(ID_FOUND == check_id_valid(temp_number));
	new_acc.bank_ID = temp_number;
	new_acc.status = ACCOUNT_ACTIVE;
	printf("\nAccount has been created!\n");
	printf("Your bank ID is: %llu\n", new_acc.bank_ID);
	printf("Your password is: %hu\n", new_acc.password);
	add_new_account(&new_acc);
	Block_getchar();
}

static void Open_Existing_Account(void){
	uint8 user_entry;
	uint64 entered_ID;
	account_t *chosen_account;
	system("cls");
	printf("Welcome to admin mode!\n");
	printf("----------------------\n\n");
	printf("Open an existing account :-\n");
	printf("Enter bank ID: ");
	FLUSH_BUFFER();
	scanf("%llu", &entered_ID);
	get_account_info(entered_ID, &chosen_account);
	if(NULL == chosen_account){
		printf("ERROR: account not found!\n");
		Block_getchar();
	}
	else{
		printf("Press 1 to make a transaction to another account\n");
		printf("Press 2 to change account status\n");
		printf("Press 3 to withdraw cash from account\n");
		printf("Press 4 to deposit cash to account\n");
		printf("Press 0 to cancel\n\n");
		do{
			printf("Your choice: ");
			FLUSH_BUFFER();
			scanf("%d", (int*)&user_entry);
			switch(user_entry){
			case 0:
				printf("Operation is canceled!\n");
				Block_getchar();
				break;
			case 1:
				make_transaction(chosen_account);
				user_entry = 0; // to exit do-while loop
				break;
			case 2:
				change_account_status(chosen_account);
				user_entry = 0; // to exit do-while loop
				break;
			case 3:
				get_cash(chosen_account);
				user_entry = 0; // to exit do-while loop
				break;
			case 4:
				deposit_cash(chosen_account);
				user_entry = 0; // to exit do-while loop
				break;
			default:
				printf("\nWrong choice, please enter a correct option!\n\n");
				break;
			}
		}while(user_entry);
	}
}


