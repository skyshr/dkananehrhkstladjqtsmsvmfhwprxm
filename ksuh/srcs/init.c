/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:26 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/02 16:43:40 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	memset_2d(int **arr, int size);
static void	copy_arg(t_rush *rush, char *arg);
static void	copy_arg_to_arr(int	*arr, int size, char **arg);

t_rush	*init_rush(int size, char *arg)
{
	t_rush	*rush;

	rush = (t_rush *)malloc(sizeof(t_rush));
	if (!rush)
		return (NULL);
	rush->size = size;
	rush->result = init_2d(size);
	if (!rush->result)
		return (free(rush), NULL);
	rush->col_up = (int *)malloc(size * sizeof(int));
	rush->col_down = (int *)malloc(size * sizeof(int));
	rush->row_left = (int *)malloc(size * sizeof(int));
	rush->row_right = (int *)malloc(size * sizeof(int));
	if (!rush->col_up || !rush->col_down \
		|| !rush->row_left || !rush->row_right)
		return (free_rush(&rush), NULL);
	rush->row_visited = init_2d(size + 1);
	if (!rush->result)
		return (free_rush(&rush), NULL);
	init_rush_vars(rush);
	copy_arg(rush, arg);
	return (rush);
}

int	**init_2d(int size)
{
	int	**arr;
	int	i;
	int	j;

	arr = (int **)malloc(size * sizeof(int *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = (int *)malloc(size * sizeof(int));
		if (!arr[i])
		{
			j = 0;
			while (j < i)
				free(arr[j++]);
			return (free(arr), NULL);
		}
		i++;
	}
	memset_2d(arr, size);
	return (arr);
}

void	memset_2d(int **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			arr[i][j++] = 0;
		i++;
	}
}

void	copy_arg(t_rush *rush, char *arg)
{
	copy_arg_to_arr(rush->col_up, rush->size, &arg);
	copy_arg_to_arr(rush->col_down, rush->size, &arg);
	copy_arg_to_arr(rush->row_left, rush->size, &arg);
	copy_arg_to_arr(rush->row_right, rush->size, &arg);
}

void	copy_arg_to_arr(int	*arr, int size, char **arg)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i++] = **arg - '0';
		(*arg) += 2;
	}
}
