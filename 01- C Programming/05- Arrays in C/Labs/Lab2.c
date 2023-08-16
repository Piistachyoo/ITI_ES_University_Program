#include <stdio.h>

int getsum(int array[], int sizeofarray)
{
	int sum=0;
	for (int i=0;i<sizeofarray;i++)
	{
		printf("Please enter number %d: ", i+1);
		scanf("%d", &array[i]);
		sum += array[i];
	}
	return sum;
}

int main()
{
	int narray[10] = {0};
	int sizeofarray = sizeof(narray)/sizeof(narray[0]);
	int average, sum;
	
	sum = getsum(narray, sizeofarray);
	
	average = sum/10;
	
	printf("Sum = %d\n", sum);
	printf("Average = %d\n", average);
}