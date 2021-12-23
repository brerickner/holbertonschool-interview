#include "holberton.h"
/**
 * main - int argc, char *argv[]
 * @argc: Number of arguments
 * @argv: Array of 2 numbers to multiple
 * Description: This program multiplies two numbers
 * Return: Zero if successful. Else exit 98
 */

int main(int argc, char *argv[])
{
	int a, b, len1, len2, result = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	else
	{
		len1 = zap_trim_getLen(argv[1]);
		len2 = zap_trim_getLen(argv[2]);

		if (len1 == 98 || len2 == 98)
		{
			return (result);
		}
		if (len1 == 0 || len2 == 0)
		{
			printf("0\n");
			exit(0);
		}
		a = atoi(argv[1]);
		b = atoi(argv[2]);

		result = a * b;

		if (result != '0')
		{
			printf("%d\n", result);
		}
		else
		{
			printf("0\n");
		}
		return (0);
	}
}
/**
 * zap_trim_getLen - char* str
 * @str: a potential number being multiplied
 * Description: Function that checks arguments for non-numeric characters
 * Return: string to multiply if all characters are numeric.
 * Else, exit(98) and print 'Error'.
 */
int zap_trim_getLen(char *str)
{
	int index, zeros, length = 0;

	for (; str[index] != '\0'; index++)
	{
		if (str[index] < '0' || str[index] > '9')
		{
			return (98);
		}
		if (index == 0 || str[index] == '0')
		{
			if (index == 0 && str[index] == '0')
			{
				zeros = 1;
			}
			zeros++;
		}
		length++;
	}
	/* printf("length: %d\n", length);*/
	/* printf("zeros: %d\n", zeros);*/
	if (zeros >= length)
	{
		return (0);
	}

	return (length);
}
