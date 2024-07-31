/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:30:05 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/31 06:41:21 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
#include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000

# define PLAYER "./ressources/pac.xpm"
# define WALL "./ressources/wall.xpm"
# define COLL "./ressources/apple.xpm"
# define EXIT "./ressources/exit.xpm"

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
	void	*window;
	int		moves;
	char 	**map_copy;
	char	*moves_c;
}	t_list;

void		ft_puterror(int i, t_list *map);
int			destroy_window(t_list *map);
int			check_extension(char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			check_file(int ac, char *av[], t_list *map);
char		*get_next_line2(char **rest, char **buffer, int fd);
char		*get_next_line(int fd);
char		*find_full_buffer(int fd);
void		find_full_buffer_helper(char **tmp, char **buffer, int ret);
char		*find_line(char *buffer);
char		*find_rest(char *buffer);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_strchr(const char *s, int c);
int			ft_strlen(char *s);
char		*ft_strdup(char *s1);
int			create_1d_map(t_list *map);
static int	count_words(char const *s, char c);
static int	word_len(const char *s, char c);
static void	*ft_free(char **str, int i);
static char	**ft_fill(char **str, char const *s, char c);
char		**ft_split(char const *s, char c);
int			columns_number(t_list *map);
void		calculate_coll(t_list *map);
void		calculate_players(t_list *map);
void		calculate_exit(t_list *map);
int			lines_number(t_list *map);
int			check_columns_walls(t_list *map);
void		redraw_window(t_list *map, void *mlx, void *window);
void		ft_putstr(char *str);
char		*ft_itoa(int n);
void    	flood_fill(t_list *d, int x, int y);
int			check_filled(t_list *map);
int 		check_flood_fill(t_list *map);
void 		create_map_copy(t_list *d);
void		find_cordinates(t_list *map);

#endif
