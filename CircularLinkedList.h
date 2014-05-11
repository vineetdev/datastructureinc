#ifndef CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define NULL 0

struct node
{
	int data;
	struct node* next;
};

void addToCicrularLinkedList(struct node** head); /* Function to add a node to a Circular Linked List */

void displayCircularLinkedList(struct node* temp); /* Function to display the Circular Linked List */

#endif 