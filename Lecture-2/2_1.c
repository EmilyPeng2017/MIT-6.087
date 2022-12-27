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
}
