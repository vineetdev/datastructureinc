/*
File: Tree Traversals
Description: This file contains all the possible types of traversals on a tree
Author: Vineet Kumar Srivastava
Date: 21st Febraury 2010
*/
#include "Tree.h"

/* Main Program */
void main()
{
	int more=1,d=0, num=-1,a=0,tDepth=0, sum = 0;
	bool ret = TRUE;
	struct node *root=NULL;
	struct node* newTree = NULL;
	printf("Do you want to do Tree Traversals: Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. For Adding a number onto Tree\
				                                          \n 2. For changing the tree structure and getting mirror image\
				                                          \n 3. For Printing the Tree using Preorder Traversal \
									                      \n 4. For Printing the Tree using Inorder Traversal \
				                                          \n 5. For Printing the Tree using Postorder Traversal \
														  \n 6. For Getting the depth of tree \
														  \n 7. For Breadth traversal of tree \
														  \n 8. For PreOrder Traversal without recursion \
														  \n 9. For InOrder Traversal without recursion \
														  \n 10. For PostOrder Traversal without recursion \
														  \n 11. For Generating a new tree after mirroring the original tree \
														  \n 12. For printing all the paths in a tree \
														  \n 13. For checking whether the tree has a given path Sum \
														  \n 14. For checking whether two binary trees are SAME or NOT \
														  \n 15. Get the MINIMUM value from a binary search tree \
														  \n 16. Get the MAXIMUM value from a binary search tree \
														  \n 17. Verify whether the tree is binary search tree or not \
														  \n 18. To get the size of Tree \n:");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				printf(" Enter the number:");
				scanf("%d", &num);
				addNode(&root, num);
				break;
			case 2:
				printf("\n Tree is as follows: ");
				breadthFirstTraversal(root);
				printf("\n Generating the mirror image of tree ");
				mirrorTheTree(root);
				printf("\n After generating the mirror image tree is as follows: ");
				breadthFirstTraversal(root);
				break;
			case 3:
				preorderTraversal(root);
				break;
			case 4:
				inorderTraversal(root);
				break;
			case 5:
				postorderTraversal(root);
				break;
			case 6:
				tDepth = treeDepth(root);
				printf(" Tree depth is %d \n",tDepth);
				break;
			case 7:
				tDepth = breadthFirstTraversal(root);
				break;
			case 8:
				preorderTraversalWithoutRecursion(root);
				break;
			case 9:
				inorderTraversalWithoutRecursion(root);
				break;
			case 10:
				postorderTraversalWithoutRecursion(root);
				break;
			case 11:
				printf("\n Tree is as follows: ");
				breadthFirstTraversal(root);
				printf("\n Generating the mirror image of tree ");
				newTree = mirrorTheTreeToGetnewTree(root);
				printf("\n The New Tree is as follows: ");
				breadthFirstTraversal(newTree);
				break;
			case 12:
				printf("\n Printing all the paths in a tree:");
				printPathsOfTree(root);
				break;
			case 13:
				printf("\n Enter the sum you want to find in tree :");
				scanf("%d", &sum);
				ret = hasPathSum(root, sum);
				if(TRUE == ret)
					printf("\n Got the given path Sum in the tree ");
				else
					printf("\n Given path Sum NOT FOUND in the tree ");
				break;
			case 14:
				ret = sameTree( root, root);
				if(TRUE == ret)
					printf("\n Both the trees are SAME ");
				else
					printf("\n Both the trees are NOT SAME");
				break;
			case 15:
				num = minValue(root);
				if(-1 == num)
					printf("\n MIN value in the tree NOT FOUND as TREE POINTER WAS NULL ");
				else
					printf("\n MIN value in the tree is found and is %d", num);
				break;
			case 16:
				num = maxValue(root);
				if(-1 == num)
					printf("\n MAX value in the tree NOT FOUND as TREE POINTER WAS NULL ");
				else
					printf("\n MAX value in the tree is found and is %d", num);
				break;
			case 17:
				ret = isBST(root);
				if(TRUE == ret)
					printf("\n Its a VALID Binary Search Tree ");
				else
					printf("\n Its an INVALID Binary Search Tree ");
				break;
			case 18:
				num = size(root);
				if(0 == num)
					printf("\n Size of Tree NOT FOUND as TREE POINTER WAS NULL ");
				else
					printf("\n Size of Tree is %d", num);
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

/* Function to add a node to a tree Using recursion */
void addNode(struct node** p, int num)
{
	if(NULL == *p)
	{
		*p=(struct node*)malloc(sizeof(struct node));
		if(NULL == *p)
		{
			printf("\n Failed to allocate memory \n");
		}
		else 
		{
			(*p)->data=num;
			(*p)->right=NULL;
			(*p)->left=NULL;
			printf("\n Number added ");
		}
		return;
	}
	else
	{
		if(num < (*p)->data)
			addNode(&((*p)->left), num);
		else 
			addNode(&((*p)->right), num);
	}
}

/* Function to traverse the tree in preorder way Using Recursion */
void preorderTraversal(struct node *p)
{
	if(NULL == p)
		return;
	else
	{
		printf(" %d ", p->data);
		preorderTraversal(p->left);
		preorderTraversal(p->right);
	}
}

/* Function to traverse the tree in preorder way Using Recursion */
void preorderTraversalWithoutRecursion(struct node *p)
{
	/* Sanity check */
	if(0 == p)
	{
		printf("\npreorderTraversalWithoutRecursion: No Tree OR Tree pointer is NULL ");
		return;
	}

	while(p)
	{
		printf(" %d ", p->data);
		if(0 != p->right)
			push(p->right);
		if(0 != p->left)
			p = p->left;
		else 	
			p = pop();
	}

	return;
}


/* Function to traverse the tree in inorder way Using Recursion */
void inorderTraversal(struct node *p)
{
	if(NULL == p)
		return;
	else
	{
		inorderTraversal(p->left);
		printf(" %d ", p->data);
		inorderTraversal(p->right);
	}
}

/* Function to traverse the tree in inorder way Without Using Recursion */
void inorderTraversalWithoutRecursion(struct node *p)
{
	/* Sanity check */
	if(0 == p)
	{
		printf("\ninorderTraversalWithoutRecursion: No Tree OR Tree pointer is NULL ");
		return;
	}

	/* Traverse one time to the extreme left and add all the elements onto stack */
	while(p)
	{
		push(p);
		p = p->left;
	}

	/* Pop the last leftmost element */
	p = pop();

	/* Process the element and check for its right branch elements */
	while(p)
	{
		printf(" %d ", p->data);
		if(p->right)
		{
			p = p->right;
			/* check for left branch and push all the elements onto stack */
			while(p)
			{
				push(p);
				p = p->left;
			}
		}

		/* Pop the element from stack */
		p = pop();
	}
	return;
}

/* Function to traverse the tree in postorder way Using Recursion */
void postorderTraversal(struct node *p)
{
	if(NULL == p)
		return;
	else
	{
		postorderTraversal(p->left);
		postorderTraversal(p->right);
		printf(" %d ", p->data);
	}
}

/* Function to traverse the tree in postorder way without using Recursion */
void postorderTraversalWithoutRecursion(struct node *p)
{
	struct node* temp = p;

	/* Sanity check */
	if(0 == p)
	{
		printf("\n postorderTraversalWithoutRecursion: No Tree OR Tree pointer is NULL ");
		return;
	}

	while(temp)
	{
		push(temp);
		if(temp->right)
		{
			temp->right->isRightChild = TRUE;
			push(temp->right);
		}
		temp = temp->left;
	}

	temp = pop();

	while(temp)
	{
		if(TRUE != temp->isRightChild)
			printf(" %d ", temp->data);
		else
		{
			temp->isRightChild = FALSE;
			while(temp)
			{
				push(temp);
				if(temp->right)
				{
					temp->right->isRightChild = TRUE;
					push(temp->right);
				}
				temp = temp->left;
			}
		}
		temp = pop();
	}

	return;
}

/* Function to get the depth of tree using Recursion */
int treeDepth(struct node *p)
{
	int h1=0,h2=0;
	if(NULL == p)
		return 0;
	else
	{
		//printf(" %d ", p->data);
		if(p->left)
			h1=treeDepth(p->left);
		if(p->right)
			h2=treeDepth(p->right);
		if(h1>h2)
			return (h1+1);
		else
			return (h2+1);
	}
}


/* Function to do Breadth First Traversal of tree */
int breadthFirstTraversal(struct node* p)
{
	int ret = 0;
	struct node* temp = p;
	if(0 == p)
	{
		printf("\n TREE is EMPTY");
		return ret;
	}
	
	printf("\n Breadth First Traversal of Tree is as follows: \n");
	while(temp)
	{
		printf(" %d ", temp->data);
		if(temp->left)
			addToQueue(temp->left);
		if(temp->right)
			addToQueue(temp->right);

		temp = removeFromQueue();
	}

	return ret;
}


/* Function to push an element onto the stack */
void push(struct node* p)
{
	struct stack *temp = st;
	if(0 == st)
	{
		st = (struct stack*)calloc(1, sizeof(struct stack));
		st->next = 0;
		st->element = p;
	}
	else
	{
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = (struct stack*)calloc(1, sizeof(struct stack));
		temp->next->next = 0;
		temp->next->element = p;
	}
	return;
}

/* Function to pop an element from the stack */
struct node* pop()
{
	struct node* ret = 0;
	struct stack *prev = 0, *temp = st;

	if(0 == st)
	{
		printf("\n Stack is EMPTY");
		return 0;
	}
	while(temp->next)
	{
		prev = temp;
		temp = temp->next;
	}
	ret = temp->element;
	free(temp);

	if(0 == prev)
		st = 0;
	else
		prev->next = 0;

	return ret;
}

/* Function to add an element onto QUEUE */
void addToQueue(struct node* p)
{
	struct queue* queueElement = (struct queue*)calloc(1, sizeof(struct queue));
	queueElement->element = p;
	queueElement->next = NULL;

	if(0 == head)
		head = queueElement;
	else
	{
		struct queue* temp = head;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = queueElement;
	}

	return;
}


/* Function to remove an element from QUEUE */
struct node* removeFromQueue()
{
	struct node* ret = 0;
	struct queue* temp = 0;
	
	if(0 == head)
	{
		printf("\n Queue is EMPTY ");
		return ret;
	}
	else
	{
		ret = head->element;
		temp = head;
		head = head->next;
		free(temp);
		temp = 0;
	}

	return ret;
}

/* Function to mirror the Tree */
void mirrorTheTree(struct node* p)
{
	if(NULL != p)
	{
		struct node* temp = NULL;

		temp = p->left;
		p->left = p->right;
		p->right = temp;
		mirrorTheTree(p->left);
		mirrorTheTree(p->right);
	}

	return;
}

/* Function to GENERATE a NEW Tree by mirroring the OLD Tree */
struct node* mirrorTheTreeToGetnewTree(struct node* p)
{
	struct node* q = NULL;
	if(NULL != p)
	{
		q = (struct node*)calloc(1, sizeof(struct node));
		memcpy(q, p, sizeof(struct node));
		q->left = p->right;
		q->right = p->left;
		q->left = mirrorTheTreeToGetnewTree(q->left);
		q->right = mirrorTheTreeToGetnewTree(q->right);
	}

	return q;
}

/* Another helper function used by printPathsOfTree to print the elements of any array */
void printArr(int *arr, int len)
{
	int i = 0;

	for(i=0;i<len;i++)
		printf(" %d ", arr[i]);

	printf("\n");

	return;
}

/* Recursive helper function to be used by printPathsOfTree to print all the paths of a tree */
void printPaths( struct node* tree, int* path, int pathLen)
{
	if(NULL == tree)
		return;

	path[pathLen] = tree->data;
	pathLen++;
	if((NULL == tree->left) && (NULL == tree->right))
		printArr(path, pathLen);
	else 
	{
		printPaths( tree->left, path, pathLen);
		printPaths( tree->right, path, pathLen);
	}
}

/* Function to print all the paths in a tree */
void printPathsOfTree(struct node* root)
{
	int path[15]={0,};

	printf("\n printPathsOfTree: Entry");
	printPaths( root, path, 0);
	printf("\n printPathsOfTree: Exit");

	return;
}

/* Function to check whether a given path Sum is there in the tree or not */
bool hasPathSum(struct node* root, int sum)
{
	if(NULL == root)
		return(sum == 0);
	else 
	{
		int subSum = sum - root->data;
		return (hasPathSum(root->right, subSum)
			    || hasPathSum(root->left, subSum));
	}
}

/* Function to check whether two binary trees are similar in structure as well as values or not */
int sameTree(struct node* a, struct node* b)
{
	if((NULL == a) && (NULL == b))
		return TRUE;
	else if((NULL == a) || (NULL == b))
		return FALSE;
	else 
	{
		if(a->data == b->data)
			return((sameTree(a->left, b->left)) && (sameTree(a->right, b->right)));
		else 
			return FALSE;
	}
}

/* Function to get the minimum value from a binary search tree */
int minValue(struct node* root)
{
	if(NULL == root)
		return -1;

	while(root->left)
		root = root->left;

	return (root->data);
}

/* Function to get the maximum value from a binary search tree */
int maxValue(struct node* root)
{
	if(NULL == root)
		return -1;

	while(root->right)
		root = root->right;

	return (root->data);
}

/* Utility Recursive Function to Verify whether the tree is binary search tree or not */
bool isBSTUtil(struct node* node, int min, int max)
{
	if(NULL == node)
		return TRUE;


}

/* Function to Verify whether the tree is binary search tree or not */
bool isBST(struct node* root)
{
	if(NULL == root)
	{
		printf("\n isBST: Empty Binary Tree ");
		return FALSE;
	}

	return (isBSTUtil(root, 0, 20));
}

/* Function to get the size of a Tree i.e. number of nodes in it */
int size(struct node* root)
{
	if(NULL == root)
		return 0;
	else
		return(size(root->left) + 1 + size(root->right));
}