/*
File: ArraySearching.cpp
Description: This file contains all the possible types of searching and finds out their computational complexity also
        i.e. Linear search AND Binary Search
Author: Vineet Kumar Srivastava
Date: 21st Febraury 2010
*/

#include "ArraySearching.h"
#include "HeapUtils.h"

void main()
{
	int more=1,d=0,a=0,count=0,i=0,idx=-1, key = 0;
	int arr[MAX_INDEX_COUNT];
	
	printf("Do you want to search in an array of numbers: Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		printf("\nEnter the number of elements in array:");
		scanf("%d", &count);
		for(i=0;i<count;i++)
		{
			printf("\nEnter the %dth number:",i);
			scanf("%d", &arr[i]);
		}
		printf("\nPrinting the contents of Array\n");
		printArr(arr, count);
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. For Searching A number in array using Linear search\
				                                          \n 2. For Searching A number in array using Binary search\
				                                          \n 3. For Printing the array \
														  \n 4. For searching in a rotated sorted array \
														  \n 5. For Custom Binary search \
														  \n 6. Create a custom made Double dimensional Array \
														  \n 7. Create a custom made Single dimensional Array \
														  \n 8. Find second largest number in an array using Brute force \
														  \n 9. Find second largest number in an array using Max Heap \
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				idx = linearSearchInArr(arr,count);
				printf(" Index at which number found is %d\n\n",idx);
				break;
			case 2:
				printf("\n Enter the number to be found:");
				scanf("%d", &key);
				idx = binarySearchInArr(arr,count, key);
				if(-1 == idx)
					printf("\n Number NOT Found ");
				else
					printf("\n Number FOUND ");
				break;
			case 3:
				printArr(arr, count);
				break;
			case 4:
				printf("\n Enter the number to be found:");
				scanf("%d", &key);
				idx = searchInSortedArrUsingWhile(arr, count, key);
				if( -1 == idx)
					printf("\n Number entered NOT FOUND \n");
				else
					printf("\n Number found at index %d \n", idx);
				break;
			case 5:
				printf("\n Custom Binary Search");
				printf("\n Enter the number to be found:");
				scanf("%d", &key);
				idx = binarySearchInArrCustom(arr, 0, (count-1), key);
				if( -1 == idx)
					printf("\n Number entered NOT FOUND \n");
				else
					printf("\n Number found at index %d \n", idx);
				break;
			case 6:
				printf("\n Making a custom made Double dimensional array ");
				customMadeDimensionalArray();
				break;
			case 7:
				printf("\n Making a custom made Single dimensional array ");
				customMadeSingleDimensionalArray();
				break;
			case 8:
				printf("\n Find the second largest number in the array Using Brute Force\n");
				findSecondLargestNumInArrayUsingBruteForce(arr, count);
				break;
			case 9:
				printf("\n Find the second largest number in the array Using Heap\n");
				findSecondLargestNumInArrayUsingHeap(arr, count);
				break;
			default:
				printf("\n You have not entered a valid choice \n");
				break;
			}
			printf("\nDo you want to do one more operation: Enter 1 for YES 2 for NO:");
			scanf("%d", &a);
			if(2 == a)
				more=0;
			else
				more=1;
		}
	}
	printf(" Do one more key press to Exit\n");
	getche();
}


/* Function to print the contents of an array */
void printArr(int *p, int len)
{
	int j=0;
	printf(" Array Elements are:");
	for(j=0;j<len;j++)
	{
		printf(" %d", *(p+j));
	}
	printf("\n");
}

int linearSearchInArr(int *p, int len);
void binarySearchInArr(int *p, int len);
/* Above lines compile becoz multiple declarations work fine 
   whereas multiple definitions generate errory saying function or variable already has a body or has been defined earlier */

/* Function for Searching A number in array using Linear search */
int linearSearchInArr(int *p, int len)
{
	int num=-1,i=0,numComp=0,ret=-1;
	printf("\n\n Enter the number to be searched in Array:");
	scanf("%d", &num);

	printf("\n Performing LINEAR SEARCH \n");
	for(i=0;i<len;i++)
	{
		numComp++;
		if(num == p[i])
		{
			printf("\n Number found at the %dth index in array \n", i+1);
			ret=i+1;
			break;
		}
	}
	printf(" Number of comparisons made are: %d\n\n",numComp);
	return ret;
}

/* Function for Searching A number in array using Binary search */
int binarySearchInArr(int *p, int len, int key)
{
int beg = 0, end = len-1, mid = (beg+end)/2, ret = -1;

	while((p[mid] != key) && (beg < end))
	{
		if(key < p[mid])
			end = mid-1;
		else
			beg = mid+1;
		mid = (beg+end)/2;
	}
	if(key == p[mid])
		ret = mid;

	if(-1 == ret)
		printf("\n binarySearchInArr: Number not found OR is not in this array");
	else
		printf("\n binarySearchInArr: Number FOUND in array at %d index", ret);
	return ret;
}

/* Function for Searching A number in array using Binary search */
int binarySearchInArrCustom(int *p, int left, int right, int key)
{
	int mid=-1, ret=-1;
	int numComp=0;
	while(left < right)
	{
		mid=(left+right)/2;
		if(key == p[mid])
		{
			ret = mid;
			break;
		}
		else if(key > p[mid])
			left=mid+1;
		else 
			right=mid-1;
	}
	if((left == right) && (key == p[left]))
		ret = left;

	if(-1 == ret)
		printf("\n binarySearchInArr: Number not found OR is not in this array");
	else
		printf("\n binarySearchInArr: Number FOUND in array at %d index", ret);
	return ret;
}

