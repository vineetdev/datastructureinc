#include<stdio.h>
#include<string.h>
#include<malloc.h>


struct mystruct
{
> int a;
> int b;
};
struct mystruct t;
//Array, string and pointer

/**Find out the string length of a string**/
int xstrlen(char **s)
{
> char**p;

> for(p = s; **s != '\0'; s++);**

> return s-p;
}

/**string copy**/
void xstrcpy(char **source, char**dest)
{
> for(;(**dest++ =**source++) !='\0';);

  * est = '\0';
}
/**string concatenation**/
void xstrcat(char **s1, char**s2)
{
> for(; **s1 != '\0';s1++);**

> for(; (**s1=**s2) != '\0'; s2++,s1++);

  * 1 = '\0';
}
/**String comparision**/
int xstrcmp(char **s, char**t)
{
> for(;**s ==**t && **s != '\0';s++,t++);**

> if(**t == '\0' &&**s == '\0')
> > return 0;

> else
> > return s-t;
}
/**String reverse**/
void xstrev(char **s)
{

> int i,j, len;**

> len = xstrlen(s);
> for(i = 0, j = len -1; i<j; i++,j--)
> {
> > s[len](len.md) = s[i](i.md);
> > s[i](i.md) = s[j](j.md);
> > s[j](j.md) = s[len](len.md);

> }
> s[len](len.md) ='\0';
}
/**strchr**/
char **xstrchr(char**s, int c)
{
> while(**s)
> {
> > if(**s == (char)c)
> > > return s;

> > s++;

> }
> return 0;
}

/**Memmove implementation**/
void **xmemmove(void**dest, void **src, int size)
{
> char**pd = dest;
> char **ps = src;**

> while(size--)
    * d++ = **ps++;**

> return dest;
}
/**strstr implementation**/
char **xstrstr(char**s, char **t)
{
> int i,j,k;**

> for(i = 0; s[i](i.md) != '\0';i++)
> {
> > for(j = i, k = 0; t[k](k.md) != '\0' && s[j](j.md) == t[k](k.md);j++,k++);


> if(t[k](k.md) == '\0')
> > return s[i](i.md);

> }
> return 0;
}

/**convetrt ascii to integer**/
int xatoi(char **s)
{
> int sign,d = 0;**

> sign = (**s == '-')?-1:1;**

> if(**s == '-' ||**s == '+')
> > s++;


> while(**s >= '0' &&**s <= '9')
> {
> > d = d **10 +(**s - '0');
> > s++;

> }
> return d **sign;
}
/**convert int to ascii **/
void xitoa(char**s, int d)
{
> int i = 0,sign, n;

> sign = (d < 0)? -1:1;

> d = sign **d;**

> while(d > 0)
> {
> > n = d%10;
> > d = d/10;
> > s[i](i.md) = n + '0';
> > i++;

> }
> if(sign == -1)
> > s[i++] = '-';


> s[i](i.md) = '\0';

> xstrev(s);

}
/**Convert ascii to float**/
float xatof(char **s)
{
> int sign;
> float f;
> int d = 0, pow = 1;**

> sign = (**s == '-')?-1:1;**

> if(**s == '-' ||**s == '+')
> > s++;


> while(**s >= '0' &&**s <= '9')
> {
> > d = d **10 + (**s - '0');
> > s++;

> }
> if(**s == '.')
> {
> > s++;**


> while(**s >= '0' &&**s <= '9')
> {
> > d = d **10 + (**s - '0');
> > s++;
> > pow = pow **10;

> }
> }
> f = (float)d/pow;**

> return f;
}
/**Convert int to char base Hex, oct**/
void itob(int n, char **s, int b)
{
> int i = 0, sign = 1;
> int d;**

> if(n < 0)
> > sign = -1;


> while(n > 0)
> {
> > d = n % b;


> s[i++]= (d <= 9)? d + '0' : d +'a'-10;
> n = n/b;
> }
> if(sign < 0)
> > s[i++] = '-';


> s[i](i.md) = '\0';

> xstrev(s);
}
int is\_digit(int d)
{
> if(d >= '0' && d <= '9')
> > return 1;

> else
> > return 0;
}
int tolower(int c)
{

> if(c >= 'A' && c <= 'Z')
> > return c-'A'+'a';

> else
> > return c;
}

