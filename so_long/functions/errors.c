/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:12:04 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 05:26:15 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

static void	error1(t_list *map)
{
	ft_putstr("Error : Invalid file");
	free(map);
	exit(0);
}

static void	error2(t_list *map)
{
	int	r;

	r = 0;
	ft_putstr("Error : Invalid map");
	free(map->map);
	while (r < map->lines)
	{
		free(map->map_2d[r]);
		r++;
	}
	free(map->map_2d);
	free(map);
	free(map->text);
}

static void	error3(t_list *map)
{
	int	r;

	ft_putstr("Error : Invalid map");
	r = 0;
	while (r < map->lines)
	{
		free(map->map_2d[r]);
		r++;
	}
	free(map->map);
	free(map->map_2d);
	r = 0;
	while (r < map->lines)
		free(map->map_copy[r++]);
	free(map->map_copy);
	r = 0;
	while (r < 4)
	{
		free(map->text[r]);
		r++;
	}
	free(map);
	free(map->text);
}

void	ft_puterror(int i, t_list *map)
{
	if (i == 1)
		error1(map);
	if (i == 2)
		error2(map);
	if (i == 3)
		error3(map);
	if (i == 4)
		error4(map);
	exit(1);
}
