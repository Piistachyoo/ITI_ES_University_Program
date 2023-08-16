#include <stdio.h>

void print_array(int array[], int sizeofarray)
{
	for(int i=0;i<sizeofarray;i++)
	{
		printf("Value [%d] = %d\n", i, array[i]);
	}
}

void reversearray(int array[], int sizeofarray)
{
	
	printf("The value in reversed order is: ");
	
	for (int i=sizeofarray-1;i>=0;i--)
	{
		printf("%d\n", array[i]);
	}
}


int main()
{
	int numarray[10];
	int sizeofarray = sizeof(numarray)/sizeof(numarray[0]);
	for(int i=0;i<10;i++)
	{
		printf("Please enter number %d: ", i);
		scanf("%d", &numarray[i]);
	}
	reversearray(numarray, sizeofarray);
	
	
}