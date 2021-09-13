#include "palindrome.h"

/**
* oneDigit - unsigned long int n
* @n: the int
* description: check if palindrome
* Return: int
*/
int oneDigit(unsigned long n)
{
	return (n < 10);
}

/**
* isPalUtil - int n, int* dupNum
* @n: the int
* @dupNum: contains address of copy of n
* description: recursive function find num is palindrome
* Return: True when palindrome. Else false
*/

int isPalUtil(int n, int *dupNum)
{
	if (oneDigit(n))
		return (n == (*dupNum) % 10);

	if (!isPalUtil(n / 10, dupNum))
		return (0);

	*dupNum /= 10;

	return (n % 10 == (*dupNum) % 10);
}

/**
* is_palindrome - unsigned long n
* @n: the int to be checked
* description: function that checks whether or not a given unsigned
* integer is a palindrome.
* Return: 1 if n is a palindrome. Else 0
*/
int is_palindrome(unsigned long n)
{
	unsigned long new = n;
	int dupNum = new;

	return (isPalUtil(n, &dupNum));
}
