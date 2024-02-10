/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:17:20 by mkobaa            #+#    #+#             */
/*   Updated: 2024/02/01 15:30:53 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_full_buffer(int fd)
{
	char	*str;
	char	*tmp;
	char	*ptr;

	str = ft_strdup("");
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while ((read(fd, ptr, BUFFER_SIZE)) > 0)
	{
		ptr[read(fd, ptr, BUFFER_SIZE)] = '\0';
		tmp = ft_strjoin(str, ptr);
		free(str);
		str = tmp;
		if (read(fd, ptr, BUFFER_SIZE) < BUFFER_SIZE)
			break ;
	}
	free(ptr);
	if (read(fd, ptr, BUFFER_SIZE) < 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*find_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*find_rest(char *buffer)
{
	char	*rest;
	int		i;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	rest = ft_strdup(&buffer[i + 1]);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*new_rest;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	while (!ft_strchr(rest, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(rest, buffer);
		free(rest);
		rest = temp;
	}
	if (bytes_read == -1)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = find_line(rest);
	new_rest = find_rest(rest);
	free(rest);
	rest = new_rest;
	return (line);
}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
}