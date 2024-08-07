/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:34:06 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 06:18:55 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_list	*map;

	map = malloc(sizeof(t_list));
	if (!map)
		return (0);
	if (!main_checks(ac, av, map))
		return (0);
	create_map_copy(map);
	create_text(map);
	if (!check_flood_fill(map))
		return (0);
	create_mlx_window(map);
}
