#include "rush.h"

int	ft_check_valid_num(char *str, int n)
{
	while (*str != '\0')
	{
		if (*str - '0' < 1 || *str - '0' > n)
			return (0);
		str++;
	}
	return (1);
}