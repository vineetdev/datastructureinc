/*
File: Linked List Header file
Description: The header file for the corresponding cpp file
Author: Vineet Kumar Srivastava
*/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

/* Data structure for the Linked List */
struct list
{
	int data;
	list* next;
};

/* Function to find the middle of linked list */
int findMiddleOfList(struct list** node);

/* Function to detect a loop in a linked list */
int detectLoopInList(struct list* head, struct list** node);

/* Function to form a loop in a linked list */
int formLoopInList(struct list* head, int data);

/* Function to remove a loop in a linked list */
int removeLoopFromList(struct list* head, struct list* node);

#endif 