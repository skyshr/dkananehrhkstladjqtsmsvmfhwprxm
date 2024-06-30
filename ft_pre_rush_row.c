#include "rush.h"

void    ft_pre_rush_row(int num, int *dif, t_rush *data, t_idx *idx)
{
    int temp;
    
    if (dif[0] != -1)
    {
        data->visible[dif[4]] += 1;
        temp = idx->left[dif[4]];
        idx->left[dif[4]] = dif[0];
        dif[0] = temp - dif[0];
    }
    else
        dif[0] = 0;
    if (dif[1] != -1)
    {
        data->visible[idx->size + dif[4]] += 1;
        temp = idx->right[dif[4]];
        idx->right[dif[4]] = dif[1];
        dif[1] -= temp;
    }
    else
        dif[1] = 0;
}