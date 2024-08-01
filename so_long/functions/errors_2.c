/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 05:21:07 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 06:18:41 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error4(t_list *map)
{
	int	r;

	ft_putstr("Invalid texture");
	r = 0;
	while (r < map->lines)
		free(map->map_2d[r++]);
	free(map->map);
	free(map->map_2d);
	r = 0;
	while (r < map->lines)
		free(map->map_copy[r++]);
	free(map->map_copy);
	r = 0;
	while (r < 4)
		free(map->text[r++]);
	free(map);
	free(map->text);
}
