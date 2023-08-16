#include <stdio.h>

int binary_search(int array[], int sizeofarray, int search_number);

void main()
{
	int numarray[10] = {5, 7, 10, 13, 20, 22, 33, 41, 46, 51};
	int sizeofarray = sizeof(numarray)/sizeof(numarray[0]);
	int search_number, found;
	printf("Enter a number to search for: ");
	scanf("%d", &search_number);
	found = binary_search(numarray, sizeofarray, search_number);
	if(found == 1)
	{
		printf("Value Found.");
	}
	else
	{
		printf("Value Not Exist");
	}
}

int binary_search(int array[], int sizeofarray, int search_number)
{
	int low=0, high = sizeofarray-1;
	int mid = (high+low)/2;
	
	while(low!=high)
	{
		if(search_number==array[mid])
		{
			return 1;
		}
		else if(search_number>array[mid])
		{
			low=mid;
			mid=(low+high)/2;
			continue;
		}
		else if(search_number<array[mid])
		{
			high=mid;
			mid=(low+high)/2;
			continue;
		}
	}
	
	return 0;
}
