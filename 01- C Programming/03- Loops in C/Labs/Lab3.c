#include <stdio.h>

int main(){

    int i, n;
    int sum = 0;
    double average;

    /* Input data */
    printf("Enter 10 numbers: \n");
    for(i = 0; i < 10; i++){
    	printf("Enter number %d: ", i+1);
    	scanf("%d", &n);
        sum += n;
    }

    average = sum/10.0;

    /* Output data */
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

	return 0;
}