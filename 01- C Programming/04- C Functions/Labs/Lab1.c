#include <stdio.h>

int max(int n1, int n2){
	return (n1>n2) ? n1 : n2;
}

int main(){
	int a, b;
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);
	printf("The maximum value is %d", max(a,b));
	return 0;
}