/*
File: Stack Operations
Description: This file contains all the possible types of operations possible on a stack
Author: Vineet Kumar Srivastava
Date: 21st Febraury 2010
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define MAX_INDEX_COUNT 15

struct stack
{
	int arr[MAX_INDEX_COUNT];
	int top;
}st;

void printStack();
void push();
int pop();

#endif 