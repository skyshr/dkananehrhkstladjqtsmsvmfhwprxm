/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:17 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 16:43:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	free_2d(int **arr, int size)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

void	init_rush_vars(t_rush *rush)
{
	int	i;

	i = 0;
	while (i < rush->size)
	{
		rush->up_see[i] = 0;
		rush->down_see[i] = 0;
		rush->left_see[i] = 0;
		rush->right_see[i] = 0;
		rush->up_idx[i] = -1;
		rush->down_idx[i] = -1;
		rush->left_idx[i] = -1;
		rush->right_idx[i] = -1;
		i++;
	}
}

void	free_rush(t_rush **rush)
{
	t_rush	*tmp;

	tmp = *rush;
	free_2d(tmp->result, tmp->size);
	free_2d(tmp->row_visited, tmp->size + 1);
	free(tmp->col_up);
	free(tmp->col_down);
	free(tmp->row_left);
	free(tmp->row_right);
	free(tmp);
	tmp = NULL;
}