/* Function for Searching A number in an ROTATED SORTED array using Binary search */
int searchInSortedArr(int *p, int len, int key)
{
	static int start=0, end = len-1, mid=(start+end)/2;

	if(key == p[start])
		return start;
	else if(key > p[start])
	{
		if(key == p[mid])
			return mid;
		if(key > p[mid])
		{
			p=p+mid;
			start=mid;
			mid=(start+end)/2;
			len=len-mid;
			return searchInSortedArr(p, len, key);
		}
		else
		{
			end=mid;
			len=len-mid-1;
			mid=(start+end)/2;
			return searchInSortedArr(p, len, key);
		}
	}
	else if(key == p[end])
		return end;
	else if(key < p[end])
	{
		start=mid;
		len=len-mid;
		mid=(start+end)/2;
		return searchInSortedArr(p, len, key);
	}
	else 
		return -1;
}


/* Function for Searching A number in an ROTATED SORTED array using Binary search */
int searchInSortedArrUsingWhile(int *p, int len, int key)
{
	int start=0, end = len-1, mid=(start+end)/2;
	int idx=-1;
	while(start < end)
	{
		if(key == p[start])
		{
			idx= start;
			break;
		}
		else if(key > p[start])
		{
			if(key == p[mid])
			{
				idx= mid;
				break;
			}
			if(key > p[mid])
			{
				p=p+mid;
				start=mid;
				mid=(start+end)/2;
				len=len-mid;
			}
			else
			{
				end=mid;
				len=len-mid-1;
				mid=(start+end)/2;
			}
		}
		else if(key == p[end])
		{
			idx= end;
			break;
		}
		else if(key < p[end])
		{
			start=mid;
			len=len-mid;
			mid=(start+end)/2;
		}
	}
	return idx;
}

void customMadeDimensionalArray(void)
{
	int row = -1, column = -1, idx = -1, *p=NULL;
	int i=0,j=0;

	/* Get the row and column */
	printf("\n customMadeDimensionalArray: Enter the row:");
	scanf("%d", &row);
	printf("\n customMadeDimensionalArray: Enter the column:");
	scanf("%d", &column);

	/* Allocate memory to array based on row and column */
	p=(int *)calloc((row*column),sizeof(int));
	if(NULL == p)
	{
		printf("\n customMadeDimensionalArray: Memory allocation to the array FAILED");
		return;
	}

	/* Put the numbers obtained from User */
	for(i = 0; i <row; i++)
	{
		for(j = 0; j <column; j++)
		{
			printf("\n customMadeDimensionalArray: Enter the number to be placed at %dth row and %dth column:", i, j);
			scanf("%d", &(*(p+(i*column)+j)));
		}
	}

	/* Print the array formed */
	printf("\n customMadeDimensionalArray: Array formed is as follows: \n");
	for(i = 0; i <row; i++)
	{
		for(j = 0; j <column; j++)
		{
			printf(" %d", *(p+(i*column)+j));
		}
		printf("\n");
	}

	return;
}

void customMadeSingleDimensionalArray(void)
{
	int column = -1, idx = -1, *p=NULL;
	int j=0;

	/* Get the column */
	printf("\n customMadeSingleDimensionalArray: Enter the column:");
	scanf("%d", &column);

	/* Allocate memory to array based on row and column */
	p=(int *)calloc( column,sizeof(int));
	if(NULL == p)
	{
		printf("\n customMadeSingleDimensionalArray: Memory allocation to the array FAILED");
		return;
	}

	/* Put the numbers obtained from User */
	for(j = 0; j <column; j++)
	{
		printf("\n customMadeSingleDimensionalArray: Enter the number to be placed at %dth place:", j);
		scanf("%d", &(*(p+j)));
	}

	/* Print the array formed */
	printf("\n customMadeSingleDimensionalArray: Array formed is as follows: \n");
	for(j = 0; j <column; j++)
	{
		printf(" %d", *(p+j));
	}
	printf("\n");

	return;
}


/* Find the second largest number in the array using brute force algorithm */
int findSecondLargestNumInArrayUsingBruteForce(int* pArr, int len)
{
	int iSecondLargest = 0, iLargest = 0, idx = 0;

	if(len < 2)
	{
		printf("\n findSecondLargestNumInArray: Array length passed is less than 2\n");
		return iSecondLargest;
	}

	for(idx = 0; idx < len; idx++)
	{
		if(pArr[idx] > iLargest)
		{
			iSecondLargest = iLargest;
			iLargest = pArr[idx];
		}
		else if(pArr[idx] > iSecondLargest)
		{
			iSecondLargest = pArr[idx];
		}
	}

	printf("\n findSecondLargestNumInArray: Largest element is %d and second largest is %d\n", iLargest, iSecondLargest);
	return iSecondLargest;
}


/* Find the second largest number in the array using HEAP */
int findSecondLargestNumInArrayUsingHeap(int* pArr, int len)
{
	int iRet = 0, idx = 1;
    
    /* First build a heap out of the numbers in array */
    for(idx = 1; idx < len; idx++)
		addElementToHeap(pArr, idx, pArr[idx]);

	/* Display the heap */
	printHeap(pArr, len);

	/* Delete the root node */
	deleteElementFromHeap(pArr, &len, 0);

	/* Display the heap */
	printHeap(pArr, len);

	/* Take out the root node it shall be the second largest number */
	
	return iRet;
}