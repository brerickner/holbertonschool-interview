#include "menger.h"

/* #define SIZE(x) (sizeof x / sizeof x[0]) */



/**
 * middleCheck - int rows, int cols
 * @rows: x index
 * @cols: y index
 * description: function that flags the middle indexes to be removed
 * Return: 1 if middle index. Else 0
 */
int middleCheck(int rows, int cols)
{
	for (; cols; rows /= 3, cols /= 3)
	{
		if (rows % 3 == 1 && cols % 3 == 1)
			return (1);
	}
	return (0);
}


/**
 * menger - int level
 * @level: level of the Menger Sponge to draw
 * description: function that draws a 2D Menger Sponge
 * Return: void
 */

void menger(int level)
{
	int x, y, size = pow(3, level), middle;
	/* printf("size: %i\n", size);*/


	if (level < 0)
		return;

	if (level == 0)
	{
		printf("%s\n", "#");
		return;
	}

	else
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size; y++)
			{
				middle = middleCheck(x, y);

				if (middle)
					printf("%s", " ");
				else
					printf("#");
			}
			printf("\n");
		}
	}
}
