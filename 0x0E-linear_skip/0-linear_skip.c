#include "search.h"

/**
 * linear_skip - skiplist_t *list, int value
 * @list: Pointer to head of sorted ascending skip list
 * @value: Value to search for.
 * Description: Function that searches for a value in a sorted
 * ascending skip list of ints using an express lane.
 *
 * Return: Pointer to first node where 'value' is located, or NULL if value
 * not present in list or if head is NULL.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *normalLane, *expressLane = NULL;

	/* WHEN NO LIST*/
	if (list == NULL)
		return (NULL);

	/* Compare values in express lane to determine if value is present in*/
	/*express Lane values*/
	for (expressLane = list->express, normalLane = list; expressLane;
	     normalLane = expressLane, expressLane = expressLane->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			expressLane->index, expressLane->n);

		if (expressLane->express == NULL || expressLane->n >= value)
		{
			/* Reaches end of express nodes without finding value */
			if (expressLane->express == NULL && expressLane->n < value)
			{
				/* Calculate for in between indexes */
				for (normalLane = expressLane; expressLane->next;
					expressLane = expressLane->next)
					;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				normalLane->index, expressLane->index);

			/* Iterate through normal lane checking for value */
			for (; normalLane; normalLane = normalLane->next)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					normalLane->index, normalLane->n);
				if (normalLane->n == value)
					return (normalLane);
			}
		}
	}
	return (NULL);
}
