#include "CircularLinkedList.h"

struct node* head = NULL;

void main()
{
	int more = 1, option = 1;

	while(more)
	{
		printf("\n -------------------- MENU DRIVEN OPERATION --------------------");
		printf("\n 1. To add a new element in the circular linked list ");
		printf("\n 2. To display the circular linked list ");
		printf("\n\n Enter your option: ");
		scanf("%d", &option);

		switch(option)
		{
		case 1:
			addToCicrularLinkedList(&head);
			break;
		case 2:
			displayCircularLinkedList(head);
			break;
		default:
			printf("\n You have entered wrong option ");
			break;
		}
		printf("\n Do you want to do one more operation Enter 1 for YES and 0 for NO \n");
		scanf("%d", &more);
		if(more > 1)
			break;
	}
}

/* Function to add a node to a Circular Linked List */
void addToCicrularLinkedList(struct node** head)
{
	int data;
	struct node* newNode = NULL;
	struct node* temp = NULL;

	printf("\n addToCicrularLinkedList: Enter the new data :");
	scanf("%d", &data);

	newNode = (struct node*)calloc(1, sizeof(struct node));
	if(NULL == newNode)
	{
		printf("\naddToCicrularLinkedList: Memory allocation failure HENCE RETURNING ");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;

	if(NULL == *head)
	{
		*head = newNode;
		newNode->next = *head;
		printf("\naddToCicrularLinkedList: Circular Linked List created ");
	}
	else
	{
		temp = *head; 

		while(temp->next != *head)
			temp = temp->next;

		temp->next = newNode;
		newNode->next = *head;
	}

	return;
}

/* Function to display the Circular Linked List */
void displayCircularLinkedList(struct node* temp)
{
	struct node* dispNode = temp;

	if(NULL == temp)
	{
		printf("\n displayCircularLinkedList: Circular Linked List to be displayed is EMPTY");
	}
	else
	{
		printf("\n displayCircularLinkedList: Circular Linked List is \n\t");
		while(dispNode->next != temp)
		{
			printf(" %d ", dispNode->data);
			dispNode = dispNode->next;
		}
		printf(" %d ", dispNode->data);
	}

	printf(" \n ");
	return;
}