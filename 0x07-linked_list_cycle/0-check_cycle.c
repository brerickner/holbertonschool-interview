#include "lists.h"
/**
 * check_cycle - listint_t *list
 * @list: linked list of ints
 * description: check to see if singly linked list has a cycle
 * Return: 0 if no cycle. Else 1.
 */
int check_cycle(listint_t *list)
{
	/* both start @ head node in *list */

	listint_t *paceNode = list;
	listint_t *raceNode = list;
	/* check if raceNode is tail node or raceNode->next is tail node/NULL*/

	while (raceNode && raceNode->next)
	{
	/* paceNode increase slowly, by 1*/
	/* while raceNode by 2 in attempt to catch up */
		paceNode = paceNode->next;
		raceNode = raceNode->next->next;
		if (raceNode == paceNode)
			return (1);
	}
	return (0);
}
