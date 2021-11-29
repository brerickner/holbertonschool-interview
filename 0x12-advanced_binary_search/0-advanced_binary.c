#include "search_algos.h"



/**
 * print_func - int *array, size_t size, int start, int end
 * @array: pointer to first element of array
 * @size: size of array
 * @start: index to start printing
 * @end: index to end printing
 * Description: prints array after each split
 * Return: void
 */
void print_func(int *array, int start, int end)
{
	printf("Searching in array: ");
	
	for (int i = start; i < end; i++)
	{
		if(i == end - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	printf("\n");	
}

 /*
 * advanced_binary - int *array, size_t size, int value
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in {array}
 * @value: is the value to search for
 * Description: function that searches for a value in a sorted array
 * of integers.
 * Return: the index of the first occurrence of value in array or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index = 0;

	if (!array || size < 1)
		return (index - 1);
	
	return(index_grabber(array, index, (int)size - 1, value));
	
}

/**
 * index_grabber - int *array, int start, int end, int value)
 * @array: pointer to first element of array
 * @start: index to start search
 * @end: index to stop search
 * @value: value to search for
 * Description: Searches through array for index spot that matches value
 * Return: index where value is located. Else -1
 */
int index_grabber(int *array, int start, int end, int value)
{
	char side;
	int middle = 0;
	int index = 0;

	middle = (end / 2) + 1;
	print_func(array, 0, end);
	printf("*****************************\n");

	printf("Middle Index: [%d] is %d\n", middle, array[middle]);
	if(value > array[middle])
	{
		printf("Value: %d > Middle: %d\n", value, array[middle]);
		print = "l";
	}
	if(value <= array[middle])
	{
		printf("Value: %d <= middle: %d\n", value, array[middle]);
	}

	/* If value less than middle number, print and search left half*/
	if (array[middle] >= value)
	{
		if(array[middle] == value)
			index = middle;
		else
		{
			index = index_grabber(array, start, middle - 1, value);	
		}
	}
	
	/* If value higher than middle number, print and search right half*/
	if(array[middle] > value)
	{
		print_func(array, middle, end - 1);
		index = index_grabber(array, middle, end - 1, value);
	}
	if (index != -1)
		return (index);
	return(-1);
}