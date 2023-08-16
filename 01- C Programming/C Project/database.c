/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : IMT_Bank_System                                    	 */
/* File          : database.c                                            */
/* Date          : Aug 16, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "database.h"

static account_t *HEAD = NULL;

void add_new_account(account_t *pAccount){
	account_t *new = (account_t*)malloc(sizeof(account_t));
	if(NULL != new){
		*new = *pAccount;
		if(NULL == HEAD){
			new->next = NULL;
		}
		else{
			new->next = HEAD;
		}
		HEAD = new;
		export_database();
	}
	else{ /* Do Nothing */ }
}

void display_all_accounts(void){
	uint8 account_counter = 0;
	account_t *iterator = HEAD;
	system("cls");
	printf("Display all accounts\n");
	printf("--------------------\n\n");
	if(NULL == iterator){
		printf("ERROR: No accounts found!\n");
		Block_getchar();
	}
	else{
		while(iterator){
			print_account_details(iterator);
			printf("\n===========\n\n");
			iterator = iterator->next;
			account_counter++;
		}
		printf("%d accounts found!\n", account_counter);
		Block_getchar();
	}
}



uint8 check_id_valid(uint64 _ID){
	uint8 ret_val = ID_NOT_FOUND;
	account_t *iterator = HEAD;
	while(iterator){
		if(_ID == iterator->bank_ID){
			ret_val = ID_FOUND;
			break;
		}
		else{ /* Do Nothing */ }
		iterator = iterator->next;
	}
	return ret_val;
}

void get_account_info(uint64 _ID, account_t **retAccount){
	account_t *iterator = HEAD;
	*retAccount = NULL;
	while(iterator){
		if(_ID == iterator->bank_ID){
			*retAccount = iterator;
			break;
		}
		else{ /* Do Nothing */ }
		iterator = iterator->next;
	}
}

void print_account_details(account_t *pAccount){
	printf("\nAccount details:\n");
	printf("----------------\n\n");
	if(ACCOUNT_ACTIVE == pAccount->status){
		printf("Account status: Active\n");
	}
	else if(ACCOUNT_RESTRICTED == pAccount->status){
		printf("Account status: Restricted\n");
	}
	else if(ACCOUNT_CLOSED == pAccount->status){
		printf("Account status: Closed\n");
	}
	printf("Balance: %.2f\n", pAccount->balance);
	printf("Bank ID: %llu\n", pAccount->bank_ID);
	printf("Password: %hu\n", pAccount->password);
	printf("----------------\n");
	printf("Name: %s\n", pAccount->name);
	printf("Age: %hu\n", pAccount->age);
	printf("Address: %s\n", pAccount->address);
	printf("National ID: %llu\n", pAccount->national_ID);
	if(pAccount->guardian){
		printf("Guardian ID: %llu\n", pAccount->guardian_ID);
	}
	else{
		printf("Guardian: NO\n");
	}
	printf("----------------\n");
}

void import_database(void){
	FILE *file = fopen("accounts_database.txt", "r");
	account_t new_account;
	if(NULL != file){
		while(fread(&new_account, sizeof(account_t), 1, file)){
			add_new_account(&new_account);
		}
		fclose(file);
	}
	else{ /* Do Nothing */ }
}

void export_database(void){
	FILE *file = fopen("accounts_database.txt", "w");
	account_t *iterator = HEAD;
	while(iterator){
		fwrite(iterator, sizeof(account_t), 1, file);
		iterator = iterator->next;
	}
	fclose(file);
}

void make_transaction(account_t *pAccount){
	uint64 destination_ID;
	double transaction_amount;
	account_t *destination_account;
	printf("Enter the Bank ID you want to transfer money to: ");
	FLUSH_BUFFER();
	scanf("%llu", &destination_ID);
	get_account_info(destination_ID, &destination_account);
	if(NULL == destination_account){
		printf("ERROR: Account not found!\n");
	}
	else{
		printf("Enter amount you want to transfer: ");
		FLUSH_BUFFER();
		scanf("%lf", &transaction_amount);
		if(transaction_amount > pAccount->balance){
			printf("ERROR: Balance not sufficient!\n");
		}
		else{
			if( (ACCOUNT_ACTIVE != pAccount->status) || (ACCOUNT_ACTIVE != destination_account->status) ){
				printf("ERROR: Both accounts must be active in order to do transaction\n");
			}
			else{
				pAccount->balance -= transaction_amount;
				destination_account->balance += transaction_amount;
				printf("%.2f was sent successfully!\n", transaction_amount);
				printf("New balance: %.2f\n", pAccount->balance);
				export_database();
			}
		}
	}
	Block_getchar();
}

