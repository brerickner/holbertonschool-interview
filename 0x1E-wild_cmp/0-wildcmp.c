#include "holberton.h"

/**
 * wildcmp - char *s1, char *s2
 * @s1: char *s1
 * @s2: char *s2
 * Description: function that compares two strings
 * to see if they are identical. s2 can have wildcards that
 * replace any number of characters.
 * Return: 1 if identical, 0 if not.
 */
int wildcmp(char *s1, char *s2)
{
	if ((*s1 == '\0' && *s2 == '\0') || (*s1 == *s2))
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);

		return (wildcmp(s1 + 1, s2 + 1));
	}
	else if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));
	else if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (0);

		return (
			wildcmp(s1 + 1, s2 + 1)
			|| wildcmp(s1 + 1, s2)
			|| wildcmp(s1, s2 + 1));
	}
	else
		return (0);
}
