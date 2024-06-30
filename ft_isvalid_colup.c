#include "rush.h"

int	ft_isvalid_colup(int row, int *dif, t_rush *data, t_idx *idx)
{
	int	size;
	int	up;
	int	col;
	int	see;
	int	idx_up;

	size = 2 * idx->size;
	col = dif[5];
	up = data->data[size + col];
	see = data->visible[size + col];
	idx_up = idx->up[col];
	if (idx_up == -1 || row < idx_up)
	{
		if (see + 1 + row < up || see + 1 + (row > 0) > up)
			return (0);
		dif[2] = row;
	}
	return (1);
}