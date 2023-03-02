#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles.
 * @grid: int
 * 
 * 
 * Return: void fun
*/

void print_grid(int grid[3][3]) {
    printf("Sandpile:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }
}

/**
 * topple - function
 * @grid: int
 * @x: int
 * @y: int
 *
 * Return: void fun
*/

void topple(int grid[3][3], int x, int y) {
    grid[x][y] -= 4;
    if (x > 0) grid[x-1][y]++;
    if (x < 2) grid[x+1][y]++;
    if (y > 0) grid[x][y-1]++;
    if (y < 2) grid[x][y+1]++;
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int tmp_grid[3][3];
    int stable = 0;
    while (!stable) {
        stable = 1;
        // add the two grids
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp_grid[i][j] = grid1[i][j] + grid2[i][j];
                if (tmp_grid[i][j] > 3) {
                    stable = 0;
                }
            }
        }
        if (!stable) {
            print_grid(grid1);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (tmp_grid[i][j] > 3) {
                        topple(tmp_grid, i, j);
                    }
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    grid1[i][j] = tmp_grid[i][j];
                }
            }
        }
    }
    print_grid(grid1);
}
