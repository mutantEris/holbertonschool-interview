#include "sandpiles.h"

/**
 * print_grid - prints grid
 * @grid: a 3x3 grid
 */

static void print_grid(int grid[3][3])
{
	int g, x;

	printf("=\n");

	for (g = 0; g < 3; g++)
	{
		for (x = 0; x < 3; x++)
		{
			if (x)
				printf(" ");
			printf("%d", grid[g][x]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - adds some sand together
 * @grid1: sandpile
 * @grid2: sandpile
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int w, y;
	int grid[3][3];

	for (y = 0; y < 3; y++)
	{
		for (w = 0; w < 3; w++)
			grid1[y][w] += grid2[y][w];
	}
	while (!stablized(grid1))
	{
		print_grid(grid1);

		for (y = 0; y < 3; y++)
			for (w = 0; w < 3; w++)
				grid[y][w] = 0;
		for (y = 0; y < 3; y++)
		{
			for (w = 0; w < 3; w++)
			{
				if (w != 0 && grid1[y][w - 1] > 3)
					grid[y][w]++;
				if (w != 2 && grid1[y][w + 1] > 3)
					grid[y][w]++;
				if (y != 0 && grid1[y - 1][w] > 3)
					grid[y][w]++;
				if (y != 2 && grid1[y + 1][w] > 3)
					grid[y][w]++;
			}
		}
		for (y = 0; y < 3; y++)
		{
			for (w = 0; w < 3; w++)
			{
				if (grid1[y][w] > 3)
					grid1[y][w] -= 4;
				grid1[y][w] += grid[y][w];
			}
		}
	}
}

/**
 * stablized - is sand stable
 * @grid: the checked sandpile
 * Return: 1 if stable
 */

int stablized(int grid[3][3])
{
	int z, h;

	for (z = 0; z < 3; z++)
	{
		for (h = 0; h < 3; h++)
			if (grid[z][h] > 3)
				return (0);
	}
	return (1);
}
