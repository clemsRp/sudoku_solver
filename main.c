
#include "sudoku.h"

void    ft_putnbr(int nbr)
{
    char    c;

    if (nbr > 9)
        ft_putnbr(nbr / 10);
    c = nbr % 10 + '0';
    write(1, &c, 1);
}

void    algo(char *filename)
{
    char    *res;
    char    **grid;
    int         nb_solutions;

    nb_solutions = 0;
    res = parser(filename);
    if (res == NULL)
    {
        write(1, filename, ft_strlen(filename));
        write(1, ": Erreur de lecture.\n", 22);
        return ;
    }
    grid = ft_split(res, "\n");
    if (is_valid_grid(grid) == 0)
    {
        write(1, filename, ft_strlen(filename));
        write(1, ": Grille incorrecte\n", 20);
        return ;
    }
    backtrack(grid, 0, 0, &nb_solutions);
    write(1, filename, ft_strlen(filename));
    write(1, ": Il y a ", 9);
    ft_putnbr(nb_solutions);
    write(1, " solutions possibles.\n", 22);
}

int     main(int argc, char *argv[])
{
    int     i;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            algo(argv[i]);
            if (i != argc - 1)
                write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}