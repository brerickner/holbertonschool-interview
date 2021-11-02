#include "search.h"

skiplist_t *check(skiplist_t *skippy, skiplist_t *buffList, int value)
{
	skiplist_t *skippyExpress = skippy->express;
	int skippyN = skippy->n;

	if(skippyExpress == NULL || skippyN >= value)
	{
		if(skippyExpress == NULL && skippyN < value)
		{
			buffList = skippy;
			while (skippy->next)
				skippy = skippy->next;
		}

		printf("Value found between indexes [%lu] and [%lu]\n", buffList->index, skippy->index);

		for (; buffList; buffList = buffList->next)
		{
			printf("Value checked at [%lu] = [%d]\n", buffList->index, buffList->n);
			if (buffList->n == value)
				return (buffList);
		}
	}
	return (NULL);
 }
/**
 * struct skiplist_s - skiplist_t *list, int value
 * @list: Pointer to head of sorted ascending skip list
 * @value: Value to search for.
 * Description: Function that searches for a value in a sorted skip list 
 * of integers. None of express lane placed every index which is a multiple
 * of the square root of the size of the list. 
 * Print 'Value checked at index {} = {value}'
 * Return: Pointer to first node where 'value' is located, or NULL if value
 * not present in list or head is NULL.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skippy = NULL;
	skiplist_t *buffList = NULL;
	
	if (list == NULL)
		return (NULL);
	
	skippy = list->express;
	buffList = list;

	for (; skippy; buffList = skippy, skippy = skippy->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", skippy->index, skippy->n);
		buffList = check(skippy, buffList, value);
	}
	return(buffList);
}
	
		


	
