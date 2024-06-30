#include "rush.h"

int	main(int argc, char *argv[])
{
	int		n;
	char	*str;
	int		*arr;
	t_rush	*rush_data;
	t_idx	*rush_idx;

	if (argc != 2)
	{
		ft_putstr("The number of argument must be 1.\n");
		return (-1);
	}
	str = argv[1];
	if (!error_check(str))
		return (-1);
	n = ft_strlen(str) / 4;
	rush_data = (t_rush *)malloc(sizeof(t_rush));
	rush_idx = (t_idx *)malloc(sizeof(t_idx));
	init_data(rush_data, n, str);
	init_idx(rush_idx, n);
	rush(rush_data, rush_idx, n);
	free_data(rush_data, n);
	free_idx(rush_idx);
	return (0);
}
