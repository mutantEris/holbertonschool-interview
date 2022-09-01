#include "slide_line.h"
#include <stdio.h>

/**
 * rightyTighty - slides line right
 * @line: the line
 * @size: line's size
 */
void rightyTighty(int *line, int size)
{
	int box;
	int end = 0;
    int empy = -1;
    int g;

	//pushes empties left
	for (box = size - 1; box >= 0; box--)
	{
		if (line[box] == 0)
		{
			if (empy == -1)
				empy = box;
			end = empy;
			while (line[box] == 0 && box >= 0)
				box--;
			if (box >= 0)
			{
				line[empy--] = line[box];
				line[box] = 0;
			}
		}
	}
	for (box = size - 1; box > end; box--)
	{
		if (line[box] == line[box - 1])
		{
			line[box] *= 2;
			for (g = box - 1; g > end; g--)
				line[g] = line[g - 1];
			line[end++] = 0;
		}
	}
}

/**
 * leftyLoosey - slides line left
 * @line: the line
 * @size: bigness of line
 */
void leftyLoosey(int *line, int size)
{
	int box;
	int end = size - 1;
	int empy = -1;
	int g;

	/*move 0s to the right*/
	for (box = 0; box < size; box++)
	{
		if (line[box] == 0)
		{
			if (empy == -1)
				empy = box;
			end = empy;
			while (line[box] == 0 && box < size)
				box++;
			if (box < size)
			{
				line[empy++] = line[box];
				line[box] = 0;
			}
		}
	}
	for (box = 0; box < end; box++)
	{
		if (line[box] == line[box + 1])
		{
			line[box] *= 2;
			for (g = box + 1; g < end; g++)
				line[g] = line[g + 1];
			line[end--] = 0;
		}
	}
}

/**
 * slide_line - slides the line
 * @line: the line
 * @size: line size
 * @direction: slide direction
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		leftyLoosey(line, size);
	else
		rightyTighty(line, size);
	return (1);
}