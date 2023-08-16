#include <stdio.h>

int main(){
	int n1, n2;
	while(1){
		printf("Please enter first number: ");
		scanf("%d", &n1);
		printf("Please enter second number: ");
		scanf("%d", &n2);
		printf("The result is %d\n\n", n1+n2);
	}
	return 0;
}