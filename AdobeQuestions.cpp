/*
File: AdobeQuestions.cpp
Description: Implementation for questions asked in Adobe Interview 
Author: Vineet Kumar Srivastava
Date: 20 MARCH 2011
*/

#include "AdobeQuestions.h"

#define NULL 0

void main()
{
	int more=1,d=0, count=0, num = 0,i =0, make = 1;
	char *ch = 0;
	short int a = -1;
	int b=a;
	
	printf("Do you want to look for any operation to be done Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. To do STRTOK Operation \
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				{
					char ch[]="My name is RAM";
					char* string = NULL;
					string = strtok(ch, '\ ');
					string = strtok(NULL, '\ ');
					string = strtok(NULL, '\ ');
					string = strtok(NULL, '\ ');
				}
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

char* strtok(char *str, const char* delimiters)
{
	static char* string = NULL;
	static char* strOutput = NULL;

	if(NULL != str)
		string = str;

	return strOutput;
}