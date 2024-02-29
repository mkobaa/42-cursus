/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:30:33 by mkobaa            #+#    #+#             */
/*   Updated: 2024/02/29 16:42:35 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_full_buffer(int fd)
{
	char	*tmp;
	char	*buffer;
	int		ret;

	buffer = ft_calloc(1, 1);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (ft_strchr(tmp, '\n', BUFFER_SIZE) == 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		tmp[ret] = '\0';
		if (ret <= 0)
			break ;
		buffer = ft_strjoin(buffer, tmp);
	}

	return (buffer);
}

char	*find_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j++] = buffer[i];
	line[j] = '\0';
	return (line);
}

char	*find_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	rest = malloc(ft_strlen(buffer) - i);
	if (!rest)
		return (NULL);
	i++;
	while (buffer[i])
	{
		rest[j] = buffer[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
    char		*buffer;
    char		*line;
	int			i;
    static char	*rest;
    
	buffer = find_full_buffer(fd);
	if (!rest)
	{
		line = find_line(buffer);
		rest = find_rest(buffer);
	}
	else
	{
		if (ft_strchr(rest, '\n', BUFFER_SIZE))
		{
			line = find_line(rest);
			while (rest[i] != 0)
				
		}
		else
		{
			line = ft_strjoin(rest, find_line(buffer));
			rest = find_rest(buffer);
		}
	}
	if (buffer[0] == 0)
		return NULL;
	return (rest);
}
