#ifndef RUSH_H
# define RUSH_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_rush
{
    int **res;
    int **row;
    int **col;
    int *visible;
    int *data;
}   t_rush;

typedef struct  s_idx
{
    int size;
    int *left;
    int *right;
    int *up;
    int *down;
}   t_idx;

#endif