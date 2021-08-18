
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
	int x, y;
	int sumPile[3][3];
	/*int i, j, sumGrid[3][3];*/

	/*Get the sums of two grids and put in new grid*/
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			sumPile[x][y] = grid1[x][y] + grid2[x][y];
		}
	}
	printf("=\n");
	print_grid(sumPile);
	printf("***DEBUG nextpile and grid1 should be equal**\n");
}
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