#include "holberton.h"

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	else
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		int c = a * b;
		printf("%d\n", c);
	}
	// int a,b,result;
	// a = strlen("87879");
	// b = strlen("406749840980484980487487987");
	// result = strlen("1654454331376");
	// printf("a: %d\n",a);
	// printf("b: %d\n",b);
	// printf("result: %d\n",result);
	// printf ("Error");
}