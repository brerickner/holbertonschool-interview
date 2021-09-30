#include "slide_line.h"


/**
* slide_line - int *line, size_t size, int direction
* @line: the line
* @size: the size
* @direction: Left or right
* description: function that slides and merges an array of integers
* Return: 1 upon success. Else 0
*/

static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("BUFF ARRAY: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

int slide_line(int *line, size_t size, int direction)
{
	int index, jIndex = 0, zeros = 0, dups = 0;
	int buffArray[size - zeros];
	int current, lftNeighb, rtNeighb;

	if (!line)
	{
		return (0);
	}
	if (direction != 0 && direction != 1)
	{
		return (0);
	}
	if (size < 1)
	{
		return (0);
	}

	if (direction == SLIDE_LEFT)
	{
		zeros = 0;
		jIndex = 0;
		for (index = 0; index < (int)size - 1; index++)
		{
			current = line[index];
			lftNeighb = line[index + 1];
			jIndex = 0;
			while ((zeros + jIndex) < (int)size)
			{	
				if (current == 0)
				{
					zeros++;
					continue;
				}
				else if (current != 0 && current == lftNeighb)
				{
					zeros++;
					buffArray[jIndex] = current + lftNeighb;
					print_array(buffArray, size);
					jIndex++;
					continue;
				}
			}
		}
		
	}
	if (direction == SLIDE_RIGHT)
	{
		zeros = 0;
		jIndex = 0;
		for (index = size - 1; index > -1; index--)
		{
			current = line[index];
			rtNeighb = line[index - 1];
			while ((zeros + jIndex) < (int)size)
			{
				if (current == 0)
				{
					zeros++;
					continue;
				}
				if (current == rtNeighb)
				{
					zeros++;
					buffArray[jIndex] = current + rtNeighb;
					jIndex++;
					continue;
				}
			}
		}

		
	}
	return (1);
}


