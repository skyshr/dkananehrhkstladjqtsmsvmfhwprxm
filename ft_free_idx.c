#include "rush.h"

void    ft_free_idx(t_idx *idx)
{
    free(idx->left);
    free(idx->right);
    free(idx->up);
    free(idx->down);
    free(idx);
}