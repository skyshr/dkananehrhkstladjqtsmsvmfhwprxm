#include "rush.h"
void	ft_print(int **res, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = res[i][j] + '0';
			write(1, &c, 1);
			if (j < size - 1)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}