/*
File: DynamicProgrammingQuestions.cpp
Description: Implementation for algorithm specific dynamic programming specific questions.
Author: Vineet Kumar Srivastava
Date: 11 MAY 2014
*/
/************************************* INCLUDES *******************************************/
#include "DynamicProgrammingQuestions.h"

/************************************** DEFINES *******************************************/
#define NULL 0


/******************************** FUNCTION DEFINITIONS ************************************/
void main()
{
	int n = 0, option =1;
	printf("\n Choose one option among the possible choices given below: ");
	while(option)
	{
		printf("\n 1. Given N then using numbers 1 to N add or substract them so that resulting sum is ZERO.");
		printf("\n    Print all such paths");
		printf("\n    For e.g. User enters N as 4 then such path possible is 1-2-3+4,  \
				\n    Print all such paths");
		printf("\n 2. Exit\n:");

		scanf("%d", &option);
		switch(option)
		{
			case 1: 
				printf("\n Enter N i.e. limit of numbers to be used as:");
				scanf("%d", &n);
				printPathsOfNIntegersWhoseSumis0(n);
				break;

			case 2:
				printf("\n Exiting from the while loop");
				option = 0;
				break;
		}
	}
	getche();
}

/* Given number N as 4 say then the numbers possible are 1,2,3 and 4. */
/* Using + and - we need to generate such combinations where its sum shall be ZERO */
/* Such paths shall be 1-2-3+4 = 0 */
/* Function which will print the paths of N integers whose sum shall result in ZERO */
void printPathsOfNIntegersWhoseSumis0(int n)
{
	int idx = 1, subSum = 0;
	char string[MAX_STRING_LENGTH] = {0,};
	int strlength = 0;
	int sum = (n*(n+1))/2; /* Sum of all the N integers */

	/* Validate if such paths are possible or not */
	if(sum%2)  /* If remainder exists then such paths are not possible */
	{
		printf("\n printPathsOfNIntegersWhoseSumis0: No such paths are possible\n");	
		return;
	}

	/* If remainder is 0 then such paths are possible */
	/* Generate such paths */
	subSum = 1;
	string[0]='1';
	strlength = 1;

	/* Call the API to find such paths */
	findZEROLengthPaths(subSum, 2, n, string, strlength);
}

/* Recursive function call to find such paths */
int	findZEROLengthPaths(int subSum, int idx, int n, char* string, int strlength)
{
	if(subSum > ((n*(n+1))/4))  /* i.e. subSum > sum/2 */
		return 0;

	{
		int subSum1 = subSum + idx;
		int subSum2 = subSum - idx;
		char buffer[2]= {0,};
		char string1[MAX_STRING_LENGTH] = {0,}, string2[MAX_STRING_LENGTH] = {0,};

		itoa(idx, buffer, 10);
		memcpy(string1, string, strlength);
		string1[strlength]='+';
		strncpy(&string1[strlength+1], buffer, 1);

		strncpy(string2, string, strlength);
		string2[strlength]='-';
		strncpy(&string2[strlength+1], buffer, 1);

		if(n == idx)  /* Means path is found */
		{
			if(0 == subSum1)
			{
				printf("\nPath is: %s ", string1);
			}
			if(0 == subSum2)
			{
				printf("\nPath is: %s ", string2);
			}
			return 0;  /* Else case means path cannot be found now */
		}

		findZEROLengthPaths(subSum1, (idx+1), n, string1, (strlength+2));
		findZEROLengthPaths(subSum2, (idx+1), n, string2, (strlength+2));
	}
}

/* End of File */