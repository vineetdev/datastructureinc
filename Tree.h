/*
File: Header file for Tree Traversals
Description: This file contains all the possible types of traversals on a tree
Author: Vineet Kumar Srivastava
Date: 21st Febraury 2010
*/

#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define TRUE 1
#define FALSE 0

/* Data structure for a node of a tree */
struct node
{
	int data;
	bool isRightChild;
	struct node* right;
	struct node* left;
};

/* Data structure for stack */
struct stack
{
	struct node* element;
	struct stack* next;
};

/* Data structure for queue */
struct queue
{
	struct node* element;
	struct queue* next;
};

struct queue* head= NULL;

struct stack* st;
void printStack();                /* Function to print all the elements in a stack */
void push(struct node* p);         /* Function to push a element onto stack */
struct node* pop();                 /* Function to pop a element from stack */
void addToQueue(struct node* p);    /* Function to add an element onto QUEUE */
struct node* removeFromQueue();     /* Function to remove an element from QUEUE */
void addNode(struct node** p, int num);   /* Function to add a node to a tree */
void preorderTraversal(struct node *p);  /* Function to traverse the tree in preorder way */
void inorderTraversal(struct node *p);  /* Function to traverse the tree in inorder way */
void postorderTraversal(struct node *p); /* Function to traverse the tree in postorder way */
int treeDepth(struct node *p);           /* Function to get the depth of tree using recursion */
void preorderTraversalWithoutRecursion(struct node *p);  /* Function to traverse the tree in Preorder way without using recursion */
void inorderTraversalWithoutRecursion(struct node *p);   /* Function to traverse the tree in Inorder way without using recursion */
void postorderTraversalWithoutRecursion(struct node *p);  /* Function to traverse the tree in Postorder way without using recursion */
int breadthFirstTraversal(struct node* p);  /* Function to do Breadth First Traversal of tree */
void mirrorTheTree(struct node* p); /* Function to mirror the Tree */
struct node* mirrorTheTreeToGetnewTree(struct node* p); /* Function to GENERATE a NEW Tree by mirroring the OLD Tree */
void printPathsOfTree(struct node* root); /* Function to print all the paths in a tree */
bool hasPathSum(struct node* root, int sum); /* Function to check whether a given path Sum is there in the tree or not */
int sameTree(struct node* a, struct node* b); /* Function to check whether two binary trees are similar in structure as well as values or not */
int minValue(struct node* root); /* Function to get the minimum value from a binary search tree */
int maxValue(struct node* root); /* Function to get the maximum value from a binary search tree */
bool isBST(struct node* root); /* Function to Verify whether the tree is binary search tree or not */
int size(struct node* root); /* Function to get the size of a Tree i.e. number of nodes in it */



#endif 