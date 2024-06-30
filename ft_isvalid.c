#include "rush.h"

void	ft_is_valid(int row, int *dif, t_rush *data, t_idx *idx)
{
	int	n;

	n = 0;
	while (n < 4)
		dif[n++] = -1;
	dif[4] = -1;
	if (!ft_isvalid_rowleft(row, dif, data, idx))
	    return ;
	if (!ft_isvalid_rowright(row, dif, data, idx))
	    return ;
	if (!ft_isvalid_colup(row, dif, data, idx))
		return ;
	if (!ft_isvalid_coldown(row, dif, data, idx))
	    return;
	dif[4] = row;
}