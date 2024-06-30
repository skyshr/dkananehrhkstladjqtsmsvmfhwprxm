#include "rush.h"

void	ft_copy_table(char *str, t_rush *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		data->data[i] = str[i] - '0';
		i++;
	}
}