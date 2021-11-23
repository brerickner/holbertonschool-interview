#include "sort.h"


/**
* swap - int *a, int *b
* @a: pointer to int a to be swapped
* @b: pointer to int b to be swapped
* description: Function that swapts the position of two elements
* Return: void
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* heapify - int *array, int left, int right
* @array: pointer to int array
* @size: size of array
* @index: index of array
* description: Function that finds largest of root, left child and right child
* Return: void
*/
void heapify(int *array, int size, int index)
{
	int hi = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && array[left] > array[hi])
		hi = left;
	if (right < size && array[right] > array[hi])
		hi = right;

	/* Swap and continue to heapify if root is not largest */
	if (hi != index)
	{
		swap(&array[index], &array[hi]);
		heapify(array, size, hi);
		print_array(array, size);
		/* printf("in swap\n"); */
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

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (index = size / 2; index > 0; index--)
	{
		heapify(array, size, index - 1);
		/*printf("in max heap");*/
	}

	/* Heap sort */
	for (index = size - 1; index > 0; index--)
	{
		swap(&array[0], &array[index]);
		/* Heapify root element to get highest element at root again*/
		heapify(array, index, 0);
		print_array(array, size);
		/* printf("in heap sort");*/
	}

}

