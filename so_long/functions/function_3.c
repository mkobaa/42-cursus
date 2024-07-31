/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:48:02 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/31 06:19:41 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void flood_fill(t_list *d, int x, int y)
{
    if (d->map_copy[y][x] == 'E')
        d->map_copy[y][x] = 'R';
    if (y < 0 || y >= d->lines || x < 0 || x >= d->columns)
        return ;
    if (d->map_copy[y][x] == '1' || d->map_copy[y][x] == 'R')
        return ;
    d->map_copy[y][x] = 'R';
    flood_fill(d, x + 1, y);
    flood_fill(d, x - 1, y);
    flood_fill(d, x, y + 1);
    flood_fill(d, x, y - 1);
}

void create_map_copy(t_list *d)
{
    int i = 0;
    
    d->map_copy = malloc(sizeof(char *) * (d->lines + 1));
    while (d->map_2d[i])
    {
        d->map_copy[i] = ft_strdup(d->map_2d[i]);
        i++;
    }
    d->map_copy[i] = NULL;
}

int check_flood_fill(t_list *map)
{
    int i;
    int j;
    
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



