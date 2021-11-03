#include "search.h"

/**
 * linear_skip - skiplist_t *list, int value
 * @list: Pointer to head of sorted ascending skip list
 * @value: Value to search for.
 * Description: Function that searches for a value in a sorted skip list
 * of integers. None of express lane placed every index which is a multiple
 * of the square root of the size of the list.
 * Print 'Value checked at index {} = {value}'
 *
 * Return: Pointer to first node where 'value' is located, or NULL if value
 * not present in list or head is NULL.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *normalLane, *expressLane = NULL;
	// int normalI = 0, expressI = 0;


	if (list == NULL)
		return (NULL);

	expressLane = list->express;
	normalLane = list;

	for (; expressLane; expressLane = expressLane->express)
	{
		printf("%d in EXPRESS LANE??: [%lu] = %d\n",value, expressLane->index, expressLane->n);
		if (expressLane->express == NULL && value > expressLane->n)
		{
			printf("%d NOT IN EXPRESS LANE! GO TO NORMAL LANE\n", value);
		}
	}


	for (; normalLane; normalLane = normalLane->next)
	{
		printf("%d in NORMAL LANE??: [%lu] = %d\n",value, normalLane->index, normalLane->n);
	}
		
	return (NULL);
}
