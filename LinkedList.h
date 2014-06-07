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

int findMiddleOfList(struct list** node);

#endif 