void change_account_status(account_t *pAccount){
	uint8 user_entry;
	if(ACCOUNT_ACTIVE == pAccount->status){
		printf("Current account status is active!\n");
		printf("Enter 1 to change account status to restricted\n");
		printf("Enter 2 to change account status to closed\n");
		printf("Enter 0 to cancel\n");
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
				pAccount->status = ACCOUNT_RESTRICTED;
				printf("Account status changed successfully!\n");
				Block_getchar();
				user_entry = 0; // to exit do-while loop
				break;
			case 2:
				pAccount->status = ACCOUNT_CLOSED;
				printf("Account status changed successfully!\n");
				Block_getchar();
				user_entry = 0; // to exit do-while loop
				break;
			default:
				printf("\nWrong choice, please enter a correct option!\n\n");
				break;
			}
			export_database();
		}while(user_entry);
	}
	else if(ACCOUNT_RESTRICTED == pAccount->status){
		printf("Current account status is restricted!\n");
		printf("Enter 1 to change account status to active\n");
		printf("Enter 2 to change account status to closed\n");
		printf("Enter 0 to cancel\n");
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
				pAccount->status = ACCOUNT_ACTIVE;
				printf("Account status changed successfully!\n");
				Block_getchar();
				user_entry = 0; // to exit do-while loop
				break;
			case 2:
				pAccount->status = ACCOUNT_CLOSED;
				printf("Account status changed successfully!\n");
				Block_getchar();
				user_entry = 0; // to exit do-while loop
				break;
			default:
				printf("\nWrong choice, please enter a correct option!\n\n");
				break;
			}
			export_database();
		}while(user_entry);
	}
	else if(ACCOUNT_CLOSED == pAccount->status){
		printf("Current account status is closed!\n");
		printf("Enter 1 to change account status to active\n");
		printf("Enter 2 to change account status to restricted\n");
		printf("Enter 0 to cancel\n");
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
				pAccount->status = ACCOUNT_ACTIVE;
				printf("Account status changed successfully!\n");
				Block_getchar();
				user_entry = 0; // to exit do-while loop
				break;
			case 2:
				pAccount->status = ACCOUNT_RESTRICTED;
				printf("Account status changed successfully!\n");
				Block_getchar();
				user_entry = 0; // to exit do-while loop
				break;
			default:
				printf("\nWrong choice, please enter a correct option!\n\n");
				break;
			}
			export_database();
		}while(user_entry);
	}
}

void get_cash(account_t *pAccount){
	double withdraw_amount;
	printf("Enter amount of cash to withdraw from account: ");
	FLUSH_BUFFER();
	scanf("%lf", &withdraw_amount);
	if(withdraw_amount > pAccount->balance){
		printf("ERROR: Balance not sufficient!\n");
	}
	else{
		pAccount->balance -= withdraw_amount;
		printf("%.2f was withdrawed successfully!\n", withdraw_amount);
		printf("New balance: %.2f\n", pAccount->balance);
		export_database();
	}
	Block_getchar();
}

void deposit_cash(account_t *pAccount){
	double deposit_amount;
	printf("Enter amount of cash to deposit to account: ");
	FLUSH_BUFFER();
	scanf("%lf", &deposit_amount);
	pAccount->balance += deposit_amount;
	printf("%.2f was deposited successfully!\n", deposit_amount);
	printf("New balance: %.2f\n", pAccount->balance);
	export_database();
	Block_getchar();
}

void change_password(account_t *pAccount){
	uint16 password_entry;
	printf("Enter your old password: ");
	FLUSH_BUFFER();
	scanf("%hu", &password_entry);
	if(password_entry == pAccount->password){
		printf("Enter your new password: ");
		FLUSH_BUFFER();
		scanf("%hu", &pAccount->password);
		printf("Password changed successfully!\n");
		export_database();
	}
	else{
		printf("ERROR: You entered wrong password\n");
	}
	Block_getchar();
}
