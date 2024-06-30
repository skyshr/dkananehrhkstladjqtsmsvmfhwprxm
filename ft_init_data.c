#include "rush.h"

void    ft_init_data(t_rush *rush_data, int size, char *str)
{
    int n;

    rush_data->res = (int **)malloc(sizeof(int *) * size);
    rush_data->row = (int **)malloc(sizeof(int *) * size);
    rush_data->col = (int **)malloc(sizeof(int *) * size);
    rush_data->visible = (int *)malloc(sizeof(int) * (size * 4));
    rush_data->data = (int *)malloc(sizeof(int) * (size * 4));
    n = 0;
    while (n < size)
    {
        rush_data->res[n] = (int *)malloc(sizeof(int) * size);
        rush_data->row[n] = (int *)malloc(sizeof(int) * (size + 1));
        rush_data->col[n] = (int *)malloc(sizeof(int) * (size + 1));
        n++;
    }
    reset_data(rush_data, size);
    copy_table(str, rush_data);
}