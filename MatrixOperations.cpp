/*
File: MatrixOperations.cpp
Description: This file contains implementation of operations on matrix.
Author: Vineet Kumar Srivastava
Date: 25th Febraury 2016
*/

#include "MatrixOperations.h"

/* Function to print the contents of matrix in normal 2D manner */
void printMatrix(int** arr, int iRow,int iCol)
{
	int x = 0, y = 0;
	printf("\n Matrix is ");
	for(x = 0; x < iRow; x++)
	{
		printf("\n");
		for(y = 0; y < iCol; y++)
		{
			printf("\t%d", arr[x][y]);
		}
	}
	printf("\n");
}

/* Main Function */
void main()
{
	int more=1,d=0,a=0,iRow=0,iCol = 0, i=0,j = 0, key = 0;
	int** pArr = 0;
	
	printf("Do you want to do Matrix operations: Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		/* Get the matrix primary details */
		printf("\nEnter the number of Rows in matrix:");
		scanf("%d", &iRow);
		printf("\nEnter the number of Columns in matrix:");
		scanf("%d", &iCol);

		/* Allocate memory to make the Matrix */
		pArr = (int **)calloc(iRow, sizeof(int *));
		for(i=0;i<iRow;i++)
		{
			pArr[i] = (int *)calloc(iCol, sizeof(int));
		}

		/* Make the matrix */
		for(i=0;i<iRow;i++)
		{
			for(j=0;j<iCol;j++)
			{
				printf("\nEnter the [%d][%d]th number:",i, j);
				scanf("%d", &pArr[i][j]);
			}
		}

		printf("\nPrinting the contents of Matrix\n");
		printMatrix(pArr, iRow, iCol);
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. For Traversing the 2D matrix in Sprial manner\
				                                          \n 2. For Traversing the 2D matrix in a simple 2D manner\
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				printf("\n Yet to be implemented \n");
				break;
			case 2:
				printf("\n Printing the contents of Matrix in a simple 2D manner");
				printMatrix(pArr, iRow, iCol);
				break;
			default:
				printf("\n You have not entered a valid choice \n");
				break;
			}
			printf("\nDo you want to do one more operation: Enter 1 for YES 2 for NO:");
			scanf("%d", &a);
			if(2 == a)
				more=0;
			else
				more=1;
		}
	}
	printf(" Do one more key press to Exit\n");
	getche();
}