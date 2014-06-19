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

#define MAX_ELEMENTS_ALLOWED_IN_LIST 50

/* Function for printing the Linked List */
void printList(struct list* head)
{
	struct list* temp=head;
	int count = 0;

	printf("\n");
	while((temp) && (count < MAX_ELEMENTS_ALLOWED_IN_LIST))
	{
		printf("  %d", temp->data);
		temp=temp->next;
		count++;
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
	struct list* nodeInLoop = 0;
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
														  \n 11. For finding the middle of linked list \
														  \n 12. To make a loop in linked list \
														  \n 13. To detect loop in a linked list \
														  \n 14. To remove the loop from a linked list\n:");
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
			case 12:
				{
					int data = 0;
					printf("\nForming a loop in linked list\n");
					printf("\n Enter the node data from where you want to start the loop in the list ");
					scanf("%d", &data);

					formLoopInList(head, data);
				}
				break;
			case 13:
				printf("\nDetecting loop in linked list\n");
				detectLoopInList(head, &nodeInLoop);
				printf("\n And the linked list is : ");
				printList(head);
				break;
			case 14:
				printf("\n Should be exercised only after executing option 13\n");
				if(0 != nodeInLoop)
				{
					removeLoopFromList(head, nodeInLoop);
				}
				else
					printf("\n Should be exercised only after executing option 13\n");
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


/* Function to find the middle of linked list */
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


/* Function to detect a loop in a linked list */
/* This function uses floyd's loop detection mechanism */
int detectLoopInList(struct list* head, struct list** node)
{
	int iIsLoopPresent = 0;
	struct list* slow_p = head;
	struct list* fast_p = head;

	/* Sanity check on the linked list */
	if(0 == head)
	{
		printf("\n detectLoopInList: List is empty\n");
		return iIsLoopPresent;
	}

	do
	{
		slow_p = slow_p->next;

		if(fast_p->next)
			fast_p = fast_p->next->next;
	}while((slow_p != fast_p) && (0 != fast_p) && (0 != fast_p->next));

	if((0 == fast_p) || (0 == fast_p->next))
		printf("\n detectLoopInList: End of the List reached\n");
	else
	{
		iIsLoopPresent = 1;
		*node = slow_p;
		printf("\n detectLoopInList: End of the List reached\n");
	}

	/* At the last check whether linked list has loop found or not */
	if(1 == iIsLoopPresent)
		printf("\n detectLoopInList: Loop detected in linked list \n");
	else
		printf("\n detectLoopInList: Loop NOT present in Linked list\n");

	return iIsLoopPresent;
}


/* Function to form a loop in a linked list */
int formLoopInList(struct list* head, int data)
{
	int ret_val = 0;
	struct list* node = head;
	struct list* temp = head;

	/* Sanity check on node */
	if(0 == head)
	{
		printf("\n formLoopInList: List provided is NULL\n");
		return ret_val;
	}

	/* Get the node pointer which has to be the loop starting point */
	while((node) && (data != node->data))
		node = node->next;

	/* Verify if we got the node */
	if(0 == node)
	{
		printf("\n formLoopInList: Node not found\n");
		return ret_val;
	}


	/* Traverse till the last of list and make it point to the desired node to make loop */
	while(temp->next)
		temp = temp->next;

	/* Verify if by the given data loop can be made or not */
	if(temp == node)
	{
		printf("\n formLoopInList: Loop cannot be made as last node was provided as the pivotal point\n");
		return ret_val;
	}

	/* Form the loop */
	temp->next = node;

	return ret_val;
}

/* Function to remove a loop in a linked list */
/* Function returns 1 if loop is removed else in all other cases returns 0 */
int removeLoopFromList(struct list* head, struct list* node)
{
	int bRetval = 0, bHeadOfLoopFound = 0;
	struct list* ptrInLoop = node;
	struct list* ptrInList = head;

	while((!bHeadOfLoopFound) && (ptrInList))
	{
		do
		{
			ptrInLoop = ptrInLoop->next;
		}while((ptrInList != ptrInLoop->next) && (node != ptrInLoop) && (ptrInLoop));
		
		if(ptrInList != ptrInLoop->next)
			ptrInList = ptrInList->next;
		else
			bHeadOfLoopFound = 1;

		if(0 == ptrInLoop)
		{
			printf("\n removeLoopFromList: Loop doesnt exists\n");
			break;
		}
	}

	/* Break the loop */
	if((bHeadOfLoopFound) && (ptrInLoop))
	{
		ptrInLoop->next = NULL;
		bRetval = 1;
	}

	return bRetval;
}
/* End Of File */
