#include<stdio.h>
#include<string.h>

//Array, string and pointer

/* Find out the string length of a string */
int xstrlen(char *s)
{
	char *p;

	for(p = s; *s != '\0'; s++);

	return s-p;
}

/* string copy */
void xstrcpy(char *source, char *dest)
{
	for(;(*dest++ = *source++) !='\0';);

	*dest = '\0';
}
/* string concatenation */
void xstrcat(char *s1, char *s2)
{
	for(; *s1 != '\0';s1++);

	for(; (*s1=*s2) != '\0'; s2++,s1++);

	*s1 = '\0';
}
/* String comparision */
int xstrcmp(char *s, char *t)
{
	for(;*s == *t && *s != '\0';s++,t++);

	if(*t == '\0' && *s == '\0')
		return 0;
	else
		return s-t;
}
/* String reverse */
void xstrev(char *s)
{
	int i,j, len;
	
	len = xstrlen(s);
	for(i = 0, j = len -1; i<j; i++,j--)
	{
		s[len] = s[i];
		s[i] = s[j];
		s[j] = s[len];
	}
	s[len] ='\0';
}
/* strchr */
char *xstrchr(char *s, int c)
{
	while(*s)
	{
		if(*s == (char)c)
			return s;
		s++;
	}
	return 0;
}

/* Memmove implementation */
void *xmemmove(void *dest, void *src, int size)
{
	char *pd = dest;
	char *ps = src;

	while(size--)
		*pd++ = *ps++;

	return dest;
}
/* strstr implementation */
char *xstrstr(char *s, char *t)
{
	int i,j,k;

	for(i = 0; s[i] != '\0';i++)
	{
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k];j++,k++);

		if(t[k] == '\0')
			return s[i];
	}
	return 0;
}

/* convetrt ascii to integer */
int xatoi(char *s)
{
	int sign,d = 0;

	sign = (*s == '-')?-1:1;

	if(*s == '-' || *s == '+')
		s++;

	while(*s >= '0' && *s <= '9')
	{
		d = d * 10 +(*s - '0');
		s++;
	}
	return d * sign;
}
/*convert int to ascii */ 
void xitoa(char *s, int d)
{
	int i = 0,sign, n;
	
	sign = (d < 0)? -1:1;

	d = sign *d;

	while(d > 0)
	{
		n = d%10;
		d = d/10;
		s[i] = n + '0';
		i++;
	}
	if(sign == -1)
		s[i++] = '-';

	s[i] = '\0';

	xstrev(s);

}
/* Convert ascii to float*/
float xatof(char *s)
{
	int sign;
	float f;
	int d = 0, pow = 1;

	sign = (*s == '-')?-1:1;

	if(*s == '-' || *s == '+')
		s++;

	while(*s >= '0' && *s <= '9')
	{
		d = d *10 + (*s - '0');
		s++;
	}
	if(*s == '.')
	{
		s++;

		while(*s >= '0' && *s <= '9')
		{
			d = d *10 + (*s - '0');
			s++;
			pow = pow * 10;
		}
	}
	f = (float)d/pow;

	return f;
}
/* Convert int to char base Hex, oct*/
void itob(int n, char *s, int base)
{
	int i = 0, sign = 1;
	int d;

	if(n < 0)
		sign = -1;

	while(n > 0)
	{
		d = n % b;

		s[i++]= (d <= 9)? d + '0' : d +'a'-10;
		n = n/b;
	}
	if(sign > 0)
		s[i++] = '-';

	s[i] = '\0';

	xstrev(s);
}
int is_digit(int d)
{
	if(d >= '0' && d <= '9')
		return 1;
	else
		return 0;
}
int tolower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c-'A'+'a';
	else
		return c;
}
	
