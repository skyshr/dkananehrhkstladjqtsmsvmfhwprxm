#include "rush.h"

void    ft_init_idx(t_idx *rush_idx, int size)
{
    rush_idx->size = size;
    rush_idx->left = (int *)malloc(sizeof(int) * size);
    rush_idx->right = (int *)malloc(sizeof(int) * size);
    rush_idx->up = (int *)malloc(sizeof(int) * size);
    rush_idx->down = (int *)malloc(sizeof(int) * size);
    ft_reset_idx(rush_idx, size); //-1초기화
}