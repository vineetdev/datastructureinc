/*
File: Header for Sorted Linked List
Description: Header file for the corresponding cpp file
Author: Vineet Kumar Srivastava
*/

#ifndef _SORTED_LINKED_LIST_H_
#define _SORTED_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

typedef struct node{
	int data;
	struct node* next;
};

#define SUCCESS 0
#define FAILURE 1

int insertNumInLinkedList(struct node** root, int num);
int printList(struct node* root);

#endif