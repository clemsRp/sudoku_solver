 
#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char    **ft_split(char *str, char *charset);
char    *parser(char *filename);
int     is_valid_grid(char **grid);
int     has_solution(char **grid);
int     ft_strlen(char *str);
void    backtrack(char **grid, int x, int y, int *res);

#endif