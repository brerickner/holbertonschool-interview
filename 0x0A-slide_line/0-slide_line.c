#include "slide_line.h"

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
	size_t i;

	if (!line)
	{
		return (0);
	}
	/* If L */
	if (direction == 0 || direction == 1)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i + 1] && line[i + 1] == line[i])
			{
				line[i] = line[i] + line[i + 1];
				if (line[i + 2])
				{
					line[i + 1] = line[i + 2];
				}

				else if (line[i + 1] && line[i + 1] == line[i])
				{
					line[i + 1] = slide_line(line, size, direction);

					line[i + 1] = 0;
				}
			}
		}
		return (1);
	}

	else
	{
		return (0);
	}
}


