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
		printf("%d, ", array[i]);
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
	int middle = 0;

	if (!array || size < 2)
		return (-1);
	
	middle = (size / 2) + 1;

	if (array[middle] <= value)
	{
		print_func(array, 0, size);
		print_func(array, 0, middle);
	}

	if(array[middle] > value)
		print_func(array, middle, size);
	
	// print_func(array, 0, size);
	return(array[0]);
}