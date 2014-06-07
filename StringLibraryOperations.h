/* This file contains function prototype declarations done for string library functions 
 * Author: Vineet Kumar Srivastava 
 * Date Created: 01st OCTOBER 2010 
 * ---------------------------------------------------------------------------------------
 * MODIFICATION HISTORY 
 * ---------------------------------------------------------------------------------------
 * 01st OCTOBER 2010: Strtok, Strlen, Strcpy, Strcat, Strcmp, Strchr
 * 02nd OCTOBER 2010: Strncat
 * ---------------------------------------------------------------------------------------
 * All the above modifications are done by the Author himself.
 * ---------------------------------------------------------------------------------------
 */

#ifndef STRING_LIBRARY_OPERATIONS_H
#define STRING_LIBRARY_OPERATIONS_H

#include <stdio.h>
#include <conio.h>

const char* Strtok(char* string, char* delimiter); /* Function to implement strtok function */
char* Strcat(char* destination, char* source); /* Function to implement string concatenation */
int Strcmp(const char* str1, const char* str2); /* Function to implement string comparison string library functionality */
int Strlen(const char* string); /* Function to implement Strlen string library function */
char* Strchr(char* str, int character); /* Function to implement strchr string library function */
char* Strcpy(char* destination, const char* source); /* Function to implement strcpy string library function */
char* Strncat(char* destination, const char* source, int num); /* Function to implement Strncat string library function */
char* Strncpy(char* destination, const char* source, int num); /* Function to implement Strncpy string library function */
int Strncmp(const char* str1, const char* str2, int num); /* Function to implement Strncmp string library function */
#endif 