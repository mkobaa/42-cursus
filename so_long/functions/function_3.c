/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:48:02 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/28 03:06:17 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	main_checks(int ac, char *av[], t_list *map)
{
	if (!check_file(ac, av))
		return (0);
	map->fd = open(av[1], O_RDONLY);
	if (!create_1d_map(map))
		return (0);
	if (!columns_number(map) || !check_filled(map))
		return (0);
	calculate_coll(map);
	calculate_players(map);
	calculate_exit(map);
	lines_number(map);
	if (!check_lines_walls(map) || !check_columns_walls(map))
		return (0);
	if (!map->coll_number || map->player_number != 1 || map->exit_number != 1)
		return (0);
	return (1);
}

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


// char    **floodfill(t_list d, int x, int y)
// {

	
//     // if (d.map_copie[x][y] == 'E')
//     //     d.map_copie[x][y] = 'D';
// 	printf("player position x = %d, y = %d\n", d.player_x, d.player_y);
// 	if (x < 0 || x >= d.lines || y < 0 || y >= d.columns
//         || (d.map_copie[x][y] == '1' || d.map_copie[x][y] == 'D'))
//         return (d.map_copie);
//     d.map_copie[x][y] = 'D';
//     d.map_copie = floodfill(d, x + 1, y);
//     d.map_copie = floodfill(d, x - 1, y);
//     d.map_copie = floodfill(d, x, y + 1);
//     d.map_copie = floodfill(d, x, y - 1);
//     return (d.map_copie);
// }
