/*
File: Linked List Header file
Description: The header file for the corresponding cpp file
Author: Vineet Kumar Srivastava
*/

#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define NULL 0

/* Data structure for the Linked List */
struct dubLinkList
{
	int data;
	dubLinkList* next;
	dubLinkList* prev;
};

typedef enum
{
	LIST_START = 0,
	LIST_MIDDLE,
	LIST_AFTER_A_NUM,
	LIST_END
}position;

void printList(struct dubLinkList *head); /* Function to print the contents of the Double Linked List */
void addNode(struct dubLinkList **href, position pos); /* Function to add a node in the Double Linked List at the position mentioned */
void delNode(struct dubLinkList **href, position pos); /* Function to del a node in the Double Linked List at the position mentioned */
void freeList(struct dubLinkList **href); /* Function to free the Double Linked List */




#endif 