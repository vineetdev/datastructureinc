#ifndef _AKAMAI_QUESTIONS_H_
#define _AKAMAI_QUESTIONS_H_

/*
File: AKAMAIQuestions.h
Description: This file contains all the possible types of searching and finds out their computational complexity also
        i.e. Programmes for questions asked in AKAMAI Interview
Author: Vineet Kumar Srivastava
Date: 01 MAY 2010
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

typedef struct doubleLinkedList
{
	int num;
	struct doubleLinkedList* next;
	struct doubleLinkedList* prev;
};

typedef struct singleLinkedList
{
	int num;
	struct singleLinkedList* next;
};

void identifySystemIsLittleEndeanOrBigEndean(); /* Function to identify whether the system is Little Endean or Big Endean */
int countNumOfOnesInADecimalNumber(int num); /* Function to count the number of ONEs in an integer */
void displayAllBitsInADecimalNumber(int num); /* Function to display the BINARY representation of a DECIMAL NUMBER */
char *makeStringOfBinaryRepresentationOfDecimalNumber(int num); /* Function to make a string of the BINARY representation of a DECIMAL NUMBER */
bool deleteNodeFromDoubleLinkedList(struct doubleLinkedList* node); /* Function to delete a node from the Double Linked List */
bool deleteNodeFromSingleLinkedList(struct singleLinkedList* node); /* Function to delete a node from the Single Linked List */
int getSizeOfInt(void); /* Function to get the sizeof without using sizeof */ 
#endif 