#include "rush.h"

int	error_check(char *str)
{
	int	n;

	n = erase_blank(str);
	if (n == -1)
	{
		ft_putstr("No input number over 9.\n");
		return (0);
	}
	if (n == -2)
	{
		ft_putstr("The values must be digit.\n");
		return (0);
	}
	if (n % 4 != 0)
	{
		ft_putstr("The number of values must be a multiple of 4.\n");
		return (0);
	}
	n /= 4;
	if (n >= 10)
	{
		ft_putstr("The input must be less than size of 10.\n");
		return (0);
	}
	if (!check_valid_num(str, n))
	{
		ft_putstr("The value must be a number between 1 and n.\n");
		return (0);
	}
	return (1);
}
