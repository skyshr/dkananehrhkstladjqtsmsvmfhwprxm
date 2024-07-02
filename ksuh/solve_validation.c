/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:40 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 16:43:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	isvalid_up(int row, int col, t_rush *rush);
static int	isvalid_down(int row, int col, t_rush *rush);
static int	isvalid_left(int row, int col, t_rush *rush);
static int	isvalid_right(int row, int col, t_rush *rush);

int	isvalid_num(int num, int row, int data[6], t_rush *rush)
{
	int	col;

	data[4] = row;
	col = data[5];
	if (!isvalid_up(row, col, rush))
		return (0);
	if (!isvalid_down(row, col, rush))
		return (0);
	if (!isvalid_left(row, col, rush))
		return (0);
	if (!isvalid_right(row, col, rush))
		return (0);
	return (next_rush(num, data, rush));
}

int	isvalid_up(int row, int col, t_rush *rush)
{
	int	max;
	int	min;

	if (rush->up_idx[col] == -1)
	{
		max = 1 + row;
		min = 1 + (row != 0);
	}
	else if (row < rush->up_idx[col])
	{
		max = rush->up_see[col] + 1 + row;
		min = rush->up_see[col] + 1 + (row != 0);
	}
	else
	{
		max = rush->up_see[col] + rush->up_idx[col];
		min = rush->up_see[col] + (rush->up_idx[col] != 0);
	}
	if (rush->col_up[col] >= min && rush->col_up[col] <= max)
		return (1);
	return (0);
}

int	isvalid_down(int row, int col, t_rush *rush)
{
	int	cur_see;
	int	cur_idx;
	int	max;
	int	min;

	cur_see = rush->down_see[col];
	cur_idx = rush->down_idx[col];
	if (cur_idx == -1)
	{
		max = rush->size - row;
		min = 1 + ((row + 1) != rush->size);
	}
	else if (row < cur_idx)
	{
		max = cur_see + rush->size - cur_idx - 1;
		min = cur_see + ((cur_idx + 1) != rush->size);
	}
	else
	{
		max = cur_see + rush->size - row;
		min = cur_see + 1 + ((row + 1) != rush->size);
	}
	if (rush->col_down[col] >= min && rush->col_down[col] <= max)
		return (1);
	return (0);
}

int	isvalid_left(int row, int col, t_rush *rush)
{
	int	max;
	int	min;

	if (rush->left_idx[row] == -1)
	{
		max = 1 + col;
		min = 1 + (col != 0);
	}
	else if (col < rush->left_idx[row])
	{
		max = rush->left_see[row] + 1 + col;
		min = rush->left_see[row] + 1 + (col != 0);
	}
	else
	{
		max = rush->left_see[row] + rush->left_idx[row];
		min = rush->left_see[row] + (rush->left_idx[row] != 0);
	}
	if (rush->row_left[row] >= min && rush->row_left[row] <= max)
		return (1);
	return (0);
}

int	isvalid_right(int row, int col, t_rush *rush)
{
	int	cur_see;
	int	cur_idx;
	int	max;
	int	min;

	cur_see = rush->right_see[row];
	cur_idx = rush->right_idx[row];
	if (cur_idx == -1)
	{
		max = rush->size - col;
		min = 1 + ((col + 1) != rush->size);
	}
	else if (col < cur_idx)
	{
		max = cur_see + rush->size - cur_idx - 1;
		min = cur_see + ((cur_idx + 1) != rush->size);
	}
	else
	{
		max = cur_see + rush->size - col;
		min = cur_see + 1 + ((col + 1) != rush->size);
	}
	if (rush->row_right[row] >= min && rush->row_right[row] <= max)
		return (1);
	return (0);
}
