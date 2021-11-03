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
	size_t lastValue;

	if (list == NULL)
		return (NULL);

	expressLane = list->express;
	normalLane = list;

	for (; expressLane; expressLane = expressLane->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			expressLane->index, expressLane->n);

		if (expressLane->express == NULL || expressLane->n >= value)
		{
			if (expressLane->express == NULL)
			{
				lastValue = expressLane->index;
				if (expressLane->n < value)
				{
					for (normalLane = expressLane; expressLane->next;
					     expressLane = expressLane->next)
						;
				}
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				lastValue, expressLane->index);

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
