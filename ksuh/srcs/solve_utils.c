/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:36 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/11 17:50:10 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	pre_solve(int row, int col, t_rush *rush)
{
	if (rush->up_idx[col] == -1 || row < rush->up_idx[col])
	{
		rush->up_idx[col] = row;
		rush->up_see[col]++;
	}
	if (rush->down_idx[col] == -1 || row > rush->down_idx[col])
	{
		rush->down_idx[col] = row;
		rush->down_see[col]++;
	}
	if (rush->left_idx[row] == -1 || col < rush->left_idx[row])
	{
		rush->left_idx[row] = col;
		rush->left_see[row]++;
	}
	if (rush->right_idx[row] == -1 || col > rush->right_idx[row])
	{
		rush->right_idx[row] = col;
		rush->right_see[row]++;
	}
}

void	post_solve(int row, int col, int data[6], t_rush *rush)
{
	if (rush->up_idx[col] == row)
	{
		rush->up_idx[col] = data[0];
		rush->up_see[col]--;
	}
	if (rush->down_idx[col] == row)
	{
		rush->down_idx[col] = data[1];
		rush->down_see[col]--;
	}
	if (rush->left_idx[row] == col)
	{
		rush->left_idx[row] = data[2];
		rush->left_see[row]--;
	}
	if (rush->right_idx[row] == col)
	{
		rush->right_idx[row] = data[3];
		rush->right_see[row]--;
	}
}
