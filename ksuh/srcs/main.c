/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:19:30 by ksuh              #+#    #+#             */
/*   Updated: 2024/07/03 15:07:38 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	t_rush	*rush;
	int		size;

	if (argc != 2)
		return (error(1), EXIT_FAILURE);
	if (!isvalid_arg(argv[1], &size))
		return (EXIT_FAILURE);
	rush = init_rush(size, argv[1]);
	if (!rush)
		return (error(6), EXIT_FAILURE);
	rushy(rush);
	free_rush(&rush);
	return (EXIT_SUCCESS);
}
