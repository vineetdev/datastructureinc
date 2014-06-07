/* This file contains implementation done for string library functions 
 * Author: Vineet Kumar Srivastava 
 * Date Created: 01st OCTOBER 2010 
 * ----------------------------------------------------------------------
 * MODIFICATION HISTORY 
 * ----------------------------------------------------------------------
 * 01st OCTOBER 2010: Strtok, Strlen, Strcpy, Strcat, Strcmp, Strchr
 * 02nd OCTOBER 2010: Strncat, Strncpy
 * ----------------------------------------------------------------------
 * All the above modifications are done by the Author himself.
 * ----------------------------------------------------------------------
 */

#include "StringLibraryOperations.h"

void main()
{
	int more=1,d=0, count=0, num = 0,i =0, make = 1, a = 0;
	const char *retString = 0;

	printf("Do you want to look for any operation to be done Enter 1 for YES 2 for NO:\n");
    scanf("%d", &d);
	
	if(1==d)
	{
		while(more)
		{
			printf("\n Enter one of the following choices \n\n 1. Strtok - Tokenize a string \
				                                          \n 2. Strcat - concatenation of two strings \
														  \n 3. Strcmp - comparison of two strings \
														  \n 4. Strlen - length of string \
														  \n 5. Strchr - get the first occurence of a given character in a given string \
														  \n 6. Strcpy - copy the source string into the destination string \
														  \n 7. Strncat - concatenation of two strings upto the first num characters of source onto the deestination \
														  \n 8. Strncpy - copy the first num characters from source string onto the destination string \
														  \n 9. Strncmp - compares the first num characters of both the strings \
														  \n 10. Strrchr - Locates the last occurence of a character in a string \
														  \n 11. Strstr - \
														  \n\n Enter your option :");
			scanf("%d", &d);
			switch(d)
			{
			case 1:
				{
				char* str = "I Love My India";
				retString = Strtok( str, " ,");
				printf("\n %s", retString);
				retString = Strtok( 0, " ,");
				printf("\n %s", retString);
				retString = Strtok( 0, " ,");
				printf("\n %s", retString);
				retString = Strtok( 0, " ,");
				printf("\n %s", retString);
				retString = Strtok( 0, " ,");
				if(retString)
					printf("\n %s", retString); 
				}
				break;
			case 2:
				{
					char string[30]= " Vineet ";
					retString = Strcat( string, "Kumar Srivastava");
					printf("\n %s", retString); 
				}
				break;
			case 3:
				{
					int compResult = 0;
					compResult = Strcmp("Vineet 1", "Vineet ");
					printf("\n Result of string comparison is %d", compResult);
				}
				break;
			case 4:
				{
					int strLen = Strlen("Vineet ");
					printf("\n Length of string is %d ", strLen);
				}
				break;
			case 5:
				{
					char* result = Strchr("Vineet", 'i');
					if(result)
						printf("\n First occurence of e in Vineet is found at %s ", result);
				}
				break;
			case 6:
				{
					char str[40]={0,};
					char* strResult = Strcpy(str, "Ram Ram Tau");
					printf("\n Result of string copying is %s", strResult);
				}
				break;
			case 7:
				{
					char ch[30]="Vineet ";
					char* strResult = Strncat( ch, "Kumar ", 12);
					printf("\n Result of copying %d characters of %s onto %s is %s", 12, "Kumar ", ch, strResult);
				}
				break;
			case 8:
				{
					char ch[30]={0,};
					char* strResult = Strncpy(ch, "Vineet ", 25);
					printf("\n Result of copying %d characters of %s onto another string is %s", 25, ch, strResult);
					break;
				}
			case 9:
				{
					int result = Strncmp("Vineet Kumar 1", "Vineet Kumar ", 15);
					printf("\n Result of Strncmp operation is %d", result);
					break;
				}
			case 10:
				{
					break;
				}
			case 11:
				{
					break;
				}
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

/* This function will check whether a given character is a delimiter or not */
bool isNotADelimiter(char** ch, char* delimiter, int isTokenStartFound)
{
	char* limiter = delimiter;
	bool ret = 1;
	while('\0' != *limiter)
	{
		if(*limiter == **ch)
		{
			ret = 0;
			if(0 == isTokenStartFound)
			{
				(*ch)++;
				limiter = delimiter;
				ret = 1;
			}
			else
				break;
		}
		else
			limiter++;
	}

	return ret;
}

/* Function to implement strtok function */
const char* Strtok(char* string, char* delimiter)
{
	static char* str = string;
	static char ret[] = {'\0',};
	int IsTokenStartFound = 0;
	int len = 0;

	/* When next NOT NULL string is provided */
	if((*str == '\0') && (0 != string))
	{
		str = string;
	}

	/* If delimiter is NULL	return the original string as NO TOKEN FOUND */
	if(0 == delimiter)
		return string;

	/* Tokenize the string and copy the token found in a local array */
	while( (isNotADelimiter(&str, delimiter, IsTokenStartFound)) && (*str != '\0'))
	{
		IsTokenStartFound = 1;
		ret[len] = *str;
		str++;
		len++;
	}

	/* Return the correct string */
	if('\0' == *str)
	{
		if((0 == string) && (0 != len))
			return ret;
		else
			return string;
	}
	else 
	{
		ret[len] = '\0';
		return ret;
	}
}

/* Function to implement string concatenation library function */
char* Strcat(char* destination, char* source)
{
	char* ret = destination;

	if(0 == destination)
		return 0;

	/* Get to the end of destiation string */
	while('\0' != *destination)
		destination++;

	/* Append the characters of source string onto the destination string */
	while('\0' != *source)
	{
		*destination = *source;
		source++;
		destination++;
	}

	/* Put the NULL character at the end of destination string */
	*destination = '\0';

	return ret;
}

/* Function to implement string comparison string library functionality */
int Strcmp(const char* str1, const char* str2)
{
	int result = 0;

	/* Compare the two strings */
	while(('\0' != *str1) || ('\0' != *str2))
	{
		if(*str1 != *str2)
		{
			result = *str1 - *str2;
			break;
		}
		str1++;
		str2++;
	}

	return result;
}

/* Function to implement Strlen string library function */
int Strlen(const char* string)
{
	int strLen = 0;

	/* Get the length of string uptill we dont encounter NULL character */
	while('\0' != *string)
	{
		strLen++;
		string++;
	}

	return strLen;
}

/* Function to implement strchr string library function */
char* Strchr(char* str, int character)
{
	char* retString = 0;

	/* Searching for the first occurence of character in string */
	while(( character != *str) && ('\0' != *str))
		str++;

	/* If found then return the string pointer at the place where string is found */
	if( character == *str)
		retString = str;

	return retString;
}

/* Function to implement strcpy string library function */
char* Strcpy(char* destination, const char* source)
{
	char* ret = destination;

	/* While loop to copy the source string onto the destination */
	while('\0' != *source)
	{
		*destination = *source;
		source++;
		destination++;
	}

	/* Put NULL character at the end of destination string as source string will have NULL character */
	*destination = '\0';

	return ret;
}

/* Function to implement Strncat string library function */
char* Strncat(char* destination, const char* source, int num)
{
	char* ret = destination;
	int charCopiedCount = 0;
	
	/* Reach to the end of the destination string */
	while('\0' != *destination)
		destination++;

	/* Append the first num characters from source string onto the destination string */
	while((charCopiedCount != num) && ('\0' != *source))
	{
		*destination = *source;
		source++;
		destination++;
		charCopiedCount++;
	}

	/* Put the NULL character at the last of destination string */
	*destination = '\0';

	return ret;
}

/* Function to implement strncpy string library function */
char* Strncpy(char* destination, const char* source, int num)
{
	char* ret = destination; /* This variable is used to return the destination string itself */

	/* Loop to copy first num characters from source string onto the destination string */
	while((0 != num) && ('\0' != *source))
	{
		*destination = *source;
		source++;
		destination++;
		num--;
	}

	/* If Null of source is reached and num is still not zero */
	if(('\0' == *source) && (0 != num))
	{
		*destination = *source;
		while(0 != num)
		{
			*destination = 0;
			num--;
		}
	}

	return ret;
}

/* Function to implement Strncmp string library function */
int Strncmp(const char* str1, const char* str2, int num)
{
	int result = 0;

	/* While loop to compare the two strings character by character uptill the count num */
	while((0 != num) && (('\0' != *str1) || ('\0' != *str2))) 
	{
		if(*str1 != *str2)
		{
			result = *str1 - *str2;
			break;
		}
		str1++;
		str2++;
		num--;
	}

	return result;
}