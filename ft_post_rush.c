#include "rush.h"

void    ft_post_rush(int num, int *dif, t_rush *data, t_idx *idx)
{
    if (dif[0])
    {
        data->visible[dif[4]] -= 1;
        idx->left[dif[4]] += dif[0];
    }
    if (dif[1])
    {
        data->visible[idx->size + dif[4]] -= 1;
        idx->right[dif[4]] -= dif[1];
    }
    if (dif[2])
    {
        data->visible[2 * idx->size + dif[5]] -= 1;
        idx->up[dif[5]] += dif[2];
    }
    if (dif[3])
    {
        data->visible[3 * idx->size + dif[5]] -= 1;
        idx->down[dif[5]] -= dif[3];
    }
    data->res[dif[4]][dif[5]] = 0;
    data->col[dif[5]][num] = 0;
    data->row[dif[4]][num] = 0;
}