int toupper(int c)
{
	if(c >= 'a' && c <= 'z')
		return c-'a'+'A';
	else
		return c;
}
void swap(int a, int b)
{
	printf("Before swap value of a is %d and b is %d", a,b)
	a = a^b;
	b = a^b;
	a = a^b;

	printf("After swap value of a is %d and b is %d", a,b)
}
//Write a C program to reverse the words in a sentence in place.

void Reverse(char *s, int beg, int end)
{
	int c;

	for(;beg < end; beg++, end--)
	{
		c = s[beg];
		s[beg] = s[end];
		s[end] = c;
	}
}
void wordrev(char *s)
{
	int beg = 0, end, idx;
	//1. word by word reverse.
	end = xstrlen(s);
	Reverse(s, beg, end -1);
	while(beg < end)
	{
		for(idx = beg; s[idx] != " " || s[idx] != '\0';idx++);

		Reverse(s, beg, idx -1);
		beg = idx + 1;
	}
	//2. usin strtok
	    //wordrev(strtok(s, " "));
	    //void wordrev(char *s)
		//{
		//	if(s == NULL)
		//		return;
		//	else
		//	{
		//		wordrev(strtok(NULL, " ");
		//		printf("%s", s);
		//	}
		//}

	//3. Using linklist
}
int factorial(int n)
{
	if(n == 1)
		return 1;
	else
		return n*factorial(n-1);
}

//Write a C program to calculate pow(x,n)?

int pow(int x, int n)
{ 
	if(n == 1)
		return 1;
	else
		return x*pow(x,n-1);
}
//generate fibonacci numbers
int fibonacii(int n)
{
	if(n <= 2)
		return 1;
	else
		return (fibonacii(n-1) + fibonacii(n-2));
}
//max seq of sub array from array.
void find_subarray(int array1[])
{
	int first_current_index = 0, last_current_index = 0;
	int first_prev_index = 0, last_prev_index = 0;
	int i;

	for(i = 0; i < 10; i++)
	{
		if(array1[i+1] > array1[i])
		{
			last_current_index = i;
		
			if((last_current_index - first_current_index) > (last_prev_index - first_prev_index))
			{
				first_prev_index = first_current_index;
				last_prev_index = last_current_index;
			}
			first_current_index = i + 1;
		}
	}
	printf("Max sub array found at begin seq is %d and end seq is %d", first_prev_index, last_prev_index);
}
//max sum of sub array from array.
void find_max_sum_subarray(int array1[])
{
	int prev_max = 0, current_max = array1[0];
	int i;

	for(i = 0; i < 10; i++)
	{
		if(array1[i+1] > array1[i])
		{
			current_max += array1[i+1];
		}
		else
		{
			if(prev_max < current_max)
				prev_max = current_max;
			current_max = array1[i+1];
		}
	}
	printf("max sum of sub array is %d",prev_max);
}
//Write C code to return a string from a function
/* Solution 1 : use malloc */
/* solution 2 : use static decarion */

