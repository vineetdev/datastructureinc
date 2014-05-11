/*
File: Sorting
Description: This file contains all the possible algorithms for sorting
        i.e. Bubble sorting in increasing order, 
		     Insertion sorting, Selection sorting and Quick sort algorithms.
Author: Vineet Kumar Srivastava
Date: 19th & 20th Febraury 2010
*/

#include "ArraySorting.h"

void main()
{
	int more=1,d=0,a=0,count=0,i=0;
	int arr[MAX_INDEX_COUNT];
	
	printf("Do you want to sort an array of numbers: Enter 1 for YES 2 for NO:\n");
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
			printf("\n Enter one of the following choices \n 1. For Sorting the array using Bubble sort in Increasing order\
				                                          \n 2. For Sorting the array \
														  \n 3. For Sorting the array using Insertion sort\
														  \n 4. For Sorting the array using Selection sort\
														  \n 5. For Sorting the array using Quick sort\
				                                          \n 6. For Printing the array \n:");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				bubbleSortArr(arr,count);
				printArr(arr,count);
				break;
			case 2:
				sortArr(arr,count);
				printArr(arr,count);
				break;
			case 3:
				insertionSortArr(arr,count);
				printArr(arr,count);
				break;
			case 4:
				selectionSortArr(arr,count);
				printArr(arr, count);
				break;
			case 5:
				quickSortArr(arr, 0, count-1,count);
				break;
			case 6:
				printArr(arr, count);
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

/* Function to bubble sort the contents of an array */
void sortArr(int *p, int len)
{
	int j=0,i=0,temp=0,ordr=0, numComp=0;
	printf(" Enter the order in which you want to sort the array: 1 for Increasing 2 for decreasing:");
	scanf("%d",&ordr);
	if(1 == ordr)
		printf(" Sorting the array elements in increasing order\n");
	else if(2 == ordr)
		printf(" Sorting the array elements in decreasing order\n");
	else
	{
		printf(" Order selected for sorting is invalid\n");
		return;
	}

	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++) // Smallest or the largest number bubbles up to the start of the array
		{
			if(1==ordr)  
			{
				if(*(p+i) > *(p+j))
				{
					temp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=temp;
					numComp++;
				}
			}
			else
			{
				if(*(p+i) < *(p+j))
				{
					temp=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=temp;
					numComp++;
				}
			}
		}
	}
	printf("\n Total number of comparisons are: %d \n", numComp);
}

/* Function to sort the contents of an array in increasing order */
void bubbleSortArr(int *p, int len)
{
	int j=1,temp=0,num=0, numComp=0;
	printf(" Sorting the array elements in increasing order\n");
	for(num=0;num<len;num++)    // In each pass of array the greatest number sinks to the end of array
	{
		int i=0;
		for(j=1;j<len-num;j++)
		{
			if(*(p+i) > *(p+j))
			{
				temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
				numComp++;
			}
			i++;
		}
	}
	printf("\n Total number of comparisons are: %d \n", numComp);
}

/* Function to sort array using insertion sort */
void insertionSortArr(int *p, int len)
{
	int i=0,j=0, temp = 0, numComp=0;
	for(i=1;i<len;i++)   // In each pass of array one number gets inserted at its correct place
	{
		j=i-1;
		temp=p[i];

		/* Move the greater numbers */
		while(p[j] > temp)
		{
			p[j+1]=p[j];
			j--;
			numComp++;
		}

		/* Insert the number */
		p[j+1]=temp;
		printf("\n one pass of array completed: ");
		printArr(p, len);
	}
	printf("\n Number of comparisons are: %d \n", numComp);
}

/* Function to sort array using Selection sort */
void selectionSortArr(int *p, int len)
{
	int i=0,j=0, numComp=0, temp=0;
	for(i=0;i<len;i++)   // In each pass of array the smallest number in array is moved to the start of array
	{
		int k=i;
		/* Find the smallest number */
		for(j=i;j<len;j++)
		{
			if(p[k]>p[j])
				k=j;
			numComp++;
		}

		/* Smallest number found swap it */
		if(0 != k)
		{
			temp=p[i];
			p[i]=p[k];
			p[k]=temp;
		}

		/* Print the array after each swap */
		printf("\n one pass of array completed: ");
		printArr(p, len);
	}
	printf("\n Number of comparisons are: %d \n", numComp);
}

/* A function to do quick sorting */
void quickSortArr(int *p, int startPos, int endPos, int len)
{
	int left=startPos, loc = startPos, temp=0, right = endPos, numComp=0;
	while(right != loc)
	{
		while((p[loc] < p[right]) && (right != loc))
		{
			right--;
			numComp++;
		}

		/* Swap the two numbers */
		if(right != loc)
		{
			temp=p[loc];
			p[loc]=p[right];
			p[right]=temp;
			loc=right;
		}
		else
			break;

		while((p[loc] > p[left]) && (left != loc))
		{
			left++;
			numComp++;
		}

		/* Swap the two numbers */
		if(left != loc)
		{
			temp=p[loc];
			p[loc]=p[left];
			p[left]=temp;
			loc=left;
		}
		else
			break;
	}
	printf(" Done quick sorting now returning \n");
	printArr(p, len);
}