int toupper(int c)
{

> if(c >= 'a' && c <= 'z')
> > return c-'a'+'A';

> else
> > return c;
}
void swap(int a, int b)
{

> printf("Before swap value of a is %d and b is %d", a,b);
> a = a^b;
> b = a^b;
> a = a^b;

> printf("After swap value of a is %d and b is %d", a,b);
}
//Write a C program to reverse the words in a sentence in place.

void Reverse(char **s, int beg, int end)
{
> int c;**

> for(;beg < end; beg++, end--)
> {
> > c = s[beg](beg.md);
> > s[beg](beg.md) = s[end](end.md);
> > s[end](end.md) = c;

> }
}
void wordrev(char **s)
{
> int beg = 0, end, idx = 0;
> //1. word by word reverse.
> end = xstrlen(s);
> Reverse(s, beg, end -1);
> while(beg < end)
> {
> > for(idx = beg; s[idx](idx.md) != ' ' && s[idx](idx.md) != '\0';idx++);**


> Reverse(s, beg, idx -1);
> beg = idx + 1;
> }
> //2. usin strtok
> > //wordrev(strtok(s, " "));
> > //void wordrev(char **s)
> > //{
> > //	if(s == NULL)
> > //		return;
> > //	else
> > //	{
> > //		wordrev(strtok(NULL, " ");
> > //		printf("%s", s);
> > //	}
> > //}**


> //3. Using linklist
}
int factorial(int n)
{
> if(n == 1)
> > return 1;

> else
> > return n\*factorial(n-1);
}

//Write a C program to calculate pow(x,n)?

int pow(int x, int n)
{

> if(n == 1)
> > return x;

> else
> > return x\*pow(x,n-1);
}
//generate fibonacci numbers
int fibonacii(int n)
{

> if(n <= 2)
> > return 1;

> else
> > return (fibonacii(n-1)+fibonacii(n-2));
}
//max seq of sub array from array.
void find\_subarray(int array1[.md](.md))
{

> int first\_current\_index = 0, last\_current\_index = 0;
> int first\_prev\_index = 0, last\_prev\_index = 0;
> int i;

> for(i = 0; i < 9; i++)
> {
> > if(array1[i](i.md) > array1[i+1])
> > {
> > > last\_current\_index = i;


> if((last\_current\_index - first\_current\_index) > (last\_prev\_index - first\_prev\_index))
> {
> > first\_prev\_index = first\_current\_index;
> > last\_prev\_index = last\_current\_index;

> }
> first\_current\_index = i + 1;
> }
> }
> printf("Max sub array found at begin seq is %d and end seq is %d", first\_prev\_index, last\_prev\_index);
}
//max sum of sub array from array.
void find\_max\_sum\_subarray(int array1[.md](.md))
{
> int prev\_max = 0, current\_max = array1[0](0.md);
> int i;

> for(i = 0; i < 10; i++)
> {
> > if(array1[i](i.md) > array1[i+1])
> > {
> > > current\_max += array1[i+1];

> > }
> > else
> > {
> > > if(prev\_max < current\_max)
> > > > prev\_max = current\_max;

> > > current\_max = array1[i+1];

> > }

> }
> printf("max sum of sub array is %d",prev\_max);
}
//Write C code to return a string from a function
/**Solution 1 : use malloc**/
/**solution 2 : use static decarion**/

