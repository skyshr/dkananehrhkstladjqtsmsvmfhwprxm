#include "rush.h"

void	ft_reset_data(t_rush *rush_data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size + 1)
		{
			if (j < size)
				rush_data->res[i][j] = 0;
			rush_data->row[i][j] = 0;
			rush_data->col[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
		rush_data->visible[i++] = 0;
}