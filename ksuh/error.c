/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:12 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 16:43:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	error(int num)
{
	if (num == 1)
		ft_putendl("usage: ./rush-01 \"3 2 1 2 2 1 2 3 3 2 1 2 2 1 2 3\"");
	else if (num == 2)
	{
		ft_putendl("invalid argument");
		error(1);
	}
	else if (num == 3)
	{
		ft_putendl("invalid argument: n/o inputs must be a multiple of 4");
		error(1);
	}
	else if (num == 4)
		ft_putendl("out of board range: 4 ~ 9");
	else if (num == 5)
		ft_putendl("inputs out of board range");
	else if (num == 6)
		ft_putendl("malloc error");
}
