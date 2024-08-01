/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:37:26 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 05:45:54 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	redraw_window(t_list *map, void *mlx, void *window)
{
	char	*s;

	mlx_clear_window(mlx, window);
	put_walls(map, mlx, window);
	put_coll(map, mlx, window);
	put_player(map, mlx, window);
	put_exit(map, map->mlx, map->win);
	s = ft_itoa(map->moves);
	mlx_string_put(map->mlx, map->win, 10, 10, 0x00000000, s);
	free(s);
	win_function(map);
}

int	key_hook(int keycode, t_list *d)
{
	char	*moves;

	moves = ft_itoa(d->moves);
	if (keycode == 13)
		if (d->y > 1 && (d->map_2d[d->y - 1][d->x] != '1'))
			up_moves(d);
	if (keycode == 1)
		if (d->y < d->lines - 2 && (d->map_2d[d->y + 1][d->x] != '1'))
			down_moves(d);
	if (keycode == 0)
		if (d->x > 1 && (d->map_2d[d->y][d->x - 1] != '1'))
			left_moves(d);
	if (keycode == 2)
		if (d->x < d->columns - 1 && (d->map_2d[d->y][d->x + 1] != '1'))
			right_moves(d);
	if (keycode == 53)
	{
		destroy_window(d);
		exit(0);
	}
	ft_putstr(moves);
	free(moves);
	eat_coll(d);
	redraw_window(d, d->mlx, d->win);
	return (0);
}

int	destroy_window(t_list *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit (0);
}

void	create_mlx_window(t_list *d)
{
	char	*s;

	d->mlx = mlx_init();
	if (d->mlx == NULL)
		ft_puterror(3, d);
	d->win = mlx_new_window(d->mlx, d->columns * 64, d->lines * 64, "so_long");
	if (d->win == NULL)
		ft_puterror(3, d);
	put_walls(d, d->mlx, d->win);
	put_coll(d, d->mlx, d->win);
	put_player(d, d->mlx, d->win);
	put_exit(d, d->mlx, d->win);
	mlx_hook(d->win, 2, 1L << 0, key_hook, d);
	d->moves = 0;
	mlx_hook(d->win, 17, 0, destroy_window, d);
	s = ft_itoa(d->moves);
	mlx_string_put(d->mlx, d->win, 10, 10, 0x00000000, s);
	free(s);
	mlx_loop(d->mlx);
}
