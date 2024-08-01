/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:31:47 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 04:25:26 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_filled(t_list *map)
{
	int		i;
	char	*s;

	i = 0;
	s = map->map;
	while (s[i])
	{
		if (s[i] != '1' && s[i] != '0' && s[i] != 'P'
			&& s[i] != 'C' && s[i] != 'E' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_lines_walls(t_list *map)
{
	int	i;

	i = 0;
	while (map->map_2d[0][i])
	{
		if (map->map_2d[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map->map_2d[map->lines - 1][i])
	{
		if (map->map_2d[map->lines - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_columns_walls(t_list *map)
{
	int	i;

	i = 0;
	while (map->map_2d[i])
	{
		if (map->map_2d[i][0] != '1' || map->map_2d[i][map->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_flood_fill(t_list *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_cordinates(map);
	flood_fill(map, map->x, map->y);
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map_copy[i][j] == 'C' || map->map_copy[i][j] == 'E')
			{
				return (ft_puterror(3, map), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main_checks(int ac, char *av[], t_list *map)
{
	if (!check_file(ac, av, map))
		return (ft_puterror(1, map), 0);
	map->fd = open(av[1], O_RDONLY);
	if (map->fd == -1)
		return (ft_puterror(1, map), 0);
	if (!create_1d_map(map) || !columns_number(map) || !check_filled(map))
		return (ft_puterror(2, map), 0);
	calculate_coll(map);
	calculate_players(map);
	calculate_exit(map);
	lines_number(map);
	if (!check_lines_walls(map) || !check_columns_walls(map))
		return (ft_puterror(2, map), 0);
	if (!map->coll_number || map->player_number != 1 || map->exit_number != 1)
		return (ft_puterror(2, map), 0);
	find_cordinates(map);
	return (1);
}
