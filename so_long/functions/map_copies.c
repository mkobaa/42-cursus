/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:41:46 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 05:17:54 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	create_1d_map(t_list *map)
{
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
		free(line);
		line = NULL;
	}
	close(map->fd);
	if (!s)
		return (0);
	map->map = s;
	return (1);
}

void	create_map_copy(t_list *d)
{
	int	i;

	i = 0;
	d->map_copy = malloc(sizeof(char *) * (d->lines + 1));
	if (!d->map_copy)
		ft_puterror(3, d);
	while (d->map_2d[i])
	{
		d->map_copy[i] = ft_strdup(d->map_2d[i]);
		i++;
	}
	d->map_copy[i] = NULL;
}
