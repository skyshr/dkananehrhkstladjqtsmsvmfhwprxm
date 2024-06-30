#include "rush.h"

int	ft_erase_blank(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]))
			return (-1);
		if (str[i] == ' ')
			cnt++;
		else if (ft_isdigit(str[i]))
			str[i - cnt] = str[i];
		else
			return (-2);
		i++;
	}
	str[i - cnt] = '\0';
	return (ft_strlen(str));
}