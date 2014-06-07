/*
File: Linked List
Description: This file contains all the possible operations on Linked list
        i.e. Adding a node at the start, in between two numbers and at the last,
		     Deleting the head of list, a specific node in the list and the end node of the list,
			 Reversing a linked list,
			 Sorting a linked list.
Author: Vineet Kumar Srivastava
*/

#include "LinkedList.h"

/* Function for printing the Linked List */
void printList(struct list* head)
{
	struct list* temp=head;
	printf("\n");
	while(temp)
	{
		printf("  %d", temp->data);
		temp=temp->next;
	}
}

/* Function for adding a node to the Linked List */
void addNode(struct list** head, int pos)
{
	struct list* tempNode=NULL;
	int data=0;
	switch(pos)
	{
		case 0:
			printf("\nEnter the data:");
			scanf("%d",&data);
			tempNode = (list*)malloc(sizeof(list));
			tempNode->data=data;
			tempNode->next=*head;
			*head=tempNode;
			break;
		case 1:
			tempNode=*head;
			printf("\nEnter the data after which you want to insert data:");
			scanf("%d",&data);
			while(tempNode)
			{
				if(data == tempNode->data )
					break;
				tempNode=tempNode->next;
			}
			if(NULL == tempNode)
				printf("Data after which a node was to be inserted was not found\n");
			else
			{
				struct list* newNode=NULL;
				newNode = (list*)malloc(sizeof(list));
				printf("\nEnter the data which you want to insert:");
				scanf("%d",&data);
				newNode->data=data;
				newNode->next=NULL;
				newNode->next=tempNode->next;
				tempNode->next=newNode;
			}
			break;
		case 2:
			tempNode=*head;
			printf("\nEnter the data:");
			scanf("%d",&data);
			while(tempNode->next)
			{
				tempNode = tempNode->next;
			}
			tempNode->next = (list*)malloc(sizeof(list));
			tempNode->next->data=data;
			tempNode->next->next=NULL;
			break;
	}
}

/* Function for deleting a node from the Linked List */
void delNode(struct list** head, int pos)
{
	struct list* tempNode=NULL;
	struct list* prevNode=NULL;
	int data=0;
	switch(pos)
	{
		case 0:
			printf("\n\nDeleting the head of list\n");
			tempNode = *head; // Store the pointer to the node which is to be deleted
			*head=(*head)->next;  // Move the head pointer
			tempNode->next=NULL;  //Remove the linkage from the node
			free(tempNode);   // Free the node to be deleted
			tempNode=NULL;     // Cautionary: Reset the node
			break;
		case 1:
			printf("\n\nDeleting the node mentioned\n");
			tempNode=*head;
			printf("\nEnter the data after which you want to delete:");
			scanf("%d",&data);
			
			/* Get the node to be deleted */
			while(tempNode)
			{
				if(data == tempNode->data )
					break;
				else
				{
					prevNode=tempNode;
					tempNode=tempNode->next;
				}
			}
			if(NULL == tempNode)
				printf("Node which was to be deleted was not found\n");
			else
			{
				struct list* newNode=NULL;
				newNode=tempNode;   // Store the pointer to the node which is to be deleted
				if(tempNode == *head)
					*head=(*head)->next;
				else
					prevNode->next = tempNode->next;   // Keep the linkage in linked list
				newNode->next=NULL;  // Remove the linkage from the node to be deleted
				free(newNode);    // Free the node
				newNode=NULL;      // Cautionary: Reset the node
			}
			break;
		case 2:
			struct list* newNode=NULL;
			printf("\n\nDeleting the last node\n");
			tempNode=*head;

			/* Get to the last node */
			while(tempNode->next)
			{
				prevNode=tempNode;
				tempNode = tempNode->next;
			}
			newNode=tempNode;   // Store the pointer to the node which is to be deleted
			prevNode->next=NULL;       // Remove the linkage from the node to be deleted
			free(newNode);    // Free the node
			newNode=NULL;      // Cautionary: Reset the node
			break;
	}
}

/* Function for reversing the Linked List */
void reverseList(struct list **head)
{
	//Subroutine to reverse the list
	struct list* current=*head;
	struct list* next=(*head)->next;
	struct list* last=(*head)->next->next;

	while(next)
	{
		next->next=current;
		if(current == *head)
			current->next=NULL;
		current=next;
		next=last;
		if(NULL == last)
			*head=current;
		else
			last=last->next;
	}
}

