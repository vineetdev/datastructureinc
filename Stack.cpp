#include "Stack.h"

void main()
{
	int more=1,d=0, num=-1,a=0;
	st.top = -1;
	printf("Do you want to do Stack Operations: Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. For Pushing an element onto Stack\
				                                          \n 2. For Popping an element from the Stack\
				                                          \n 3. For Printing the Stack \n:");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				push();
				break;
			case 2:
				num = pop();
				if(-1 == num)
					printf("\nPop operation FAILED \n");
				break;
			case 3:
				printStack();
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


/* Function to print the contents of Stack */
void printStack()
{
	int j=0;

	if(-1 == st.top)
		printf("\n Stack is EMPTY \n");
	else
	{
		if(MAX_INDEX_COUNT == st.top)
			printf("\n Stack is FULL \n");
		printf(" Stack Elements are:\n");
		for(j=st.top;j>=0;j--)
		{
			printf("\t %d\n", st.arr[j]);
		}
		printf("\n Here the first element will be popped out first \n");
	}
}

/* Function to push a number onto the stack */
void push()
{
	int num=0;

	printf("\n\n Enter the number to be added onto the stack:");
	scanf("%d", &num);

	if((MAX_INDEX_COUNT-1) == st.top)
		printf("\n STACK IS FULL and no more numbers can be added onto the stack i.e. OVERFLOW OCCURED");
	else
	{
		st.top++;             //Step1. Increment the top of stack.
		st.arr[st.top]= num;  //Step2. Put the number in stack.
	}
	return;
}

/* Function to pop a number from the stack */
int pop()
{
	int num=-1;

	if(-1 == st.top)
		printf("\n Stack is EMPTY Hence no more POP can take place i.e. UNDERFLOW OCCURRED\n");
	else
	{
		num=st.arr[st.top];  //Step1. Get the number from stack
		st.top--;            //Step2. Decrement the stack
	}
	return num;
}
