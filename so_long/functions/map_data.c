/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:39:09 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 04:27:00 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_cordinates(t_list *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_2d[i])
	{
		j = 0;
		while (map->map_2d[i][j])
		{
			if (map->map_2d[i][j] == 'P')
			{
				map->x = j;
				map->y = i;
			}
			j++;
		}
		i++;
	}
}

int	columns_number(t_list *map)
{
	char	**splitted;
	int		i;
	int		j;
	int		first_column_size;
	int		column_size;

	i = 0;
	j = 0;
	splitted = ft_split(map->map, '\n');
	first_column_size = ft_strlen(splitted[i]);
	i++;
	while (splitted[i] != NULL)
	{
		column_size = ft_strlen(splitted[i]);
		if (column_size != first_column_size)
			return (0);
		i++;
	}
	while (j < i)
		free(splitted[j++]);
	free(splitted);
	map->columns = column_size;
	return (1);
}

int	lines_number(t_list *map)
{
	int	i;

	i = 0;
	map->map_2d = ft_split(map->map, '\n');
	while (map->map_2d[i] != NULL)
		i++;
	map->lines = i;
	return (1);
}

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
