#include "SortedLinkedList.h"

void main()
{
	struct node* root = NULL;
	char ans='\0';
	int more=1,d=0,num=0, ret = SUCCESS;
	
	printf("Do you want to create a Sorted Linked List: Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		more=1;
		while(more)
		{
			printf("\n Enter one of the following choices \n 1. For Inserting a number in the linked list \
				   \n: 2. For displaying the linked list \n:");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				printf("\n Enter the data to be inserted:");
				scanf("%d", &num);
				ret = insertNumInLinkedList( &root, num);
				if(SUCCESS == ret)
					printf("\n Operation is SUCCESS ");
				else
					printf("\n Operation is FAILURE ");
				break;
			case 2:
				ret = printList( root);
				break;
			default:
				printf("\n You have not entered a valid choice \n");
				break;
			}
			printf("\nDo you want to do one more operation: Enter 1 for YES 2 for NO:");
			scanf("%d", &more);
			if(2 == more)
				more=0;
			else
				more=1;
		}
	}
	getche();
}

int insertNumInLinkedList( struct node** root, int num)
{
	int ret = SUCCESS;
	struct node* temp = *root;
	struct node* newNode = NULL;
	struct node* prev = NULL;

	newNode = (struct node*)calloc(1, sizeof(struct node));
	if(NULL == newNode)
	{
		printf("\n Memory allocation to node failed");
		return FAILURE;
	}
	newNode->data = num;
	newNode->next = NULL;

	if(NULL == *root)
	{
		*root = newNode;
	}
	else
	{
		if((*root)->data > num)
		{
			newNode->next = *root;
			*root = newNode;
		}
		else
		{
			while(temp)
			{
				if(temp->data > num)
					break;
				prev = temp;
				temp = temp->next;
			}
			prev->next = newNode;
			if(NULL != temp)
			{
				newNode->next = temp;
			}
		}
	}
	printList(*root);
	return ret;
}

int printList(struct node* root)
{
	int ret = SUCCESS;
	struct node* temp = root;

	if(NULL == root)
	{
		printf("\n LINKED LIST IS EMPTY ");
	}
	else
	{
		printf("\n LINKED LIST IS \t");
		while(temp)
		{
			printf(" %d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

	return ret;
}