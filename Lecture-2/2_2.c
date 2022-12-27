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
