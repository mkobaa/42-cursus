/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:30:33 by mkobaa            #+#    #+#             */
/*   Updated: 2024/02/21 20:23:21 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_full_buffer(int fd)
{
	char	*tmp;
	char	*buffer;
	int		ret;

	buffer = ft_strdup("");
	tmp = malloc(BUFFER_SIZE); // + 1
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
	tmp = NULL;
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
    return line;
}
char	*find_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;
	
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] !=  '\n')
	{
		i++;
	}
	while(buffer[i])
	{
		rest[j] = buffer[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	return (rest);
}
// char get_next_line(int fd)
// {
// 	static char	rest;
	
// 	rest = find_rest(fd);
	
// }

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", find_full_buffer(fd));
	printf("%s", find_full_buffer(fd));
	printf("%s", find_full_buffer(fd));
	printf("%s", find_full_buffer(fd));

}