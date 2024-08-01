/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pac_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:40:20 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 04:47:58 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up_moves(t_list *map)
{
	if ((map->map_2d[map->y - 1][map->x] != 'E'))
	{
		map->moves += 1;
		map->y -= 1;
		map->p_index = 2;
	}
	else if (map->coll_number == 0)
	{
		ft_putstr("You won!");
		destroy_window(map);
	}
}

void	down_moves(t_list *map)
{
	if ((map->map_2d[map->y + 1][map->x] != 'E'))
	{
		map->moves += 1;
		map->y += 1;
		map->p_index = 3;
	}
	else if (map->coll_number == 0)
	{
		destroy_window(map);
	}
}

void	left_moves(t_list *map)
{
	if ((map->map_2d[map->y][map->x - 1] != 'E'))
	{
		map->moves += 1;
		map->x -= 1;
		map->p_index = 1;
	}
	else if (map->coll_number == 0)
	{
		destroy_window(map);
	}
}

void	right_moves(t_list *map)
{
	if ((map->map_2d[map->y][map->x + 1] != 'E'))
	{
		map->moves += 1;
		map->x += 1;
		map->p_index = 0;
	}
	else if (map->coll_number == 0)
	{
		ft_putstr("You won!");
		destroy_window(map);
	}
}
