/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:30:33 by mkobaa            #+#    #+#             */
/*   Updated: 2024/03/29 15:13:03 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_full_buffer_helper(char **tmp, char **buffer, int ret)
{
	(free(*tmp), *tmp = NULL);
	if (ret <= 0 && !**buffer)
		(free(*buffer), *buffer = NULL);
}

char	*find_full_buffer(int fd)
{
	char	*tmp;
	char	*buffer;
	char	*new_buffer;
	int		ret;

	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	(1) && (*buffer = 0, ret = 1);
	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), buffer = NULL, NULL);
	while (ret > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		tmp[ret] = '\0';
		new_buffer = ft_strjoin(buffer, tmp);
		if (!new_buffer)
			return (free(buffer), buffer = NULL, free(tmp), tmp = NULL, NULL);
		buffer = new_buffer;
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	find_full_buffer_helper(&tmp, &buffer, ret);
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
	if (buffer)
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
	line[j++] = '\0';
	return (line);
}

char	*get_next_line2(char **rest, char **buffer, int fd)
{
	char	*line;

	*buffer = NULL;
	if (*rest[0] == '\0')
	{
		line = find_line(*buffer);
		(free(*rest), *rest = NULL);
	}
	if (ft_strchr(*rest, '\n'))
	{
		line = find_line(*rest);
		*rest = find_rest(*rest);
	}
	else
	{
		*buffer = find_full_buffer(fd);
		line = ft_strjoin2(*rest, find_line(*buffer));
		if (!line)
			return (free(*buffer), free(*rest), *rest = NULL, NULL);
		*rest = find_rest(*buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rest[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) < 0)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	if (!rest[fd])
	{
		buffer = find_full_buffer(fd);
		line = find_line(buffer);
		if (!line)
			return (free(buffer), buffer = NULL, free(rest[fd]), NULL);
		if (BUFFER_SIZE == 1 || !ft_strchr(buffer, '\n'))
		{
			if (buffer)
				(free(buffer), buffer = NULL);
		}
		else
			rest[fd] = find_rest(buffer);
	}
	else
		line = get_next_line2(&rest[fd], &buffer, fd);
	if (!line)
		return (free(line), free(rest[fd]), rest[fd] = NULL, line = NULL, NULL);
	return (line);
}
