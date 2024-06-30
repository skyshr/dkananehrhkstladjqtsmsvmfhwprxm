#include "rush.h"

void    ft_pre_rush(int num, int *dif, t_rush *data, t_idx *idx)
{
    pre_rush_row(num, dif, data, idx);
    pre_rush_col(num, dif, data, idx);
    data->res[dif[4]][dif[5]] = num;
    data->col[dif[5]][num] = 1;
    data->row[dif[4]][num] = 1;
}