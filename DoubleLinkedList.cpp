/*
*  Copyright Vineet Kumar Srivastava
*  This program was developed by Vineet Kumar Srivastava who is also the copyright owner.
*  This code will be available as open source and can be used for teaching and self development process
*  But this code cannot be used for professional purpose. In that case you can contact me for a licence.
*  Date Created: 20th November 2010
*/
#include "DoubleLinkedList.h"

/* Main Routine */
void main()
{
	struct dubLinkList *head= NULL,*temp=NULL;
	int more=1,d=0,data=0, a = 0;
	position pos = LIST_START;
	
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
				head=(dubLinkList *)calloc(1, sizeof(struct dubLinkList));
				head->next=NULL;
				head->data=data;
				head->prev = NULL;
				temp=head;
				printf("Head of the Linked List created\n");
			}
			else
			{
				temp->next=(dubLinkList *)calloc(1, sizeof(struct dubLinkList));
				temp->next->data=data;
				temp->next->next=NULL;
				temp->next->prev = temp;
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
														  \n 8. For REVERSING the Linked List \n:");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				pos=LIST_START;
				addNode(&head, pos);
				printList(head);
				break;
			case 2:
				pos=LIST_AFTER_A_NUM;
				addNode(&head, pos);
				printList(head);
				break;
			case 3:
				pos=LIST_END;
				addNode(&head, pos);
				printList(head);
				break;
			case 4:
				pos=LIST_START;
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
				pos=LIST_AFTER_A_NUM;
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
				pos=LIST_END;
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
				printf("\nThe resulting linked list is ");
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

		/* Free the linked list before exiting from the program */
		if(head)
			freeList(&head);
	}
	getche();
}

/* Function to print the contents of the Double Linked List */
void printList(struct dubLinkList *head)
{
	struct dubLinkList *temp = head;
	printf("\n The List is ");
	while(temp)
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

/* Function to add a node in the Double Linked List at the position mentioned */
void addNode(struct dubLinkList **href, position pos)
{
	/* Do the memory allocation to the new node first as it is a common operation */
	int num = -1;
	struct dubLinkList *temp = *href;
	struct dubLinkList *newNode = (struct dubLinkList *)calloc(1, sizeof(struct dubLinkList));
	printf("\n addNode: Enter the data:");
	scanf("%d", &num);
	newNode->data = num;
	switch(pos)
	{
	case LIST_START:
		{
			newNode->next = *href;
			if(NULL != *href)
			{
				(*href)->prev = newNode;
			}
			*href = newNode;
			printf("\n addNode: Added node at the start of the Double Linked list");
		}
		break;
	case LIST_AFTER_A_NUM:
		{
			int ref = -1;
			printf("\n addNode: Enter the data after which you want to insert a data :");
			scanf("%d", &ref);
			while( temp && (ref != temp->data)) 
				temp = temp->next;
			if(NULL != temp)
			{
				printf("\n addNode: Key found, Inserting data ");
				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;
				printf("\n addNode: data inserted ");
			}
			else
			{
				printf("\n addNode: key not found in the list, please try again");
				if(newNode)
				{
					free(newNode);
					newNode = NULL;
				}
			}
		}
		break;
	case LIST_END:
		{
			/* Move to the last node in the linked list */
			while(temp->next)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
			printf("\n addNode: Added at the last in the Doubly Linked List");
		}
		break;
	default:
		{
			printf("\n addNode: Not handled for %d value of pos", pos);
			if(newNode)
			{
				free(newNode);
				newNode = 0;
			}
		}
	}
}

/* Function to del a node in the Double Linked List at the position mentioned */
void delNode(struct dubLinkList **href, position pos)
{
	struct dubLinkList *temp = *href;
	struct dubLinkList *nodeToBeDeleted = NULL;
	if(NULL == *href)
	{
		printf("\n delNode: List is empty, hence returning ");
		return;
	}

	switch(pos)
	{
	case LIST_START:
		{
			nodeToBeDeleted = *href;
			*href = (*href)->next;
			if(*href)
				(*href)->prev = NULL;
			free(nodeToBeDeleted);
			nodeToBeDeleted = NULL;
		}
		break;
	case LIST_AFTER_A_NUM:
		{
			int key = -1;
			printf("\n delNode: Enter the key:");
			scanf("%d", &key);
			while(key != temp->data)
				temp = temp->next;

			if(NULL == temp)
			{
				printf("\n delNode: key not found ");
				return;
			}
			else
			{
				printf("\n delNode: Key found ");
				nodeToBeDeleted = temp;
				if(temp->prev)
					temp->prev->next = temp->next;
				if(temp->next)
					temp->next->prev = temp->prev;
				if(temp == *href)
					*href = NULL;
				free(nodeToBeDeleted);
				nodeToBeDeleted = NULL;
			}
		}
		break;
	case LIST_END:
		{
			while(temp->next)
				temp = temp->next;

			nodeToBeDeleted = temp;
			if(temp->prev)
				temp->prev->next = NULL;
			else
				*href = NULL;
		}
		break;
	default:
		printf("\n delNode: Unhandled value %d for pos ", pos);
	}
}

/* Function to free the Double Linked List */
void freeList(struct dubLinkList **href)
{
	struct dubLinkList *temp = *href;
	struct dubLinkList *nodeToBeFreed = NULL;

	while(temp)
	{
		nodeToBeFreed = temp;
		temp = temp->next;
		*href = temp;
		free(nodeToBeFreed);
		nodeToBeFreed = NULL;
	}

	printf("\n freeList: All the nodes in the Double Linked List are freed ");
}

/* End of File */