#include <stdio.h>

int main(){
	int saved_ID = 5555, saved_PW = 6666;
	int user_ID, user_PW;
	printf("Enter your ID: ");
	scanf("%d", &user_ID);
	if(user_ID == saved_ID){
		printf("Enter your password: ");
		scanf("%d", &user_PW);
		if(user_PW == saved_PW){
			printf("%d", saved_ID);
		}
		else{
			printf("Incorrect Password\n");
		}
	}
	else{
		printf("Incorrect ID\n");
	}
	return 0;
}