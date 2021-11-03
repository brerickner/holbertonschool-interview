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
	int start, end;


	if (list == NULL)
		return (NULL);

	expressLane = list->express;
	normalLane = list;

	for (; expressLane; expressLane = expressLane->express)
	{
		printf("%d in EXPRESS LANE??: [%lu] = %d\n",value, expressLane->index, expressLane->n);
		if (expressLane->express == NULL)
		{
			if (value > expressLane->n)
				printf("%d NOT IN EXPRESS! START AT INDEX [%lu] in NORMAL\n", value, expressLane->index);

			/* NORMAL LANE */
			for (; normalLane; normalLane = normalLane->next)
			{
				start = (int)expressLane->index;
				printf("%d in NORMAL LANE??: [%u] = %d\n", value, start, normalLane->n);

				printf("STARTING AT INDEX [%u] OF NORMAL LANE = %d\n", start, normalLane->n);
				if (normalLane->next == NULL)
				{
					end = (int)normalLane->index;

					printf("Is %d THE LAST VALUE?!\n", value);
					
					printf("Value found between indexes [%u] and [%i]\n", start, end);
					return (NULL);
				}
			}
		}
	}
		
	return (NULL);
}
