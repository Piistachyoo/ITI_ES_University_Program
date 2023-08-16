#include <stdio.h>

int main(){
	int num, i;
	printf("Enter the number to display its multiplication table: ");
	scanf("%d", &num);
	while(i <= 10){
		printf("%d X %d = %d\n", num, i, num*i);
		i++;
	}
	return 0;
}