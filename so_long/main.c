/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:34:06 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/27 06:41:28 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(int ac, char *av[])
{
	if (ac != 2)
		return (0);
	if (check_extension(av[1]))
		return (0);
	if (open(av[1], O_RDONLY) == -1)
		return (0);
	return (1);
}

int	create_1d_map(char *av[], t_list *map)
{
	int		fd;
	char	*line;
	char	*s;

	line = NULL;
	s = NULL;
	while (1)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		s = ft_strjoin(s, line);
	}
	if (!s)
		return (0);
	map->map = s;
	return (1);
}

int	columns_number(t_list *map)
{
	char	**splitted;
	int		i;
	int		first_column_size;
	int		column_size;

	i = 0;
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
	map->map_2d = splitted;
	map->columns = column_size;
	return (1);
}

int	lines_number(t_list *map)
{
	int		i;
	
	i = 0;
	map->map_2d = ft_split(map->map, '\n');
	while (map->map_2d[i] != NULL)
	{
		i++;
	}
	map->lines = i;
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

int check_lines_walls(t_list *map)
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

int check_columns_walls(t_list *map)
{
	int i = 0;
	while (map->map_2d[i])
	{
		if (map->map_2d[i][0] != '1' || map->map_2d[i][map->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int main_checks(int ac, char *av[], t_list *map)
{
	if (!check_file(ac, av))
		return (0);
	map->fd = open(av[1], O_RDONLY);
	if (!create_1d_map(av, map))
		return 0;
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

void f()
{
	system("leaks so_long");
}

int	main(int ac, char *av[])
{
	t_list	*map;
	atexit(f);
	map = malloc(sizeof(t_list));
	if (!main_checks(ac, av, map))
	{
		ft_puterror();
		return (0);
	}

	
	free(map->map_2d);
	free(map->map);
	free(map);
}
