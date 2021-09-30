#include "slide_line.h"

/**
* swapski - int *line, int zero, int direction
* @line: the line
* @zero: the index location of zero to swap
* @direction: Left or right
* description: function that swaps zeros in desired direction
* Return: void
*/
void swapski(int *line, int zero, int direction)
{
	int hold = line[zero];

	line[zero] = line[zero + direction];
	line[zero + direction] = hold;
}

/**
* makin_moves - int *line, int size, int direction
* @line: the line
* @size: the size
* @direction: Left or right
* description: does swaps in appropriate direction
* Return: void
*/
void makin_moves(int *line, int size, int direction)
{
	int i, j;

	switch (direction)
	{
		case SLIDE_LEFT:
			for (i = 0, j = 0; i < size; i++)
			{
				for (j = 0; j < size - i - direction; j++)
				{
					if (line[j] == 0)
						swapski(line, j, direction);
				}
			}
			break;

		case SLIDE_RIGHT:
			for (i = size + direction; i > 0; i--)
			{
				for (j = size + direction; j > 0; j--)
				{
					if (line[j] == 0)
					{
						swapski(line, j, direction);
					}
				}
			}
			break;
	}
}

/**
* squish - int *line, int size, int direction
* @line: the line
* @size: the size
* @direction: Left or right
* description: squishes duplicates together and replaces old value with zero
* Return: void
*/
void squish(int *line, int size, int direction)
{
	int i;

	switch (direction)
	{
		case SLIDE_LEFT:
			i = 0;
			for (; i < size - direction; i++)
			{
				if (line[i] == line[i + direction])
				{
					line[i] += line[i + direction];
					line[i + direction] = 0;
				}
			}
			break;

		case SLIDE_RIGHT:
			i = size + direction;
			for (; i > 0; i--)
			{
				if (line[i] == line[i + direction])
				{
					line[i] += line[i + direction];
					line[i + direction] = 0;
				}
			}
			break;
	}
	makin_moves(line, size, direction);
}

/**
* slide_line - int *line, size_t size, int direction
* @line: the line
* @size: the size
* @direction: Left or right
* description: function that slides and merges an array of integers
* Return: 1 upon success. Else 0
*/


int slide_line(int *line, size_t size, int direction)
{
	if (!line || ((direction != 1) && (direction != -1)) || (int)size < 1)
	{
		return (0);
	}
	makin_moves(line, size, direction);
	squish(line, size, direction);

	return (1);
}
