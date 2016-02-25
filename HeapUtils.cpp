/*
File: HeapUtils.h
Description: This file has the utility function implementation for heap
Author: Vineet Kumar Srivastava
Date: 23rd Febraury 2016
*/

#include "HeapUtils.h"

/* Function to re-heap - it will reheap the top element of heap */
int maxHeapifyDown(int* pArr, int len)
{
	int iRet = 0, idx = 0, iRtChildIdx = 0, iLtChildIdx = 0;

	iRtChildIdx = 2*idx + 2;
	iLtChildIdx = 2*idx + 1;
	while((iRtChildIdx <= len) 
		&& (iLtChildIdx <= len))
	{
		if(pArr[iRtChildIdx] > pArr[iLtChildIdx])
		{
			if(pArr[idx] < pArr[iRtChildIdx])
			{
				int temp = pArr[iRtChildIdx];
				 pArr[iRtChildIdx] =  pArr[idx];
				 pArr[idx] = temp;
				 idx = iRtChildIdx;
			}
			else
				break;
		}
		else
		{
			if(pArr[idx] < pArr[iLtChildIdx])
			{
				int temp = pArr[iLtChildIdx];
				 pArr[iLtChildIdx] = pArr[idx];
				 pArr[idx] = temp;
				 idx = iLtChildIdx;
			}		
			else
				break;
		}

		iRtChildIdx = 2*idx + 2;
		iLtChildIdx = 2*idx + 1;
	}
	
	printf("\n maxHeapifyDown: Done ");
	return iRet;
}


/* Function to re-heap - it will reheap starting from the element index provided */
int maxHeapifyIndexDown(int* pArr, int len, int index)
{
	int iRet = 0, idx = index, iRtChildIdx = 0, iLtChildIdx = 0;

	iRtChildIdx = 2*idx + 2;
	iLtChildIdx = 2*idx + 1;
	while((iRtChildIdx <= len) 
		&& (iLtChildIdx <= len))
	{
		if(pArr[iRtChildIdx] > pArr[iLtChildIdx])
		{
			if(pArr[idx] < pArr[iRtChildIdx])
			{
				int temp = pArr[iRtChildIdx];
				 pArr[iRtChildIdx] =  pArr[idx];
				 pArr[idx] = temp;
				 idx = iRtChildIdx;
			}
			else
				break;
		}
		else
		{
			if(pArr[idx] < pArr[iLtChildIdx])
			{
				int temp = pArr[iLtChildIdx];
				 pArr[iLtChildIdx] = pArr[idx];
				 pArr[idx] = temp;
				 idx = iLtChildIdx;
			}		
			else
				break;
		}

		iRtChildIdx = 2*idx + 2;
		iLtChildIdx = 2*idx + 1;
	}
	
	printf("\n maxHeapifyIndexDown: Done ");
	return iRet;
}

/* Function to adjust the number whose index is provided in the Max heap */
int maxHeapifyUp(int* pArr, int len, int idx)
{
	int iRet = 0, iUpIdx = 0, index = idx;

	if(0 == pArr)
	{
		printf("\n heapify: Array pointer is empty\n");
		return -1;
	}

	iUpIdx = index;
	while(index)
	{
		if((index/2) && (0 == index%2))
			iUpIdx = ((index/2) - 1);
		else
			iUpIdx = index/2;

		if(pArr[idx] > pArr[iUpIdx])
		{
			int temp = pArr[iUpIdx];
			pArr[iUpIdx] = pArr[index];
			pArr[index] = temp;
		}
		else
			break;

		index = iUpIdx;
	}
	return iRet;
}

/* Function to add a element to the heap */
int addElementToHeap(int* pArr, int len, int num)
{
	int iRet = 0;

	if(0 == pArr)
	{
		printf("\n addElementToHeap: Array pointer is empty\n");
		return -1;
	}

	pArr[len] = num;
	maxHeapifyUp(pArr, len, len);

	return iRet;
}

/* Function to delete the root from the heap */
int deleteRootFromHeap(int* pArr, int* len)
{
	int iRet = 0;
	
	pArr[0] = pArr[(*len)-1];
	*len = *len - 1;

	printf("\n deleteRootFromHeap: Heap after deleting the root ");
	printHeap(pArr, *len);
	
	maxHeapifyDown(pArr, *len);
	
	printf("\n deleteRootFromHeap: Heap after reheap down ");
	printHeap(pArr, *len);

	return iRet;
}

/* Function to delete the root from the heap */
int deleteElementFromHeap(int* pArr, int* len, int idx)
{
	int iRet = 0, iParentIdx = 0;
	
	pArr[idx] = pArr[(*len)-1];
	pArr[(*len)-1] = -1;
	*len = *len - 1;

	printf("\n deleteRootFromHeap: Heap after deleting the root ");
	printHeap(pArr, *len);
	
	/* Get the parent node index */
	if((idx/2) && (0 == idx%2))
		iParentIdx = ((idx/2) - 1);
	else
		iParentIdx = idx/2;

	if(pArr[idx] <= pArr[iParentIdx])
		maxHeapifyIndexDown(pArr, *len, idx);
	else
		maxHeapifyUp(pArr, *len, idx);
	
	printf("\n deleteRootFromHeap: Heap after reheap down ");
	printHeap(pArr, *len);

	return iRet;
}


/* Function to print the contents of heap */
void printHeap(int* pArr, int len)
{
	int idx = 0;
	printf("\n printHeap: Heap is\t");

	for(idx = 0; idx < len; idx++)
	{
		printf("%d\t", pArr[idx]);
	}

	printf("\n");
}