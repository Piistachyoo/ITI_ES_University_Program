#include <stdio.h>

int factorial(int number);

int main(){
	long long fact, number;
	printf("Enter a number: ");
	scanf("%d", &number);
	fact = factorial(number);
	printf("Factorial of %d is %d", number, fact);
	return 0;
}

int factorial(int number){
	return (number > 0) ? (number * factorial(number-1)) : 1;
}
