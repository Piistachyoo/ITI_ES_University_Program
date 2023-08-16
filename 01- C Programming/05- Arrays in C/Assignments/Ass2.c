#include <stdio.h>

void pass(int array[],int size);
void fail(int array[],int size);
void highest_grade(int array[],int size);
void lowest_grade(int array[],int size);
void average_grade(int array[],int size);

void main()
{
	int class1[10] = {14, 70, 80, 90, 75, 83, 93, 34, 18, 67};
	int class2[10] = {46, 15, 24, 38, 67, 98, 45, 75, 76, 88};
	int class3[10] = {18, 75, 94, 83, 46, 12, 54, 68, 75, 13};
	int sizeofarray = sizeof(class1)/sizeof(class1[0]);
	int selection;
	while(1)
	{
		printf("\n\nChoose class to get statistics: ");
		scanf("%d", &selection);
		
		switch(selection)
		{
			default:
			printf("Enter valid class number!\n");
			break;
			
			case 1:
			pass(class1, sizeofarray);
			fail(class1, sizeofarray);
			highest_grade(class1, sizeofarray);
			lowest_grade(class1, sizeofarray);
			average_grade(class1, sizeofarray);
			break;
			
			case 2:
			pass(class2, sizeofarray);
			fail(class2, sizeofarray);
			highest_grade(class2, sizeofarray);
			lowest_grade(class2, sizeofarray);
			average_grade(class2, sizeofarray);
			break;
			
			case 3:
			pass(class3, sizeofarray);
			fail(class3, sizeofarray);
			highest_grade(class3, sizeofarray);
			lowest_grade(class3, sizeofarray);
			average_grade(class3, sizeofarray);
			break;
		}
	}
}

void pass(int array[],int size)
{
	int number_of_passed=0;
	for(int i=0;i<size;i++)
	{
		if(array[i]>=50)
		{
			number_of_passed++;
		}
	}
	printf("\nNumber of passed students is: %d", number_of_passed);
}

void fail(int array[],int size)
{
	int number_of_failed=0;
	for(int i=0;i<size;i++)
	{
		if(array[i]<50)
		{
			number_of_failed++;
		}
	}
	printf("\nNumber of failed students is: %d", number_of_failed);
}

void highest_grade(int array[],int size)
{
	int max=0;
	for (int i=0;i<size;i++)
	{
		if(array[i]>max)
		{
			max=array[i];
		}
	}
	printf("\nHighest grade: %d", max);
}

void lowest_grade(int array[],int size)
{
	int min=array[0];
	for(int i=0;i<size;i++)
	{
		if(array[i]<min)
		{
			min=array[i];
		}
	}
	printf("\nLowest grade is: %d", min);
}

void average_grade(int array[],int size)
{
	int sum=0, average;
	for(int i=0;i<size;i++)
	{
		sum += array[i];
	}
	average = sum/size;
	
	printf("\nAverage grade is: %d", average);
}
