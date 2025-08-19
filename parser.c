
#include "sudoku.h"

char    *parser(char *filename)
{
    int         fd;
    int         size;
    int         i;
    char    c;
    char    *res;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    size = 0;
    while (read(fd, &c, 1))
    {
        if (c == '\n' || c == '.' || (c >= '0' && c <= '9'))
            size++;
    }
    close(fd);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    res = malloc(sizeof(char) * (size + 1));
    i = 0;
    while (read(fd, &c, 1))
    {
        if (c == '\n' || c == '.' || (c >= '0' && c <= '9'))
            res[i++] = c;
    }
    res[i] = '\0';
    close(fd);
    return (res);
}