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
	int end, endExpress;


	if (list == NULL)
		return (NULL);

	expressLane = list->express;
	normalLane = list;

	for (; expressLane; expressLane = expressLane->express)
	{
		printf("Value checked at index [%lu] = [%d] \n", expressLane->index, expressLane->n);
		if (expressLane->express == NULL)
		{
			endExpress = (int)expressLane->index;
			if (value > expressLane->n)
				printf("%d NOT IN EXPRESS! START AT INDEX [%u] in NORMAL\n\n\n", value, endExpress);

			/* NORMAL LANE */
			for (normalLane->index = (size_t)endExpress; normalLane; normalLane = normalLane->next)
			{
				printf("STARTING AT INDEX [%u] OF NORMAL LANE = %d\n", endExpress, normalLane->n);
				printf("%d in NORMAL LANE??: [%u] = %d\n", value, endExpress, normalLane->n);
				if (normalLane->next == NULL)
				{
					end = (int)normalLane->index;

					printf("Is %d THE LAST VALUE?!\n", value);
					
					printf("Value found between indexes [%u] and [%i]\n", endExpress, end);
					for(list->index = (size_t)endExpress; list->index >= (size_t)end; list = list->next)
					{
						printf("Value checked at index [%lu] = [%u]", list->index, list->n);
						if (list->n == value)
						{
							printf("******VALUE FOUND at [%lu]****\n", list->index);
							return (list);
						}
						else
						{
							printf("VALUE %d NOT IN LISTS!!!! NIL!\n", value);
							return (NULL);
						} 
					}
					return (NULL);
				}
			}
		}
	}
		
	return (NULL);
}
