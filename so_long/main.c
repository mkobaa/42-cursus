/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:34:06 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/31 06:41:49 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(int ac, char *av[], t_list *map)
{
	if (ac != 2 || check_extension(av[1]))
		return (0);
    if (map->fd == -1)
		return (0);
	return (1);
}

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
	if (!s)
		return (0);
	map->map = s;
	return (1);
};

int	columns_number(t_list *map)
{
	char	**splitted;
	int		i;
    int j = 0;
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
	while (j < i)
    {
        free(splitted[j]);
        j++;
    }
    free(splitted);
	map->columns = column_size;
	return (1);
}

int	lines_number(t_list *map)
{
	int	i;
	
	i = 0;
	map->map_2d = ft_split(map->map, '\n');
	while (map->map_2d[i] != NULL)
		i++;
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
	if (!check_file(ac, av, map))
        return (ft_puterror(1, map), 0);
	map->fd = open(av[1], O_RDONLY);
    if (map->fd == -1)
        return (ft_puterror(1, map), 0);
    if (!create_1d_map(map) || !columns_number(map) || !check_filled(map))
        return (ft_puterror(2, map), 0);
	calculate_coll(map);
	calculate_players(map);
	calculate_exit(map);
	lines_number(map);
	if (!check_lines_walls(map) || !check_columns_walls(map))
        return (ft_puterror(2, map), 0);
	if (!map->coll_number || map->player_number != 1 || map->exit_number != 1)
        return (ft_puterror(2, map), 0);
    find_cordinates(map);
    // printf("x = %d, y = %d\n", map->x, map->y);
    return (1);
}

void put_player(t_list *map, void *mlx, void *win)
{
    int i;
    int j;
    void *img;
	int width;
	int height;

    img = mlx_xpm_file_to_image(mlx, PLAYER, &width, &height);
    if (!img)
        ft_puterror(3, map);
    i = 0;
    while (map->map_2d[i])
    {
        j = 0;
        while (map->map_2d[i][j])
        {
            if (map->map_2d[i][j] == 'P')
                mlx_put_image_to_window(mlx, win, img, map->x * 64, map->y * 64);
            j++;
        }
        i++;
    }
}

void put_walls(t_list *map, void *mlx, void *win)
{
    int i;
    int j;
    void *img;
	int width;
	int height;

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

void put_coll(t_list *map, void *mlx, void *win)
{
    int i;
    int j;
    void *img;
	int width;
	int height;

    img = mlx_xpm_file_to_image(mlx, COLL, &width, &height);
    if (!img)
        ft_puterror(3, map);
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


void put_exit(t_list *map, void *mlx, void *win)
{
    int i;
    int j;
    void *img;
	int width;
	int height;

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

void find_cordinates(t_list *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map->map_2d[i])
    {
        j = 0;
        while (map->map_2d[i][j])
        {
            if (map->map_2d[i][j] == 'P')
            {
                map->x = j;
				map->y = i;
            }
            j++;
        }
        i++;
    }
	
}

void eat_coll(t_list *map)
{
    if (map->map_2d[map->y][map->x] == 'C')
    {
        map->coll_number -= 1;
        map->map_2d[map->y][map->x] = '0';
    }
}

void win(t_list *map)
{
    if (map->map_2d[map->y][map->x] == 'E' && map->coll_number == 0)
    {
        printf("You won!\n");
        exit(0);
    }
}

void redraw_window(t_list *map, void *mlx, void *window)
{
    mlx_clear_window(mlx, window);
    put_walls(map, mlx, window);
    put_coll(map, mlx, window);
    put_player(map, mlx, window);
    put_exit(map, map->mlx, map->window);
    char *s = ft_itoa(map->moves);
    mlx_string_put(map->mlx, map->window, 10, 10, 0x00000000, s);
    win(map);
    free(s);
}


int key_hook(int keycode, t_list *map)
{
    if (keycode == 13)
        if (map->y > 1 && (map->map_2d[map->y - 1][map->x] != '1'))
        {
            map->moves += 1;
            map->y -= 1;
            printf("up\n");
        }
    if (keycode == 1)
        if (map->y < map->lines - 2 && (map->map_2d[map->y + 1][map->x] != '1'))
        {
            map->moves += 1;
            map->y += 1;
            printf("down\n");
        }
    if (keycode == 0)
        if (map->x > 1 && (map->map_2d[map->y][map->x - 1] != '1'))
        {
            map->moves += 1;
            map->x -= 1;
            printf("left\n");
        }
    if (keycode == 2)
        if (map->x < map->columns - 1 && (map->map_2d[map->y][map->x + 1] != '1'))
        {
            map->moves += 1;
            map->x += 1;
            printf("right\n");
        }
    if (keycode == 53)
    {
        destroy_window(map);
        exit(0);
    }
    eat_coll(map);
    redraw_window(map, map->mlx, map->window);
    return (0);
}

int destroy_window(t_list *map)
{
    mlx_destroy_window(map->mlx, map->window);
    ft_putstr("You exited the game\n");
    exit (0);
}

void create_mlx_window(t_list *map)
{   
    char *s;
    
    map->mlx = mlx_init();
    if (map->mlx == NULL)
        ft_puterror(3, map);
    map->window = mlx_new_window(map->mlx, map->columns * 64, map->lines * 64, "so_long");
    if (map->window == NULL)
        ft_puterror(3, map);
    put_walls(map, map->mlx, map->window);
    put_coll(map, map->mlx, map->window);
    put_player(map, map->mlx, map->window);
    put_exit(map, map->mlx, map->window);
    mlx_hook(map->window, 2, 1L<<0, key_hook, map);
    map->moves = 0;
    mlx_hook(map->window, 17, 0, destroy_window, map);
    s = ft_itoa(map->moves);
    mlx_string_put(map->mlx, map->window, 10, 10, 0x00000000, s);
    free(s);
    mlx_loop(map->mlx);
}

void ft_free_mapcopy(t_list *map)
{
    int i;

    if (map == NULL || map->map_copy == NULL)
        return;
    i = 0;
    while (map->map_copy[i])
    {
        free(map->map_copy[i]);
        i++;
    }
    free(map->map_copy);
}


void f()
{
    system("leaks so_long");
}


int main(int ac, char *av[])
{
    t_list  *map;
    atexit(f);
    map = malloc(sizeof(t_list));
    if (!main_checks(ac, av, map))
        return (0);
    create_map_copy(map);
    // map->player_texture = ft_strdup(PLAYER);
    if (!check_flood_fill(map))  //TODO ktfroo only is succes
        return (0);
    
    // printf("%p", map->map_2d);
    create_mlx_window(map);
}