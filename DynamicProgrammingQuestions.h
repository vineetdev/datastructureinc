/*
File: Dynamic Programming Questions Header file
Description: The header file for the corresponding cpp file
Author: Vineet Kumar Srivastava
*/

#ifndef _DYNAMIC_PROGRAMMING_QUESTIONS_H_
#define _DYNAMIC_PROGRAMMING_QUESTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

#define MAX_STRING_LENGTH  128
void printPathsOfNIntegersWhoseSumis0(int n);

int	findZEROLengthPaths(int subSum, int idx, int n, char* string, int stlength);
#endif 