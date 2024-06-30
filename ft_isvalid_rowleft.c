#include "rush.h"

int	ft_isvalid_rowleft(int row, int *dif, t_rush *data, t_idx *idx)
{
	int	left;
	int	col;
	int	see;
	int	idx_left;

	left = data->data[row];
	col = dif[5];
	see = data->visible[row];
	idx_left = idx->left[row];
	if (idx_left == -1 || col < idx_left)
	{
		if (see + 1 + col < left || see + 1 + (col > 0) > left)
			return (0);
		dif[0] = col;
	}
	return (1);
}