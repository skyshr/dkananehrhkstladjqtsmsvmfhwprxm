#include "rush.h"

void    ft_free_data(t_rush *data, int size)
{
    int n;

    n = 0;
    while (n < size)
    {
        free(data->res[n]);
        free(data->row[n]);
        free(data->col[n]);
        n++;
    }
    free(data->visible);
    free(data->data);
    free(data->res);
    free(data->row);
    free(data->col);
    free(data);
}