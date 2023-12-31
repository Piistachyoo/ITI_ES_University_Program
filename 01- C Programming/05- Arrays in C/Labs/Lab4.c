#include <stdio.h>

int linear_search(int array[], int sizeofarray, int search_number);

void main()
{
	int numarray[10];
	int sizeofarray = sizeof(numarray)/sizeof(numarray[0]);
	int search_number, found_count=0;
	
	for(int i=0;i<sizeofarray;i++)
	{
		printf("Please Enter number %d: ", i);
		scanf("%d", &numarray[i]);
	}
	
	printf("Enter a number to search for: ");
	scanf("%d", &search_number);
	
	found_count = linear_search(numarray, sizeofarray, search_number);
	if(found_count==0)
	{
		printf("Value does not exist");
	}
	else
	{
		printf("Value exists %d times.", found_count);
	}
}

int linear_search(int array[], int sizeofarray, int search_number)
{
	int count=0;
	for(int i=0;i<sizeofarray;i++)
	{
		if(array[i]==search_number)
		{
			count++;
		}
	}
	return count;
}
