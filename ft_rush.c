#include "rush.h"

void	ft_rush(t_rush *data, t_idx *idx, int size)
{
	if (ft_solve_rush(size, 0, data, idx))
		ft_print(data->res, size);
	else
		write(1, "Error... Invalid data..\n", 24);
}