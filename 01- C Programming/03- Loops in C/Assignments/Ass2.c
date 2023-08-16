#include <stdio.h>

int main(){
	int entered_id, entered_psw, tries;
	printf("Please Enter your ID: ");
	scanf("%d", &entered_id);
	switch(entered_id){
	case 1234:
		tries = 0;
		printf("Please Enter Password: ");
		while(1){
			scanf("%d", &entered_psw);
			if(entered_psw == 7788){
				printf("Welcome Ahmed\n");
				break;
			}
			else{
				tries++;
				if(tries == 3){
					printf("Incorrect password for 3 times, No more tries\n");
					break;
				}
				else{
					printf("Try again: ");
				}
			}
		}
		break;
	case 5678:
		tries = 0;
		printf("Please Enter Password: ");
		while(1){
			scanf("%d", &entered_psw);
			if(entered_psw == 5566){
				printf("Welcome Amr\n");
				break;
			}
			else{
				tries++;
				if(tries == 3){
					printf("Incorrect password for 3 times, No more tries\n");
					break;
				}
				else{
					printf("Try again: ");
				}
			}
		}
		break;
	case 9870:
		tries = 0;
		printf("Please Enter Password: ");
		while(tries != 3){
			scanf("%d", &entered_psw);
			if(entered_psw == 1122){
				printf("Welcome Wael\n");
				break;
			}
			else{
				tries++;
				if(tries == 3){
					printf("Incorrect password for 3 times, No more tries\n");
					break;
				}
				else{
					printf("Try again: ");
				}
			}
		}
		break;
	default: printf("You are not registered\n");
	}
	return 0;
}