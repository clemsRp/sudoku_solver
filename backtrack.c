
#include "sudoku.h"

void    print_grid(char **grid)
{
    int     y;
    int     x;

    y = 0;
    while (grid[y])
    {
        x = 0;
        while (grid[y][x])
        {
            write(1, &grid[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
    write(1, "\n", 1);
}

void    backtrack(char **grid, int x, int y, int *res)
{
    int     i;

    if (y == 9)
    {
        print_grid(grid);
        (*res)++;
    }
    else if (x == 9)
        backtrack(grid, 0, y + 1, res);
    else if (grid[y][x] != '.')
        backtrack(grid, x + 1, y, res);
    else
    {
        i = 1;
        while (i < 10)
        {
            grid[y][x] = i + 48;
            if (has_solution(grid) == 1)
                backtrack(grid, x + 1, y, res);
            grid[y][x] = '.';
            i++;
        }
    }
}