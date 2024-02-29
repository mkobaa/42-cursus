/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:26:24 by mkobaa            #+#    #+#             */
/*   Updated: 2024/02/29 08:18:34 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8000

# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char    *find_full_buffer(int fd);
char    *find_line(char *buffer);
char    *find_rest(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(const char *s, int c, size_t size);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif