/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:21 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 16:43:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	ft_isdigit(int c);
static int	is_range(char *arg, int size);

int	isvalid_arg(char *arg, int *size)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
			return (error(2), 0);
		if (arg[i] == '\0')
			break ;
		if (arg[i++] != ' ')
			return (error(2), 0);
	}
	i++;
	if (i % 8)
		return (error(3), 0);
	if (i / 8 < 4 || i / 8 > 9)
		return (error(4), 0);
	if (!is_range(arg, i / 8))
		return (error(5), 0);
	*size = i / 8;
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_range(char *arg, int size)
{
	char	low;
	char	high;

	low = '1';
	high = '0' + size;
	while (*arg != '\0')
	{
		if (*arg < low || *arg > high)
			return (0);
		arg++;
		if (*arg)
			arg++;
	}
	return (1);
}
