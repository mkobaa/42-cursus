/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:33:34 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 05:47:40 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player(t_list *d, void *mlx, void *win)
{
	int		i;
	int		j;
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, d->text[d->p_index], &width, &height);
	if (!img)
		ft_puterror(3, d);
	i = 0;
	while (d->map_2d[i])
	{
		j = 0;
		while (d->map_2d[i][j])
		{
			if (d->map_2d[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img, d->x * 64, d->y * 64);
			j++;
		}
		i++;
	}
}

void	put_walls(t_list *map, void *mlx, void *win)
{
	int		i;
	int		j;
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, WALL, &width, &height);
	if (!img)
		ft_puterror(3, map);
	i = 0;
	while (map->map_2d[i])
	{
		j = 0;
		while (map->map_2d[i][j])
		{
			if (map->map_2d[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_coll(t_list *map, void *mlx, void *win)
{
	int		i;
	int		j;
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, COLL, &width, &height);
	if (!img)
		ft_puterror(4, map);
	i = 0;
	while (map->map_2d[i])
	{
		j = 0;
		while (map->map_2d[i][j])
		{
			if (map->map_2d[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	put_exit(t_list *map, void *mlx, void *win)
{
	int		i;
	int		j;
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, EXIT, &width, &height);
	if (!img)
		ft_puterror(3, map);
	i = 0;
	while (map->map_2d[i])
	{
		j = 0;
		while (map->map_2d[i][j])
		{
			if (map->map_2d[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	create_text(t_list *map)
{
	map->text = malloc(4 * sizeof(char *));
	if (map->text == NULL)
		ft_puterror(3, map);
	map->p_index = 0;
	map->text[0] = ft_strdup("./ressources/pac-right.xpm");
	if (map->text[0] == NULL)
		ft_puterror(3, map);
	map->text[1] = ft_strdup("./ressources/pac-left.xpm");
	if (map->text[1] == NULL)
		ft_puterror(3, map);
	map->text[2] = ft_strdup("./ressources/pac-top.xpm");
	if (map->text[2] == NULL)
		ft_puterror(3, map);
	map->text[3] = ft_strdup("./ressources/pac-down.xpm");
	if (map->text[3] == NULL)
		ft_puterror(3, map);
	map->p_index = 0;
}
