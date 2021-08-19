
#include "sandpiles.h"

/**
 * sandpiles_sum - int grid1[3][3], int grid2[3][3]
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid
 * description: function that computes the sum of two sandpiles
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y, stable = 0;
	/*Get the sums of two grids and put in new grid*/
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
			if (grid1[x][y] < 4)
				stable++;
		}
	}
	while (stable < 9)
	{
		printf("=\n");
		print_grid(grid1);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (grid1[x][y] < 4)
				{
					stable++;
				}

				if (grid1[x][y] > 3)
				{
					stable = 0;
					grid1[x][y] -= 4;
					if (x > -1)
						grid1[x - 1][y]++;
					if (x < 2)
						grid1[x + 1][y]++;
					if (y > -1)
						grid1[x][y - 1]++;
					if (y < 2)
						grid1[x][y + 1]++;
				}
			}
		}
	}
}


/**
 * print_grid - int grid[3][3]
 * @grid: grid to print
 * description: print grid
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
