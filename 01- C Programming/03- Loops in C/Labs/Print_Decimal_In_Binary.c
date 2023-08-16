#include <stdio.h>

int main(){
	char size, number;
	printf("Enter a number: ");
	scanf("%d", &number);
	size = sizeof(number)*8;
	for(int i = size-1; i >= 0; i--){
		//(number & (1U<<i)) ? (printf("1")) : (printf("0"));
			printf("%d", ((number>>i)&1));
		if(i%4 == 0)
				printf(" ");
	}
}