#include <stdio.h>

void sum_subt(int n1, int n2, int *p1, int *p2);

void main()
{
	int sum, sub, n1, n2;

	/* Input data */
	printf("Enter value 1: ");
	scanf("%d", &n1);
	printf("Enter value 2: ");
	scanf("%d", &n2);
	
	/* Process data */
	sum_subt(n1, n2, &sum, &sub);

	/* Output data */
	printf("\nThe result of summation is: %d", sum);
	printf("\nThe result of Subtraction is: %d", sub);
}

void sum_subt(int n1, int n2, int *p1, int *p2)
{
	*p1 = n1+n2;
	*p2 = n1-n2;
}
