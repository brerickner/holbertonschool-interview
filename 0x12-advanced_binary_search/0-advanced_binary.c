#include "search_algos.h"



/**
 * print_func - int *array, size_t size, int front, int back
 * @array: pointer to first element of array
 * @size: size of array
 * @front: index to front printing
 * @back: index to back printing
 * Description: prints array after each split
 * Return: void
 */
void print_func(int *array, int front, int back)
{
	printf("Searching in array: ");
	
	for (; front < back; front++)
	{
		printf("%d", array[front]);
		if(front != back - 1)
			printf(", ");
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
	
	return(index_grabber(array, 0, (int)size, value));
	
}

/**
 * index_grabber - int *array, int front, int back, int value)
 * @array: pointer to first element of array
 * @front: index to front search
 * @back: index to stop search
 * @value: value to search for
 * Description: Searches through array for index spot that matches value
 * Return: index where value is located. Else -1
 */
int index_grabber(int *array, int front, int back, int value)
{
	/*
	 * if front is greater than back, return -1
	 * if front is equal to back, return front
	 * if front is less than back, return index
	 */
	int middle;
	
	if (back >= front)
	{
		print_func(array, front, back);
		middle = front + (back - front) / 2;

		if (front == back)
		{
			return(-1);
		}
		/* If element at middle itself*/
		if ((array[middle] == value) && (array[middle - 1] != value))
			return (middle);

		/* If element is smaller than mid, must be in left*/
		if(value <= array[middle])
		{
			return(index_grabber(array, front, middle, value));
		}
		/*Else it's in the right side*/
		if(value >= array[middle])
		{
			return(index_grabber(array, middle + 1, back, value));
		}
	}
	return(-1);
}