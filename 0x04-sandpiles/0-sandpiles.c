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
	int x, y, unstable = 1, sumGrid[3][3];

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];

	unstable = stability_alert(grid1);

	while (unstable)
	{
		unstable = stability_alert(grid1);
		if (unstable == 0)
			return;
		printf("=\n");
		print_grid(grid1);
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				sumGrid[x][y] = grid1[x][y];
				if (sumGrid[x][y] > 3)
				{
					grid1[x][y] -= 4;
					if (x - 1 > -1)
						grid1[x - 1][y]++;
					if (x + 1 < 3)
						grid1[x + 1][y]++;
					if (y - 1 > -1)
						grid1[x][y - 1]++;
					if (y + 1 < 3)
						grid1[x][y + 1]++;
				}
			}
		}
	}
}
/**
 * stability_alert - int grid1[3][3]
 * @grid: grid to check stability of
 * description: function that checks stability of grid
 * Return: 1 if unstable, 0 if stable
 */
int stability_alert(int grid[3][3])
{
	int x, y, alert = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] < 4)
				alert++;
	if (alert == 9)
		return (0);
	return (1);
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

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
