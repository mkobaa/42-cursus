/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:36:12 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/27 05:47:00 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	calculate_coll(t_list *map)
{
	int	i;
	int	coll;

	i = 0;
	coll = 0;
	while (map->map[i])
	{
		if (map->map[i] == 'C')
			coll++;
		i++;
	}
	map->coll_number = coll;
}

void	calculate_players(t_list *map)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (map->map[i])
	{
		if (map->map[i] == 'P')
			player++;
		i++;
	}
	map->player_number = player;
}

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
