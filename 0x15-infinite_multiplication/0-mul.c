#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int zap_trim_getLen(char *str);
/**
 * main - int argc, char *argv[]
 * @argc: Number of arguments
 * @argv: Array of 2 numbers to multiple
 * Description: This program multiplies two numbers
 * Return: Zero if successful. Else exit 98
 */

int main(int argc, char *argv[])
{
	int len1 = 0;
	int len2 = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	else
	{
		len1 = zap_trim_getLen(argv[1]);
		len2 = zap_trim_getLen(argv[2]);


		if (len1 == 0 || len2 == 0)
		{
			printf("0\n");
			return (0);
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
		/*printf("str[index]: %c\n", str[index]);*/
		if (str[index] < 48 || str[index] > 57)
		{
			printf("Error meow\n");
			exit(98);
		}
		if (str[index] == 48)
			zeros++;
		length++;
	}
	/*printf("length: %d\n", length);*/
	/*printf("zeros: %d\n", zeros);*/

	if (length <= zeros)
	{
		return (0);
	}

	return (length);

}
