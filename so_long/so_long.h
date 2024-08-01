/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:30:05 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 05:27:19 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000

#  define PLAYER "./ressources/pac.xpm"
#  define WALL "./ressources/wall.xpm"
#  define COLL "./ressources/apple.xpm"
#  define EXIT "./ressources/exit.xpm"

# endif

typedef struct s_list
{
	int		fd;
	int		coll_number;
	int		player_number;
	int		exit_number;
	int		lines;
	int		columns;
	char	*map;
	char	**map_2d;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	int		moves;
	char	**map_copy;
	char	**text;
	int		p_index;
}	t_list;

void	eat_coll(t_list *map);
void	win_function(t_list *map);
int		check_extension(char *s);
int		check_file(int ac, char *av[], t_list *map);
char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
void	flood_fill(t_list *d, int x, int y);
int		check_filled(t_list *map);
int		check_lines_walls(t_list *map);
int		check_columns_walls(t_list *map);
int		check_flood_fill(t_list *map);
int		main_checks(int ac, char *av[], t_list *map);
int		create_1d_map(t_list *map);
void	create_map_copy(t_list *d);
void	calculate_exit(t_list *map);
void	find_cordinates(t_list *map);
int		columns_number(t_list *map);
int		lines_number(t_list *map);
void	calculate_coll(t_list *map);
void	calculate_players(t_list *map);
void	redraw_window(t_list *map, void *mlx, void *win);
int		key_hook(int keycode, t_list *map);
int		destroy_window(t_list *map);
void	create_mlx_window(t_list *map);
void	up_moves(t_list *map);
void	down_moves(t_list *map);
void	left_moves(t_list *map);
void	right_moves(t_list *map);
void	put_player(t_list *map, void *mlx, void *win);
void	put_walls(t_list *map, void *mlx, void *win);
void	put_coll(t_list *map, void *mlx, void *win);
void	put_exit(t_list *map, void *mlx, void *win);
void	create_text(t_list *map);
char	*get_next_line(int fd);
char	*get_next_line2(char **rest, char **buffer, int fd);
char	*find_line(char *buffer);
char	*find_full_buffer(int fd);
void	find_full_buffer_helper(char **tmp, char **buffer, int ret);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
char	*find_rest(char *buffer);
void	ft_puterror(int i, t_list *map);
void	ft_putstr(char *s);
void	error4(t_list *map);

#endif
