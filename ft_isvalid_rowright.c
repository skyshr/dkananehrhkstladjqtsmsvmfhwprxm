#include "rush.h"

int	ft_isvalid_rowright(int row, int *dif, t_rush *data, t_idx *idx)
{
	int	size;
	int	right;
	int	col;
	int	see;
	int	idx_right;
	
	size = idx->size;
	right = data->data[size + row];
	col = dif[5];
	see = data->visible[size + row];
	idx_right = idx->right[row];
	if (idx_right == -1 || col > idx_right)
	{
		if (see + size - col < right || see + 1 + (col < size - 1) > right)
			return (0);
		dif[1] = col;
	}
	return (1);
}