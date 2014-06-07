/*
File: MicrosoftAskedQuestions.h
Description: This is the header file for the corresponding cpp file
Author: Vineet Kumar Srivastava
Date: 01 MAY 2010
*/

#ifndef _MICROSOFT_ASKED_QUESTIONS_H_
#define _MICROSOFT_ASKED_QUESTIONS_H_


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define FALSE 0
#define TRUE 1

char* xitoa(int num); /* Function to do itoa without using any string function */
void xstrrev(char* ch); /* Function to do string reversal */
char* xstrstr(char* s1, char* str); /* Function to search for a small string from a big string */
int findMaxNumberInArr(int* arr, int start, int len); /* Function to find the maximum number in an array */
int findMaxSubsumInArr(int* arr, int len); /* Function to find the maximum subsum in an array */
int findMaxSubsumInArrWithLesserComplexity(int* arr, int len); /* Function to find the maximum subsum in an array Lesser complexity*/
int findIndexOfMaxNumInArray(int *arr, int len); /* Function to find the index of maximum number in array */
void arrangeElementsOfArray(int *arr, int len); /* A function to arrange negative numbers at the starting of list */

#endif 