#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 */
void menger(int level)
{
    int size = (int)pow(3, level);
    int row, col;

    if (level < 0)
        return;

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            int x = col;
            int y = row;
            char symbol = '#';

            while (x > 0 || y > 0)
            {
                if (x % 3 == 1 && y % 3 == 1)
                {
                    symbol = ' ';
                    break;
                }
                x /= 3;
                y /= 3;
            }

            printf("%c", symbol);
        }
        printf("\n");
    }
}
