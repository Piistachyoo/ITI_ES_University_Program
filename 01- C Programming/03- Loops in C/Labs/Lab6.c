#include <stdio.h>

int main(){
	int number, result = 1;
	printf("Enter an integer: ");
	scanf("%d", &number);
	if(0 != number){
		do{
			result *= number;
			number--;
		}while(number);
	}
	else{ /* Do Nothing */ }
	printf("Factorial = %d", result);
}