#include "lists.h"

/**
* is_palindrome - listint_t **head
* @head: pointer to linked list)
* description: Function that checks if a singly linked list is a palindrome
* Return: 0 if not palindrome. Else 1.
*/
/* A wrapper over isPalz() */
int is_palindrome(listint_t **head)
{
	return (isPalz(head, *head));
}

/**
* isPalz - listint_t **left, listint_t *right
* @left: left sublist
* @right: right sublist
* description: Utility function to recursively
* check sublists and compare their values
* Return: 1 if palindrome. Else 0.
*/
int isPalz(listint_t **left, listint_t *right)
{
	/* flags for palindrome test */
	int izP, izP1;
	/* stop recursion when right becomes NULL */
	if (!right)
		return (1);
	/* If sub-list is not palindrome then no need to */
	/* check for current left and right, return false */
	izP = isPalz(left, right->next);

	if (izP == 0)
		return (0);

	/* Check values at current left and right */
	izP1 = (right->n == (*left)->n);
	/* Move left to next node */
	*left = (*left)->next;

	return (izP1);
}
