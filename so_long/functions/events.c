/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:35:17 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 04:39:49 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	eat_coll(t_list *map)
{
	if (map->map_2d[map->y][map->x] == 'C')
	{
		map->coll_number -= 1;
		map->map_2d[map->y][map->x] = '0';
	}
}

void	win_function(t_list *map)
{
	if (map->map_2d[map->y][map->x] == 'E' && map->coll_number == 0)
	{
		ft_putstr("You won!");
		exit(0);
	}
}
