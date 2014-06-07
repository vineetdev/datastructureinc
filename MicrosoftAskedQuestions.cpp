/*
File: MicrosoftAskedQuestions.cpp
Description: This file contains all the possible types of searching and finds out their computational complexity also
        i.e. Programmes for questions asked in MICROSOFT Interview
Author: Vineet Kumar Srivastava
Date: 01 MAY 2010
*/
#include "MicrosoftAskedQuestions.h"

void main()
{
	int more = 1,d = 0, a = 0, num = 0, i= 0;
	int* arr=0;
	int sum=0;
	char* ch = 0;
	char bigString[20] = {'\0',};
	char smallString[10] = {'\0',};
	
	printf("Do you want to look for any operation to be done Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n 1. To do itoa without using any string function \
														\n 2. To do strstr without using any string function \
														\n 3. To get the maximum subsum of a array \
														\n 4. To arrange all negative numbers at the start of list \
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				printf("\n Enter the number:");
				scanf("%d", &num);
				ch = xitoa(num);
				if(ch)
					printf("\n String is %s ", ch);
				break;
			case 2:
				printf("\n\n Enter the big string:");
				scanf("%s", &bigString);
				printf("\n Enter the small string:");
				scanf("%s", &smallString);
				ch = xstrstr( smallString, bigString);
				printf("\n First occurence of string %s in %s is %s", smallString, bigString, ch);
				break;
			case 3:
				printf("\n Enter the number of elements in array:");
				scanf("%d", &num);
				arr = (int*)calloc(num, sizeof(int));
				for(i=0;i<num;i++)
				{
					printf("\n Enter the %dth number of element in array:", i);
					scanf("%d", &arr[i]);
				}
				printf("\n\n Finding the maximum subsum of array");
				//sum = findMaxSubsumInArr(arr, num);
				sum = findMaxSubsumInArrWithLesserComplexity(arr, num);
				printf("\n\n Maximum subsum of array is %d \t\n", sum);
				break;
			case 4:
				printf("\n Enter the number of elements in array:");
				scanf("%d", &num);
				arr = (int*)calloc(num, sizeof(int));
				for(i=0;i<num;i++)
				{
					printf("\n Enter the %dth number of element in array:", i);
					scanf("%d", &arr[i]);
				}
				printf("\n\n Printing the elements of array after arranging :\n");
				arrangeElementsOfArray(arr, num);
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
	return;
}

/* Function to do itoa without using any string function */
char* xitoa(int num)
{
	static char ch[] = {0};
	int i = 0;

	while(num)
	{
		ch[i] = num%10 + '0';
		num = num/10;
		i++;
	}
	ch[i] = '\0';

	xstrrev(ch);

	printf("\n Number is %s \n\n", ch);

	return ch;
}

/* Function to do string reversal */
void xstrrev(char* ch)
{
	int i = 0, j = strlen(ch)-1;
	char temp;

	while(i < j) // This condition will ensure that the string elements are reversed till reaching the middle element
	{
		temp = ch[i];
		ch[i]=ch[j];
		ch[j] = temp;
		i++;
		j--;
	}

	return;
}

/* Function to search for a small string from a big string */
char* xstrstr(char* s1, char* str)
{
	char *sret = 0;
	char* s2 = s1;
	bool flag_found = FALSE;

	while( '\0' != *str)
	{
		if( *s2 == *str)
		{
			sret = str;
			while((*str == *s2) && ('\0' != *s2))
			{
				str++;
				s2++;
			}
			if('\0' == *s2)
			{
				flag_found = TRUE;
				break;
			}
			else
			{
				s2 = s1;
				sret = 0;
			}
		}
		else
		{
			str++;
			s2 = s1;
		}
	}

	if(TRUE == flag_found)
	{
		if(0 != sret)
			printf("\n String %s Found", s1);
		else
			printf("\n Some problem occurred and starting pointer in Bigger string NOT FOUND ");
	}
	else
		printf("\n String %s NOT FOUND", s1);

	return sret;
}

/* Function to find the maximum number in an array */
int findMaxNumberInArr(int* arr, int start, int len)
{
	int max=arr[start], i = 0;
	for(i=start; i<len; i++)
	{
		if(max < arr[i])
			max = arr[i];
	}

	return max;
}

/* Function to find the maximum subsum in an array */
int findMaxSubsumInArr(int* arr, int len)
{
	int *p = 0;
	int i = 0, j=0, max = 0;
	p = (int*)calloc(len, sizeof(int));
	if(0 == p)
	{
		printf("\n Memory allocation for an array of %d intergers FAILED", len);
		return max;
	}

	for(i=0; i<len; i++)
	{
		int subSum=0;
		for(j=i; j<len;j++)
		{
			subSum = subSum + arr[j];
			p[j]=subSum;
		}
		p[i] = findMaxNumberInArr(p, i, len);
	}

	max = findMaxNumberInArr(p, 0, len);
	return max;
}

/* Function to find the maximum subsum in an array Lesser complexity*/
int findMaxSubsumInArrWithLesserComplexity(int* arr, int len)
{
	int max = 0, pivot = 0, i = 0, j = 0, subSum=0;
	int *p = 0;

	p = (int *)calloc(len, sizeof(int));
	if(0 == p)
	{
		printf("\n Malloc for %d number of intergers failed \n", len);
		return max;
	}

	/* Find the pivot i.e. the maximum number in the array */
	pivot = findIndexOfMaxNumInArray(arr, len);

	for(i=pivot; i >= 0; i--)
	{
		subSum = 0;
		for(j=i; j>=0; j--)
		{
			subSum = subSum + arr[j];
			p[j]=subSum ;
		}
		max = findMaxNumberInArr(p, 0, pivot+1);
		p[i]=max;
	}

	max = findMaxNumberInArr(p, 0, pivot+1);

	subSum = max;
	for(i = pivot+1; i<len;i++)
	{
		subSum = subSum+arr[i];
		if(subSum > max)
			max = subSum;
	}

	if(subSum > max)
		max = subSum;

	if(0 != p)
	{
		free(p);
		p = 0;
	}

	return max;
}

/* Function to find the index of maximum number in array */
int findIndexOfMaxNumInArray(int *arr, int len)
{
	int idx = 0, max = arr[0], ret=0;

	for(idx = 1; idx<len; idx++)
	{
		if(max < arr[idx])
		{
			max = arr[idx];
			ret = idx;
		}
	}

	return ret;
}

/* A function to arrange negative numbers at the starting of list */
void arrangeElementsOfArray(int *arr, int len)
{
	int iNeg = -1, iPos = -1, i = 0, temp = 0;
	if(0 == arr)
	{
		printf("\n Array received is NULL");
		return;
	}

	for(i = 0; i < len; i++)
	{
		if(arr[i] < 0)
			iNeg = i;
		else if(iPos <= iNeg)
			iPos = i;

		if(iNeg > iPos)
		{
			temp = arr[iPos];
			arr[iPos] = arr[iNeg];
			arr[iNeg] = temp;
			temp = iNeg;
			iNeg = iPos;
			iPos = temp;
		}
	}

	for(i = 0; i<len;i++)
		printf(" %d ", arr[i]);
	return;
}

/* END OF FILE */