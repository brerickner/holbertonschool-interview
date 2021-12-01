#include "search_algos.h"

/**
 * print_func - int *array, int left, int right
 * @array: pointer to first element of array
 * @left: index to left printing
 * @right: index to right printing
 * Description: prints array after each split
 * Return: void
 */
void print_func(int *array, int left, int right)
{
	printf("Searching in array: ");

	for (; left < right; left++)
	{
		printf("%d", array[left]);
		if (left != right - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary - int *array, int size, int value
 * @array: pointer to first element of array
 * @size: size of array
 * @value: value to search for
 * Description: searches for value in array using recursive binary search
 * Return: Index of value if found. Else -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index = 0;

	if (!array || size < 1)
		return (index - 1);

	return (index_grabber(array, 0, (int)size, value));
}

/**
 * index_grabber - int *array, int left, int right, int value)
 * @array: pointer to first element of array
 * @left: index to left search
 * @right: index to stop search
 * @value: value to search for
 * Description: Searches through array for index spot that matches value
 * Return: index where value is located. Else -1
 */
int index_grabber(int *array, int left, int right, int value)
{
	/**
	 * if left is greater than right, return -1
	 * if left is equal to right, return left
	 * if left is less than right, return index
	 */
	int middle;

	if (right > left)
	{
		print_func(array, left, right);
		middle = left + (right - left) / 2;

		/* If element at middle itself*/
		if ((array[middle] == value) && (array[middle - 1] != value))
		{
			print_func(array, middle, right);
			return (middle);
		}

		/* If element is smaller than mid, must be in left*/
		if (value <= array[middle])
		{
			return (index_grabber(array, left, middle, value));
		}
		/*Else it's in the right side*/
		if (value >= array[middle])
		{
			return (index_grabber(array, middle + 1, right, value));
		}
	}
	return (-1);
}