//Write a C progam to convert from decimal to any base (binary, hex, oct)
void decimal\_anybase(int n, int base)
{
> int i = 0, d;
> char digits[100](100.md) = {0};

> while(n> 0)
> {
> > d = n % base;
> > digits[i++] = (d <=9)?(d + '0'):(d + 'a'-10);
> > n = n/10;

> }
> for(;i>=0;i--)
> > printf("%c",digits[i](i.md));
}
//Write C code to check if an integer is a power of 2 or not in a single line?
void powerof\_two(int n)
{

> if(((~n + 1) & n) == n)
> > printf("Number is power of 2");

> else
> > printf("Number is not power of 2");
}
//Write code to find duplicates in a array. eg. 1,2,3,3,4,3,5,6,5 (Given an array of n integers from 1 to n with one integer repeated..)

void find\_duplicates(int **array1, int size)
{

> int i, d;
> int array2[100](100.md) = {0};**

> for(i = 0; i < size; i++)
> {
> > d = array1[i](i.md) % size;


> if(array2[d](d.md) != 0)
> > printf("Number %d is duplicate\n",d);

> else
> > array2[d](d.md) = d;

> }
}
//Write C code to dynamically allocate one, two and three dimensional arrays (using malloc()
void allocate\_memory()
{
> int rows =2, column = 3, depth = 3;
> int i, j;
> int **p; //one dimensional
> int****q; //2 dimensional
> int**r; //3 dimensional

> //one dimensional
> p = (int **) malloc(10);**

> //2 Dimensional
> q = (int )malloc(rows **sizeof(int));
> for(i = 0; i < rows; i++)
> {
> > q[i](i.md) = malloc(column** sizeof(int));

> }

> //3 dimensional
> r = (int **)malloc(rows** sizeof(int));
> for(i = 0; i < column; i++)
> {
> > r[i](i.md) = (int )malloc(column **sizeof(int));
> > for(j = 0; j < depth; j++)
> > {
> > > r[i](i.md)[j](j.md) = (int**)malloc(depth **sizeof(int));

> > }

> }
}
//How would you find the size of structure without using sizeof()?
void xsizeof()
{
> struct mystruct**p = &t;
> int size;

> size = ((char**)(p+1)) - (char**)p;
}
//Write a C program to check for palindromes.
int is\_palindrome(char **s)
{
> int len, flag = 1;
> int i, j;**

> len = strlen(s);

> for(i = 0, j = len -1; i < j; i++, j--)
> {
> > if(s[i](i.md) != s[j](j.md))
> > {
> > > flag = 0;
> > > break;

> > }

> }

> if(flag == 1)
> > printf("string %s is palindrome", s);


> else
> > printf("Not a palindrome");

> return flag;
}

