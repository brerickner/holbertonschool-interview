#include "lists.h"

/**
 * *find_listint_loop - listint_t *head
 * @head: A pointer to the first element of a list
 * Description: Finds the loop in a linked list and address where it starts
 * Return: The address of the node where the loop starts. Else NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *paceNode = head;
	listint_t *raceNode = head;

	if (head == NULL)
		return (NULL);

	while (paceNode && raceNode && raceNode->next)
	{
		paceNode = paceNode->next;
		raceNode = raceNode->next->next;
		if (paceNode == raceNode)
			break;
	}
	if (paceNode != raceNode)
		return (NULL);

	paceNode = head;

	while (paceNode != raceNode)
	{
		paceNode = paceNode->next;
		raceNode = raceNode->next;
	}
	return (paceNode);
}
