#include "MirafraHuaweiQuestions.h"

void main()
{
	int more=1,d=0, count=0, num = 0,i =0, make = 1, a = 0;

	printf("Do you want to look for any operation to be done Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. Given an array to arrange Positive numbers at the last and Negative numbers in the beginning \
				                                          \n 2. Given an character array sort it \
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				arrangePosNegNumbers();
				break;
			case 2:
				sortCharArray();
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

/* Given an array of positive and negative numbers arrange all positive number
   and all negative numbers at one side os array 
   Solution: Complexity of O(n) and no extra memory is required except the given array s*/
void arrangePosNegNumbers()
{
	int len = 0, posIdx=0, negIdx=0;
	int* p = 0;

	printf("\n Enter the length of array:");
	scanf("%d", &len);

	p=(int *)calloc(len, sizeof(int));
	if(0 == p)
	{
		printf("Memory allocation to array failed\n");
		return;
	}

	for(negIdx=0; negIdx<len; negIdx++)
	{
		printf("\n Enter the number at %dth index:", negIdx);
		scanf("%d", &p[negIdx]);
	}

	negIdx--;
	while(posIdx != negIdx)
	{
		if(p[posIdx] < 0)
			posIdx++;

		if(p[negIdx] > 0)
			negIdx--;

		if((p[posIdx] > 0) && (p[negIdx] < 0))
		{
			int temp = p[negIdx];
			p[negIdx]=p[posIdx];
			p[posIdx]=temp;
		}
	}

	printf("\n Resulting array after one pass is :\n");
	for(negIdx=0; negIdx<len; negIdx++)
	{
		printf(" %d ", p[negIdx]);
	}
	printf("\n");

	if(p)
	{
		free(p);
		p=0;
	}
	return;
}

/* A function to sort a char array */
void sortCharArray() 
{
	int len = 0, i = 0, j = 0;
	char* p = 0;

	printf("\n Enter the length of array:");
	scanf("%d", &len);

	p = (char *)calloc(len, sizeof(char));
	if(0 == p)
	{
		printf("Memory allocation to array failed\n");
		return;
	}

	for(i=0; i<len; i++)
	{
		printf("\n Enter the character:");
		scanf("%c", p[i]);
	}

	for(j=len-1; j>=0; j--)
	{
		for(i=0; i<j; i++)
		{
			if(p[i]>p[i+1])
			{
				char ch=p[i+1];
				p[i+1]=p[i];
				p[i]=ch;
			}
		}
	}

	printf("\n Array after bubble sorting in increasing order \n");
	for(i=0; i<len; i++)
	{
		printf(" %c ", p[i]);
	}

	if(p)
	{
		free(p);
		p=0;
	}
	return;
}