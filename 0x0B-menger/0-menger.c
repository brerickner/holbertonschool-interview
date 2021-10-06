#include "menger.h"

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

/**
 * menger - int level
 * @level: level of the Menger Sponge to draw
 * description: function that draws a 2D Menger Sponge
 * Return: void
 */
void menger(int level)
{
	int x, y, size = pow(3, level);
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
				if (x % 3 == 1 && y % 3 == 1)
					printf("%s", " ");

				else
					{
						printf("#");
					}
			}
			printf("\n");
		}
	}
}
