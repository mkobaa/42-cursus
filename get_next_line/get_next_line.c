/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:30:33 by mkobaa            #+#    #+#             */
/*   Updated: 2024/02/07 22:51:32 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_full_buffer(int fd)
{
	char	*tmp;
	char	*buffer;
	int		ret;

	buffer = ft_strdup("");
	tmp = malloc(BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	while (ft_strchr(tmp, '\n') == 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret <= 0)
			break;
		buffer = ft_strjoin(buffer , tmp);
	}
	free(tmp);
	return (buffer);
}
char *find_line(char *buffer)
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
    line = malloc(i + 2);
    if (!line)
        return (NULL);
    while (j < i)
    {
        line[j] = buffer[j];
        j++;
    }
    line[j++] = buffer[i];
    line[j] = '\0';
    return line;
}
char *find_rest(char *buffer)
{
	char	*rest;
    int		i;
	int		k;
    int		to_alloc;

	i = 0;
    if (!buffer)
        return (NULL);
	while (buffer[i] && buffer[i] != '\n') 
        i++;
	to_alloc = ft_strlen(buffer) - i;
	rest = malloc(to_alloc);
	while (buffer[i] != 0)
	{
		
	}
}
char get_next_line(int fd)
{
	return 0;
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", find_line(find_full_buffer(fd)));
	printf("%s", find_line(find_full_buffer(fd)));
	printf("%s", find_line(find_full_buffer(fd)));
	printf("%s", find_line(find_full_buffer(fd)));
	printf("%s", find_line(find_full_buffer(fd)));
	printf("%s", find_line(find_full_buffer(fd)));
}