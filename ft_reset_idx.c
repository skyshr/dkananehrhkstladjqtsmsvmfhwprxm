#include "rush.h"

void    ft_reset_idx(t_idx *rush_idx, int size)
{
    int n;

    n = 0;
    while (n < size)
    {
        rush_idx->left[n] = -1;
        rush_idx->right[n] = -1;
        rush_idx->up[n] = -1;
        rush_idx->down[n] = -1;
        n++;
    }
}