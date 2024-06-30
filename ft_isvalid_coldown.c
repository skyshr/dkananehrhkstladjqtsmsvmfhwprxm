#include "rush.h"

int	ft_isvalid_coldown(int row, int *dif, t_rush *data, t_idx *idx)
{
	int	size;
	int	down;
	int	col;
	int	see;
	int	idx_down;

	size = idx->size;
	col = dif[5];
	down = data->data[3 * size + col];
	see = data->visible[3 * size + col];
	idx_down = idx->down[col];
	if (idx_down == -1 || row > idx_down)
	{
		if (see + (size - row) < down || see + 1 + (row < size - 1) > down)
			return (0);
		dif[3] = row;
	}
	return (1);
}