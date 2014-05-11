/*
File: AKAMAIQuestions.h
Description: Header file for the corresponding cpp file
Author: Vineet Kumar Srivastava
Date: 01 MAY 2010
*/

#include "AKAMAIQuestions.h"

struct doubleLinkedList* root = 0;
struct singleLinkedList* head = 0;

void main()
{
	int more=1,d=0, count=0, num = 0,i =0, make = 1;
	char *ch = 0;
	short int a = -1;
	int b=a;
	
	displayAllBitsInADecimalNumber(a);
	printf("\n");
	displayAllBitsInADecimalNumber(a);
	printf("Do you want to look for any operation to be done Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. To identify whether the system is Little Endean or Big Endean \
															\n 2. To count the number of ONEs in an integer \
															\n 3. To print all the bits of an integer \
															\n 4. To make a string of all the bits of an integer \
															\n 5. To remove a node from a doubly linked list given node pointer \
															\n 6. To remove a node from a singly linked list given node pointer \
															\n 7. To get the sizeof without using sizeof \
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				identifySystemIsLittleEndeanOrBigEndean();
				break;
			case 2:
				printf("\n Enter the number:");
				scanf("%d", &num);
				count = countNumOfOnesInADecimalNumber(num);
				if(0 == count)
					printf("\n No ONE bit found in the number ");
				else
					printf("\n Number of ONEs found are %d", count);
				break;
			case 3:
				printf("\n Enter the number:");
				scanf("%d", &num);
				displayAllBitsInADecimalNumber(num);
				break;
			case 4:
				printf("\n Enter the number:");
				scanf("%d", &num);
				ch = makeStringOfBinaryRepresentationOfDecimalNumber(num);
				if(0 == ch)
					printf("\n String representation was unsuccessfull");
				else
				{
					printf("\n\n String representation of %d is ", num);
					for(i=sizeof(int)*8;i>=0;i--)
						printf("%c", ch[i]);
					free(ch);
					ch = 0;
				}
				break;
			case 5:
				while(make)
				{
					struct doubleLinkedList* newNode = (struct doubleLinkedList*)calloc(1, sizeof(struct doubleLinkedList));
					printf("\n Enter the data for node:");
					scanf("%d", &num);
					newNode->num = num;
					newNode->prev = 0;
					newNode->next = 0;
					if(0 == root)
						root = newNode;
					else
					{
						struct doubleLinkedList* temp = root;
						while(temp->next)
							temp = temp->next;
						temp->next = newNode;
						newNode->prev = temp;
					}
					printf("\n Do you want to make another node in the linked list: Enter 1 for YES 0 for NO:" );
					scanf("%d", &make);
				}
				printf("\n\n Enter the data to be removed:");
				scanf("%d", &num);
				if(0 == root)
				{
					printf("\n Linked list doesnt exists hence this operation cannot be preformed ");
				}
				else
				{
					struct doubleLinkedList* temp = root;
					bool found = 0;
					while(temp)
					{
						if(num != temp->num)
							temp = temp->next;					
						else
						{
							found = 1;
							break;
						}
					}
					if(0 == found)
						printf("\n Node not found which was to be deleted");
					else
					{
						bool ret = 0;
						ret = deleteNodeFromDoubleLinkedList(temp);
						if(0 == ret)
							printf("\n Deletion FAILED");
						else
							printf("\n Deletion SUCCESS");
					}
				}
				break;
			case 6:
				while(make)
				{
					struct singleLinkedList* newNode = (struct singleLinkedList*)calloc(1, sizeof(struct singleLinkedList));
					printf("\n Enter the data for node:");
					scanf("%d", &num);
					newNode->num = num;
					newNode->next = 0;
					if(0 == head)
						head = newNode;
					else
					{
						struct singleLinkedList* temp = head;
						while(temp->next)
							temp = temp->next;
						temp->next = newNode;
					}
					printf("\n Do you want to make another node in the linked list: Enter 1 for YES 0 for NO:" );
					scanf("%d", &make);
				}
				printf("\n\n Enter the data to be removed:");
				scanf("%d", &num);
				if(0 == head)
				{
					printf("\n Linked list doesnt exists hence this operation cannot be preformed ");
				}
				else
				{
					struct singleLinkedList* temp = head;
					bool found = 0;
					while(temp)
					{
						if(num != temp->num)
							temp = temp->next;					
						else
						{
							found = 1;
							break;
						}
					}
					if(0 == found)
						printf("\n Node not found which was to be deleted");
					else
					{
						bool ret = 0;
						ret = deleteNodeFromSingleLinkedList(temp);
						if(0 == ret)
							printf("\n Deletion FAILED");
						else
							printf("\n Deletion SUCCESS");
					}
				}
				break;
			case 7:
				printf("\n To get sizeof without using sizeof ");
				getSizeOfInt();
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

/* Function to identify whether the system is Little Endean or Big Endean */
void identifySystemIsLittleEndeanOrBigEndean()
{
	int i=1;

	if(*(char *)&i)
		printf("\n LITTLE Endean ");
	else
		printf("\n BIG Endean ");

	return;
}

/* Function to count the number of ONEs in an integer */
int countNumOfOnesInADecimalNumber(int num)
{
	int count = 0, i=0;

	for(i = sizeof(int)*8-1; i>=0; i--)
	{
		if((1<<i) & num)
			count++;
	}

	return count;
}

/* Function to display the BINARY representation of a DECIMAL NUMBER */
void displayAllBitsInADecimalNumber(int num)
{
	int i = 0;
	printf("\n displayAllBitsInADecimalNumber: Binary representation of number %d is ", num);

	for(i = sizeof(int)*8-1; i>=0;i--)
	{
		if((1<<i) & num)
			printf("1");
		else
			printf("0");
	}
	return;
}

/* Function to make a string of the BINARY representation of a DECIMAL NUMBER */
char *makeStringOfBinaryRepresentationOfDecimalNumber(int num)
{
	int i = 0;
	char *ch = (char *)calloc(sizeof(int)*8+1, sizeof(char));

	for(i = sizeof(int)*8-1; i>=0; i--)
	{
		if((1<<i) & num)
			ch[i+1]=1+'0';
		else
			ch[i+1]=0+'0';
	}

	printf("\n makeStringOfBinaryRepresentationOfDecimalNumber: String representation of %d number is", num);
	for(i=sizeof(int)*8;i>=0;i--)
		printf("%c", ch[i]);

	printf("\n");

	return ch;
}

/* Function to delete a node from the Double Linked List */
/* NOTE: In this case it is not possible to remove the head node untill and unless you have the pointer to the head node */
/* NOTE: In this case it is possible to remove an intermediate node as well as the last node of linked list */
bool deleteNodeFromDoubleLinkedList(struct doubleLinkedList* node)
{
	bool ret = 0;

	if(0 == node)
		printf("\n Node pointer to be deleted is NULL");
	else
	{
		if(node->prev)
			node->prev->next = node->next;
		else
			root = node->next;
		if(node->next)
			node->next->prev = node->prev;
		free(node);
		node = 0;
		ret = 1;
	}
	return ret;
}

/* Function to delete a node from the Single Linked List */
/* NOTE: In this case it is not possible to remove the head node */
/* NOTE: In this case it is not possible to remove the last node in a linked list untill and unless we have the 
         pointer to previous node */
/* NOTE: In this case it is only possible to remove an intermediate node */
bool deleteNodeFromSingleLinkedList(struct singleLinkedList* node)
{
	bool ret = 0;

	if(0 == node)
		printf("\n Node to be deleted is NULL ");
	else
	{
		if(0 == head)
			printf("\n Single Linked list doesnt exists");
		else
		{
			struct singleLinkedList* temp = 0;
			if(node->next)
			{
				node->num = node->next->num;
				temp = node->next;
				node->next = node->next->next;
				free(temp);
				temp = 0;
				ret = 1;
			}
		}
	}
	return ret;
}

/* Function to get the sizeof without using sizeof */ 
int getSizeOfInt(void)
{
	int retVal = 0;
	int i = 1, j= 0;

	while(i)
	{
		i = i<<1;
		retVal++;
	}
	
	printf("\n Size of int is %d", retVal);
	return retVal;
}