void main()
{
> int operation;

> printf(" 1: String length\n 2: String copy\n 3: Concatenate string\n 4:  String comparision\n");
> printf(" 5: String reverse\n 6: Strchr Implementation\n 7: Memmove implementation\n 8:  strstr implementation\n");
> printf(" 9: convetrt ascii to integer\n 10: convert int to ascii\n 11: Convert ascii to float\n");
> printf(" 12: Convert int to char base Hex, oct\n 13: is\_digit\n 14: tolower\n 15: toupper\n 16: swap 2 numbers\n");
> printf(" 17: reverse the words in a sentence in place\n 18: factorial\n 19: pow\n 20: Generate the fibonacii \n");
> printf(" 21: find\_subarray from array\n 22: find\_max\_sum\_subarray from array\n 23: convert from decimal to any base\n");
> printf(" 24: integer is a power of 2 or not in a single line\n 25: find duplicates in a array.\n 26: dynamically allocate one, two and three dimensional arrays\n");
> printf(" 27: size of structure without using sizeof()\n 28: check for palindromes\n 29: strtok implementation\n");

> printf(" String Operations: Please enter your choice\n");

> scanf("%d",&operation);

> switch(operation)
> {
> > case 1:
> > {
> > > int len;
> > > char s[20](20.md) = {0};


> xstrcpy("Hello Vapes", s);
> len = xstrlen(s);

> printf("string length is %d", len);
> }
> break;
> case 2:
> {
> > char src[20](20.md) = "Hello Vapes";
> > char dst[20](20.md) = {0};


> xstrcpy(src, dst);
> printf("string copy of dest is %s", dst);
> }
> break;
> case 3:
> {
> > char src[20](20.md) = "Hello ";
> > char dst[10](10.md) = "Vapes";


> xstrcat(src, dst);
> printf("After string concatenate string is %s", src);
> }
> break;
> case 4:
> {
> > char src[20](20.md) = "Hello ";
> > char dst[10](10.md) = "Hello";


> if(0 == xstrcmp(src, dst))
> > printf("String comparision success \n");

> else
> > printf("String comparision Failed \n");

> }
> break;
> case 5:
> {
> > char src[20](20.md) = "Hello ";


> xstrev(src);
> printf("String reverse is %s \n",src);
> }
> break;
> case 6:
> {
> > char **temp;
> > char src[20](20.md) = "Hello Vapes";**


> temp = xstrchr(src, ' ');
> printf("String char is %s \n",temp);
> }
> break;
> case 7:
> {
> > char s1[20](20.md) = "Hello Vapes";
> > char s2[10](10.md) = {0};


> xmemmove(s2, s1, 5);

> printf("After memmove string is %s", s2);
> }
> break;
> case 8:
> {
> > char s1[20](20.md) = "Hello Vapes";
> > char s2[10](10.md) = "Vapes";


> if(xstrstr(s1,s2))
> > printf("Substring found");

> else
> > printf("Substring not found");

> }
> break;
> case 9:
> {
> > int d;
> > char s[10](10.md) = "-1234";


> d = xatoi(s);

> printf("%d", d);
> }
> break;
> case 10:
> {
> > int d = 1234;
> > char buffer[10](10.md) = {0};


> xitoa(buffer, d);

> printf("%s", buffer);
> }
> break;
> case 11:
> {
> > float d;
> > char s[20](20.md) = "12345.12";


> d = xatof(s);

> printf("%f", d);
> }
> break;
> case 12:
> {
> > int n = 1655;
> > char s[100](100.md) = {0};
> > itob(n, s, 16);


> printf("after conversion value is %s", s);
> }
> break;
> case 13:
> {
> > int d;
> > d = is\_digit('a');


> if(d == 1)
> > printf("Number is digit");

> else
> > printf("Not a digit");

> }
> break;
> case 14:
> > tolower('A');
> > break;

> case 15:
> > toupper('a');
> > break;

> case 16:
> > swap(10,5);
> > break;

> case 17:
> {
> > char s[15](15.md) = {0};


> xstrcpy("I am a boy", s);
> wordrev(s);
> printf("%s",s);
> }
> break;
> case 18:
> > printf("factorial is %d", factorial(5));
> > break;

> case 19:
> > printf("power is %d", pow(2, 3));
> > break;

> case 20:
> {
> > int i;


> for(i = 1; i<10;i++)
> {
> > printf("%d", fibonacii(i));

> }
> }
> break;
> case 21:
> {
> > int arr1[.md](.md) = {1, 2, 3, 0, 7, 8, 9, 10, 5, 6};
> > find\_subarray(arr1);

> }
> break;
> case 22:
> {
> > int array1[.md](.md) = {1, 2, 3, -1, 7,8,9,10, 5,6};
> > find\_max\_sum\_subarray(array1);

> }
> break;
> case 23:
> > decimal\_anybase(1625, 8);
> > break;

> case 24:
> > powerof\_two(9);
> > break;

> case 25:
> {
> > int array1[.md](.md) = {1,2,3,3,4,3,5,6,5,5};
> > find\_duplicates(array1, 10);

> }
> break;
> case 26:
> > allocate\_memory();
> > break;

> case 27:
> > xsizeof();
> > break;

> case 28:
> > is\_palindrome("malayalam");


> break;
> case 29:

> case 30:
> > break;

> }
}