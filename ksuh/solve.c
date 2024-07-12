/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:43 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/11 18:01:20 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	solve_rush(int num, int col, t_rush *rush);

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
	row = -1;
	data[5] = col;
	while (++row < rush->size)
	{
		if (rush->result[row][col] || rush->row_visited[row][num])
			continue ;
		rush->result[row][col] = num;
		if (isvalid_num(row, data, rush))
		{
			rush->row_visited[row][num] = 1;
			pre_solve(row, col, rush);
			if (solve_rush(num - (((col + 1) % rush->size) == 0), \
				(col + 1) % rush->size, rush))
				return (1);
			post_solve(row, col, data, rush);
			rush->row_visited[row][num] = 0;
		}
		rush->result[row][col] = 0;
	}
	return (0);
}
