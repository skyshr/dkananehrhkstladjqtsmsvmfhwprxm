/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:43 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 16:56:53 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	rushy(t_rush *rush)
{
	if (solve_rush(rush->size, 0, rush))
		print_result(rush->result, rush->size);
	else
		ft_putendl("Error");
}

int	solve_rush(int num, int col, t_rush *rush)
{
	int	data[6];
	int	row;

	if (num == 0)
		return (1);
	if (col == rush->size)
		return (solve_rush(num - 1, 0, rush));
	row = -1;
	data[5] = col;
	while (++row < rush->size)
	{
		if (rush->result[row][col] || rush->row_visited[row][num])
			continue ;
		rush->result[row][col] = num;
		if (isvalid_num(num, row, data, rush))
			return (1);
		rush->result[row][col] = 0;
	}
	return (0);
}
