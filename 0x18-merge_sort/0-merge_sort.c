
#include "sort.h"


/**
 * merge_sort(int *array, size_t size)
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Description: Sorts an array of integers in ascending order using the
 * Merge Sort algorithm.
 * Return: void
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * Stable: Yes
 * Psuedo Code: https://en.wikipedia.org/wiki/Merge_sort
 * Psuedo Code: https://www.geeksforgeeks.org/merge-sort/
 * Psuedo Code: https://www.geeksforgeeks.org/merge-sort-for-linked-list/
 */

void merge_sort(int *array, size_t size)
{
	int *buffArray = malloc(sizeof(int) * size + 1);
	size_t i, j;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
		buffArray[i] = array[i];
	for (i = 1; i < size; i *= 2)
	{
		for (j = 0; j < size - i; j += i * 2)
		{
			if (i == 1)
				merge(array, buffArray, j, j + i - 1, j + i * 2 - 1);
			else
				merge(array, buffArray, j, j + i - 1, j + i * 2 - 1);
		}
	}
	free(buffArray);
}

/**
 * merge(int *array, int *buffArray, size_t start, size_t mid, size_t end)
 * @array: The array to be sorted
 * @buffArray: The array to be sorted
 * @start: The start index of the array to be sorted
 * @mid: The mid index of the array to be sorted
 * @end: The end index of the array to be sorted
 * Description: Merges two sorted arrays into one sorted array.
 * Return: void
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Psuedo Code: https://en.wikipedia.org/wiki/Merge_sort
 */

void merge(int *array, int *buffArray, size_t start, size_t mid, size_t end)
{
	size_t i, j, k;

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
			buffArray[k++] = array[i++];
		else
			buffArray[k++] = array[j++];
	}
	while (i <= mid)
		buffArray[k++] = array[i++];
	while (j <= end)
		buffArray[k++] = array[j++];
	for (i = start; i <= end; i++)
		array[i] = buffArray[i];
}
