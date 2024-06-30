#include "rush.h"

int	ft_solve_rush(int num, int col, t_rush *data, t_idx *idx)
{
	int	row;
	int	dif[6];
	
	if (num == 0)
		return (1);
	if (col == idx->size)
		return (solve_rush(num - 1, 0, data, idx));
	row = -1;
    dif[5] = col;
    
	while (++row < idx->size)
	{
		if (!data->col[col][num] && !data->row[row][num] && !data->res[row][col])
		{
			is_valid(row, dif, data, idx);
			if (dif[4] != -1)
			{
				pre_rush(num, dif, data, idx);
				if (solve_rush(num, col + 1, data, idx))
					return (1);
				post_rush(num, dif, data, idx);
			}
		}
	}
	return (0);
}