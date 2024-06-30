#include "rush.h"

void    ft_pre_rush_col(int *dif, t_rush *data, t_idx *idx)
{
    int temp;
    
    if (dif[2] != -1)
    {
        data->visible[2 * idx->size + dif[5]] += 1;
        temp = idx->up[dif[5]];
        idx->up[dif[5]] = dif[2];
        dif[2] = temp - dif[2];
    }
    else
        dif[2] = 0;
    if (dif[3] != -1)
    {
        data->visible[3 * idx->size + dif[5]] += 1;
        temp = idx->down[dif[5]];
        idx->down[dif[5]] = dif[3];
        dif[3] -= temp;
    }
    else
        dif[3] = 0;
}