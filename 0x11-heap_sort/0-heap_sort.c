#include "sort.h"


/**
* swap - int *a, int *b
* @array: The array to be printed
* @size: size of the array
* @a: pointer to int a to be swapped
* @b: pointer to int b to be swapped
* description: Function that swapts the position of two elements
* Return: void
*/
void swap(int *array, size_t size, int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
* heapify - int *array, int left, int right
* @array: pointer to int array
* @size: size of array
* @start: start element
* @end: end element
* description: Function that finds largest of root, left child and right child
* Return: void
*/
void heapify(int *array, size_t size, int start, int end)
{
	int hi = end;
	int left = 2 * end + 1;
	int right = 2 * end + 2;

	if (left < start && array[left] > array[hi])
		hi = left;
	if (right < start && array[right] > array[hi])
		hi = right;

	/* Swap and continue to heapify if root is not largest */
	if (hi != end)
	{
		swap(array, size, &array[end], &array[hi]);
		heapify(array, size, start, hi);
	}
}

/**
* heap_sort - int *array, size_t size
* @array: The array to be printed
* @size: Number of elements in @array
* description: Function to do heap sort
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	int index;

	if (!array)
		return;

	/* Build max heap */
	for (index = size / 2; index > 0; index--)
	{
		heapify(array, size, size, index - 1);
		/*printf("in max heap");*/
	}

	/* Heap sort */
	for (index = size - 1; index > 0; index--)
	{
		swap(array, size, &array[0], &array[index]);
		/* Heapify root element to get highest element at root again*/
		heapify(array, size, index, 0);
		/* printf("in heap sort");*/
	}

}

