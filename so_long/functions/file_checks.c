/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:26:50 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 04:23:51 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *s)
{
	int		i;
	char	*extension;

	extension = ".ber";
	i = 0;
	while (i < (ft_strlen(s) - 4))
		i++;
	if (ft_strncmp(&s[i], extension, 4))
		return (1);
	return (0);
}

int	check_file(int ac, char *av[], t_list *map)
{
	if (ac != 2 || check_extension(av[1]))
		return (0);
	if (map->fd == -1)
		return (0);
	return (1);
}
