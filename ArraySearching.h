#ifndef _ARRAY_SEARCHING_H_
#define _ARRAY_SEARCHING_H_

/*
File: Searching.h
Description: This file contains all the possible types of searching and finds out their computational complexity also
        i.e. Linear search AND Binary Search
Author: Vineet Kumar Srivastava
Date: 21st Febraury 2010
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define MAX_INDEX_COUNT 15
#define NULL 0

void printArr(int *p, int len);
int linearSearchInArr(int *p, int len);
int binarySearchInArr(int *p, int len, int key);
int binarySearchInArrCustom(int *p, int left, int right, int key);
int searchInSortedArr(int *p, int len, int key);
int searchInSortedArrUsingWhile(int *p, int len, int key);
void customMadeDimensionalArray(void);
void customMadeSingleDimensionalArray(void);


#endif 