/* Function to reverse a single linked list*/
void reverseSingleLinkedList(struct list **head)
{
	//Subroutine to reverse the list
	struct list* temp=*head;
	struct list* next=NULL;
	struct list* last=NULL;

	if(NULL == temp)
	{
		printf("\n reverseSingleLinkedList: List is Empty");
		return;
	}

	next = temp->next;
	while(temp)
	{
		if(next)
		{
			last = next->next;
			next->next = temp;
			if(*head == temp)
				temp->next = NULL;
		}
		else
		{
			last = NULL;
			*head = temp;
		}
		temp = next;
		next = last;
	}
	return;
}

/* Function to sort a linked list in either INCREASING ORDER or DECREASING ORDER */
void sortList(struct list **head, int order)
{
	if(0 == order)
	{
		printf(" Sorting in Decreasing Order \n");
	}
	else if(1 == order)
	{
		printf(" Sorting in Increasing Order \n");
	}
	else
		printf("\n Invalid order passed \n");
}

/* Main Routine */
void main()
{
	struct list *head= NULL,*temp=NULL;
	char ans='\0';
	int more=1,d=0,data=0,a=0,pos=0;
	
	printf("Do you want to create a Linked List: Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\nEnter a number:");
			scanf("%d", &data);
			if(NULL == head)
			{
				head=(list *)calloc(1, sizeof(list));
				head->next=NULL;
				head->data=data;
				temp=head;
				printf("Head of the Linked List created\n");
			}
			else
			{
				temp->next=(list *)calloc(1, sizeof(list));
				temp->next->data=data;
				temp->next->next=NULL;
				temp=temp->next;
			}

			printf("\nDo you want to enter one more number: Enter 1 for YES 2 for NO:");
			scanf("%d", &a);
			if(1 == a)
				more=1;
			else
				more=0;
		}
		printf("\nPrinting the contents of List\n");
		printList(head);
		more=1;
		while(more)
		{
			printf("\n Enter one of the following choices \n 1. For Adding a number at the Head  \
  														  \n 2. For adding a number after another Number \
				                                          \n 3. For Adding a number at the Last \
														  \n 4. Deleting the head of list      \
														  \n 5. Deleting a number from the List \
														  \n 6. Deleting the last number from the List \
														  \n 7. Print the contents of the list \
														  \n 8. For REVERSING the Linked List \
														  \n 9. For Sorting the Linked list in Increasing Order \
														  \n 10. For Sorting the Linked list in Decreasing order \
														  \n 11. For finding the middle of linked list \n:");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				pos=0;
				addNode(&head, pos);
				break;
			case 2:
				pos=1;
				addNode(&head, pos);
				break;
			case 3:
				pos=2;
				addNode(&head, pos);
				break;
			case 4:
				pos=0;
				delNode(&head, pos);
				if(NULL != head)
				{
					printf("\nThe resulting linked list is ");
					printList(head);
				}
				else
					printf("\nThe resulting linked list is EMPTY");
				break;
			case 5:
				pos=1;
				delNode(&head, pos);
				if(NULL != head)
				{
					printf("\nThe resulting linked list is ");
					printList(head);
				}
				else
					printf("\nThe resulting linked list is EMPTY");
				break;
			case 6:
				pos=2;
				delNode(&head, pos);
				if(NULL != head)
				{
				printf("\nThe resulting linked list is ");
				printList(head);
				}
				else
					printf("\nThe resulting linked list is EMPTY");
				break;
			case 7:
				printList(head);
				break;
			case 8:
				//reverseList(&head);
				reverseSingleLinkedList(&head);
				printf("\nThe resulting linked list is ");
				printList(head);
				break;
			case 9:
				sortList(&head, 1);
				printf("\nThe resulting linked list is ");
				printList(head);
				break;
			case 10:
				sortList(&head, 0);
				printf("\nThe resulting linked list is ");
				printList(head);
				break;
			case 11:
				data = findMiddleOfList(&head);
				printf("\nThe Middle node of linked list is %d \n", data);
				printf("\n And the linked list is : ");
				printList(head);
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
	getche();
}

int findMiddleOfList(struct list** node)
{
	int num = -1;
	struct list* temp = *node;
	struct list* fastTemp = NULL;

	if(NULL == temp)
	{
		printf("\n findMiddleOfList: List is EMPTY hence no middle exists \n");
		return num;
	}

	if(NULL == temp->next)
	{
		printf("\n findMiddleOfList: List has only one node hence Middle of list is the same node \n");
		num = temp->data;
	}
	else
	{
		fastTemp = temp->next->next;
		while(fastTemp)
		{
			temp = temp->next;
			if(fastTemp->next)
				fastTemp = fastTemp->next->next;
			else
				break;
		}
		num = temp->data;
	}
	if(num != -1)
		printf("\n findMiddleOfList: Middle of Linked list found and is %d \n", num);
	else
		printf("\n findMiddleOfList: Middle of Linked list NOT FOUND \n");

	return num;
}
