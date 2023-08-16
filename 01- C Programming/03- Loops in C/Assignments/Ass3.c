#include <stdio.h>

int main(){
	int i, j, num;
	int star = 1;
	printf("Please Enter the height of the pyramid: ");
	scanf("%d", &num);
	for(j = 0; j < num; j++){
		for(i = (num - j - 1); i > 0; i--){
			printf(" ");
		}
		for(i = 0; i < star; i++){
			printf("*");
		}
		star += 2;
		printf("\n");
	}
	return 0;
}