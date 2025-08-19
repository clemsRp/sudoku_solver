
#include "sudoku.h"

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     is_correct(char **grid, int i, int j)
{
    int     x;
    int     y;

    y = 0;
    while (grid[y])
    {
        if (grid[y][j] == grid[i][j] && y != i && grid[y][x] != '.')
            return (0);
        if (y == i)
        {
            x = 0;
            while (grid[y][x])
            {
                if (grid[y][x] == grid[i][j] && x != j && grid[y][x] != '.')
                    return (0);
                x++;
            }
        }
        y++;
    }
    y = i - i % 3;
    while (y < (i - i % 3 + 3))
    {
        x = j - j % 3;
        while (x < (j - j % 3 + 3))
        {
            if (grid[y][x] == grid[i][j] && x != j && y != i && grid[y][x] != '.')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int     has_solution(char **grid)
{
    int     i;
    int     j;

    i = 0;
    while (grid[i])
    {
        j = 0;
        while (grid[i][j])
        {
            if (is_correct(grid, i, j) == 0 && grid[i][j] != '.')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int     is_valid_charset(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
            return (0);
        i++;
    }
    return (1);
}

int     is_valid_grid(char **grid)
{
    int     i;
    int     len;

    i = 0;
    len = ft_strlen(grid[0]);
    while (grid[i])
    {
        if (ft_strlen(grid[i]) != len || is_valid_charset(grid[i]) == 0)
            return (0);
        i++;
    }
    if (len != i || has_solution(grid) == 0)
        return (0);
    return (1);
}