/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:30:33 by mkobaa            #+#    #+#             */
/*   Updated: 2024/03/25 07:40:48 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_full_buffer(int fd)
{
	char	*tmp;
	char	*buffer;
	int		ret;

	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	(1) && (*buffer = 0, ret = 1);
	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), NULL);
	while (ret > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret < 0)
			return(free(buffer), NULL);
		tmp[ret] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	(free(tmp), tmp = NULL);
	if (ret <= 0 && !*buffer)
		return (free(buffer), buffer = NULL, NULL);
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
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[j] = '\n';
	line[j] = '\0';
	return (line);
}

char	*find_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	rest = malloc(ft_strlen(buffer) - i);
	if (!rest)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0'; 
	if (buffer)
		(free(buffer), buffer = NULL);
	return (rest);
}

void	get_next_line2(char **line, char **rest, char **buffer, int fd)
{
	*buffer = NULL;
	if (*rest[0] == '\0')
	{
		*line = find_line(*buffer);
		if (*rest)
		{
			free(*rest);
			*rest = NULL;
		}
	}
	if (ft_strchr(*rest, '\n'))
	{
		*line = find_line(*rest);
		*rest = find_rest(*rest);
	}
	else
	{
		*buffer = find_full_buffer(fd);
		*line = ft_strjoin2(*rest, find_line(*buffer));
		*rest = find_rest(*buffer);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rest;
	
	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) < 0)
		return (free(rest), rest = NULL, NULL);
	if (!rest)
	{
		buffer = find_full_buffer(fd);
		line = find_line(buffer);
		if (BUFFER_SIZE == 1)
		{
			if (rest)
				(free(rest), rest = NULL);
			if (buffer)
				(free(buffer), buffer = NULL);
		}
		else
			rest = find_rest(buffer);
	}
	else
		get_next_line2(&line, &rest, &buffer, fd);
	// printf("rest-----> %p\n", rest);
	// printf("line-----> %p\n", line);
	// printf("buffer-----> %p\n", buffer);
	// printf("rst------> %p", rest);
	// printf("rst_len------> %zu", ft_strlen(rest));
	return (line);
}
