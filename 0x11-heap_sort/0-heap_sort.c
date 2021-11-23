#include "sort.h"

/**
* heap_sort - int *array, size_t size
* @array: The array to be printed
* @size: Number of elements in @array
* description: Function that sorts an array of ints in ascending order
* using the sift-down heap sort algorithm printing array after each swap.
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	int i, t = 0;
	
	for (i = (size - 2) / 2; i >= 0; i--) 
	{
		downheap(array, size, i);
	}
	for (i = 0; i < (int)size; i++)
	{
        	t = array[size - i - 1];
		array[size - i - 1] = array[0];
		array[0] = t;
		downheap(array, size - i - 1, 0);
		print_array(array, size - i);
	}
}

void downheap(int *array, size_t size, int i)
{
	while (1)
	{
		int j = max_heapify(array, size, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
			break;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
		i = j;
	}
}

int max_heapify(int *array, int size, int i, int j, int k)
{
	int m = i;
	if (j<size && array[j] > array[m])
		m = j;
	if (k<size && array[k] > array[m])
		m = k;
	return m;
}
