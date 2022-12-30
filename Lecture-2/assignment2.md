Problem 2.1
Determine the size,minimum and maximum value following data types. Please specify if your
machine is 32 bit or 64 bits in the answer.
• char
• unsigned char
• short
• int
• unsigned int
• unsigned long
• float
Hint: Use sizeof() operator,limits.h and float.h header files

ans:
'''
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

int main(){

	printf("The size of char is %d, minimum is %d, maximum is %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("The size of unsigned char is %d, minimum is %d, maximum is %u\n", sizeof(unsigned char), 0, UCHAR_MAX);
	printf("The size of short is %d, minimum is %d, maximum is %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
	printf("The size of int is %d, minimum is %d, maximum is %d\n", sizeof(int), INT_MIN, INT_MAX);
	printf("The size of unsigned int is %d, minimum is %d, maximum is %u\n", sizeof(unsigned int), 0, UINT_MAX);
	printf("The size of unsigned long is %d, minimum is %d, maximum is %u\n", sizeof(unsigned long), 0, ULONG_MAX);
	printf("The size of float is %d, minimum is %f, maximum is %f\n", sizeof(float), FLT_MIN, FLT_MAX);
'''

Problem 2.2
Write logical expressions that tests whether a given character variable c is
• lower case letter
• upper case letter
• digit
• white space (includes space,tab,new line)

ans:
'''
#include <stdio.h>

int main(){

	char c;
	printf("Please input a character:\n");
	scanf("%c", &c);
	if (c>='a'&&c<='z')
	{
		printf("lower case letter!\n");
	}
	else if (c>='A'&&c<='Z')
	{
		printf("upper case letter!\n");
	}
	else if (c>='0'&&c<='9')
	{
		printf("digit!\n");
	}
	else
	{
		printf("white space!\n");
	}
	
	return 0;
}

'''




Problem 2.3
Consider int val=0xCAFE; Write expressions using bitwise operators that do the following:
• test if atleast three of last four bits (LSB) are on
• reverse the byte order (i.e., produce val=0xFECA)
• rotate fourbits (i.e., produce val=0xECAF)
1. (val&0XF)|(val&0X7)|(val&0XB)|(val&0XD)|(val&0XE)
2. (val&0XFF<<8)|(val&0XFF00>>8)
3. (val&0XF<<12)|(val>>4)

Problem 2.4
Using precedence rules, evaluate the following expressions and determine the value of the variables(without running the code). Also rewrite them using parenthesis to make the order explicit.
• Assume (x=0xFF33,MASK=0xFF00).Expression: c=x & MASK ==0;
• Assume (x=10,y=2,z=2;).Expression: z=y=x++ + ++y∗2;
• Assume (x=10,y=4,z=1;).Expression: y>>= x&0x2 && z
1. c = 0xFF
2. x=11, z=16, y=17
3. 

Problem 2.5
Determine if the following statements have any errors. If so, highlight them and explain why.
• int 2nd_value=10;
• Assume (x=0,y=0,alliszero=1). alliszero =(x=1) && (y=0);
• Assume (x=10,y=3,z=0;). y=++x+y;z=z−−>x;
• Assume that we want to test if last four bits of x are on. (int MASK=0xF;ison=x&MASK==MASK)

1. number can not be the first character.
2. alliszero = (x==1) && (y==0)
3. correct
4. ison = (x&MASK)==MASK
