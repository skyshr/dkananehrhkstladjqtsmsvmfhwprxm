#include "rush.h"

int	main(int argc, char *argv[])
{
	int		n;
	char	*str;
	t_rush	*rush_data;
	t_idx	*rush_idx;

	if (argc != 2)
	{
		ft_putstr("The number of argument must be 1.\n");
		return (-1);
	}
	str = argv[1];
	if (!error_check(str)) // 에러처리
		return (-1);
	n = ft_strlen(str) / 4;
	rush_data = (t_rush *)malloc(sizeof(t_rush));
	rush_idx = (t_idx *)malloc(sizeof(t_idx));
	ft_init_data(rush_data, n, str); //rush구조체 할당
	ft_init_idx(rush_idx, n); //idx구조체 할당
	ft_rush(rush_data, rush_idx, n);
	ft_free_data(rush_data, n); //rush구조체 해제
	ft_free_idx(rush_idx); //idx구조체 해제
	return (0);
}
