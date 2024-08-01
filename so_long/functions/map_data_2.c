/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:17:20 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 04:28:08 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	calculate_exit(t_list *map)
{
	int	i;
	int	exit;

	i = 0;
	exit = 0;
	while (map->map[i])
	{
		if (map->map[i] == 'E')
			exit++;
		i++;
	}
	map->exit_number = exit;
}
