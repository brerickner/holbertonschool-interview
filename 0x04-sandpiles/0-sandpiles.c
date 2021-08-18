
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
	int x, y, sumGrid[3][3];
	int i, j;
	/*Get the sums of two grids and put in new grid*/
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			sumGrid[x][y] = grid1[x][y] + grid2[x][y];

	/*printing the sum grid*/
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", sumGrid[i][j]);
		}
		printf("\n");
	}
}
