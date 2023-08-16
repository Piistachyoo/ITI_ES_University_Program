#include <stdio.h>

int main(){
	int answer;

	printf("Enter the answer of 3 x 4 = ");
	scanf("%d", &answer);
	while(answer != 12){
		printf("Not correct, Please try again: ");
		scanf("%d", &answer);
	}
	printf("Thank You\n");
	return 0;
}