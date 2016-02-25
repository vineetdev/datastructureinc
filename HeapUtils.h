/* Start of file */
#ifndef HEAP_UTILS_H
#define HEAP_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

int maxHeapifyUp(int* pArr, int len, int idx);

int maxHeapifyDown(int* pArr, int len);

int addElementToHeap(int* pArr, int len, int num);

int deleteRootFromHeap(int* pArr, int* len);

void printHeap(int* pArr, int len);

int deleteElementFromHeap(int* pArr, int* len, int idx);

#endif 
/* End of File */