#include <stdio.h>

int get_max(int a, int b, int c, int d);
int get_min(int a, int b, int c, int d);

int main(){
	int n1, n2, n3, n4;
	printf("Enter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	printf("Enter third number: ");
	scanf("%d", &n3);
	printf("Enter fourth number: ");
	scanf("%d", &n4);
	printf("Maximum number = %d\n", get_max(n1, n2, n3, n4));
	printf("Minimum number = %d\n", get_min(n1, n2, n3, n4));
	return 0;
}

int get_max(int a, int b, int c, int d){
	int max = a;
	max = (b > max) ? b : max;
	max = (c > max) ? c : max;
	max = (d > max) ? d : max;
	return max;
}

int get_min(int a, int b, int c, int d){
	int min = a;
	min = (b < min) ? b : min;
	min = (c < min) ? c : min;
	min = (d < min) ? d : min;
	return min;
}