//Write a C progam to convert from decimal to any base (binary, hex, oct)
void decimal_anybase(int n, int base)
{
	int i = 0, d;
	char digits[100] = {0};

	while(n> 0)
	{
		d = n % base;
		digits[i++] = (d <=9)?(d + '0'):(d + 'a'-10);
		n = n/10;
	}
	for(;i>=0;i--)
		printf("%c",digits[i]);
}
//Write C code to check if an integer is a power of 2 or not in a single line?
void powerof_two(int n)
{
	if(((~n + 1) & n) == n)
		printf("Number is power of 2");
	else
		printf("Number is not power of 2");
}
//Write code to find duplicates in a array. eg. 1,2,3,3,4,3,5,6,5
void find_duplicates(int &array1, int size)
{
	int i, d;
	int array2[size] = {0};

	for(i = 0; i < size; i++)
	{
		d = array1[i] % size;

		if(array2[d] != 0)
			printf("Number %d is duplicate\n",d);
		else
			array2[d] = d;
	}
}
//Write C code to dynamically allocate one, two and three dimensional arrays (using malloc()
void allocate_memory()
{
	int rows =2, column = 3, depth = 3;
	int i, j;
	int *p; //one dimensional
	int **q; //2 dimensional
	int ***r; //3 dimensional

	//one dimensional
	p = (int *) malloc(10);

	//2 Dimensional
	q = (int **)malloc(rows * sizeof(int));
	for(i = 0; i < rows; i++)
	{
		q[i] = malloc(column * sizeof(int));
	}

	//3 dimensional
	r = (int ***)malloc(rows * sizeof(int));
	for(i = 0; i < column; i++)
	{
		r[i] = (int **)malloc(column * sizeof(int));
		for(j = 0; j < depth; j++)
		{
			r[i][j] = (int *)malloc(depth * sizeof(int));
		}
	}
}
//How would you find the size of structure without using sizeof()?
void xsizeof()
{
	struct mystruct
	{
		int a;
		int b;
	};

	struct mystruct *p;
	int size;

	size = ((char*)(p+1)) - (char*)p;
}
//Write a C program to check for palindromes.
int is_palindrome(char *s)
{
	int len, flag = 1;
	int i, j;

	len = strlen(s);

	for(i = 0, j = len -1; i < j; i++, j--)
	{
		if(s[i] != s[j]
		{
			flag = 0;
			break;
		}
	}

	if(flag == 1)
		printf("string %s is palindrome", s);
}

void main()
{
	int operation;

	printf(" 1: String length\n 2: String copy\n 3: Concatenate string\n 4:  String comparision\n");
	printf(" 5: String reverse\n 6: Strchr Implementation\n 7: Memmove implementation\n 8:  strstr implementation\n");
	printf(" 9: convetrt ascii to integer\n 10: convert int to ascii\n 11: Convert ascii to float\n");
	printf(" String Operations: Please enter your choice\n");
	
	scanf("%d",&operation);

	switch(operation)
	{
		case 1:
		{
			int len;
			char s[20] = {0};

			xstrcpy("Hello Vapes", s);
			len = xstrlen(s);

			printf("string length is %d", len);
		}
		break;
		case 2:
		{
			char src[20] = "Hello Vapes";
			char dst[20] = {0};

			xstrcpy(src, dst);			
			printf("string copy of dest is %s", dst);
		}
		break;
		case 3:
		{
			char src[20] = "Hello ";
			char dst[10] = "Vapes";

			xstrcat(src, dst);			
			printf("After string concatenate string is %s", src);
		}
		break;
		case 4:
		{
			char src[20] = "Hello ";
			char dst[10] = "Hello";

			if(0 == xstrcmp(src, dst))
				printf("String comparision success \n");	
			else
				printf("String comparision Failed \n");
		}
		break;
		case 5:
		{
			char src[20] = "Hello ";
			
			xstrev(src);
			printf("String reverse is %s \n",src);	
		}
		break;
		case 6:
		{
			char *temp;
			char src[20] = "Hello Vapes";
			
			temp = xstrchr(src, ' ');
			printf("String char is %s \n",temp);	
		}
		break;
		case 7:
		{
			char s1[20] = "Hello Vapes";
			char s2[10] = {0};

			xmemmove(s2, s1, 5);

			printf("After memmove string is %s", s2);
		}
		break;
		case 8:
		{
			char s1[20] = "Hello Vapes";
			char s2[10] = "Vapes";

			if(xstrstr(s1,s2))
				printf("Substring found");
			else
				printf("Substring not found");
		}
		break;
		case 9:
		{
			int d;
			char s[10] = "-1234";
			
			d = xatoi(s);

			printf("%d", d);
		}
		break;
		case 10:
		{
			int d = 1234;
			char buffer[10] = {0};
			
			xitoa(buffer, d);
			
			printf("%s", buffer);
		}
		break;
		case 11:
		{
			float d;
			char s[20] = "12345.12";
			
			d = xatof(s);
			
			printf("%f", d);
		}
		break;
	}
	
}