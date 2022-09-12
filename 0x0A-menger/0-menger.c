#include "menger.h"

/**
 * menger - draws a Menger Sponge but with 2 dimensions
 * @level: menger sponge bigness level
 */

void menger(int level)
{
	int x;
	int y;
	int g;
	int h;
	int z;
	int length = pow(3, level);

	if(level < 0)
	    return;
	if(level == 0)
		printf("#\n");
	else
	{
		for(y = 0; y < length; y++)
		{
			for(x = 0; x < length; x++)
			{
				g = x;
				h = y;
				for (z = 0; z < level; z++)
				{
					if (g % 3 == 1 && h % 3 == 1)
						break;
					g /= 3;
					h /= 3;
				}
				if (z == level)
					printf("#");
				else 
					printf(" ");
			}
			printf("\n");
		}
	}
}