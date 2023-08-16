#include <stdio.h>

void Get_Max(int array[], int size);
void Get_Min(int array[], int size);

void main()
{
	int numbers[10];
	int sizeofarray = sizeof(numbers)/sizeof(numbers[0]);
	printf("Enter 10 values: ");
	for(int i=0;i<10;i++)
	{
		scanf("%d", &numbers[i]);
	}
	Get_Max(numbers, sizeofarray);
	Get_Min(numbers, sizeofarray);
}

void Get_Max(int array[], int size)
{
	int max=0;
	for (int i=0;i<size;i++)
	{
		if(array[i]>max)
		{
			max=array[i];
		}
	}
	printf("\nMax number = %d", max);
}

void Get_Min(int array[], int size)
{
	int min=array[0];
	for(int i=0;i<size;i++)
	{
		if(array[i]<min)
		{
			min=array[i];
		}
	}
	printf("\nMin number = %d", min);
}
