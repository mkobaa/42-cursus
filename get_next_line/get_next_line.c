/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:17:20 by mkobaa            #+#    #+#             */
/*   Updated: 2024/01/10 19:39:49 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_full_buffer(int fd)
{
    char    *str;
    char    *tmp;
    char    *ptr;
    int      ret;

    str = ft_strdup("");
    ptr = malloc(BUFFER_SIZE + 1);
    if (!ptr)
        return (NULL);
    while ((ret = read(fd, ptr, BUFFER_SIZE)) > 0)
    {
        ptr[ret] = '\0';
        tmp = ft_strjoin(str, ptr);
        free(str);
        str = tmp;
        if (ft_strchr(str, '\n') || ret < BUFFER_SIZE)
            break;
    }
    free(ptr);
    if (ret <= 0)
    {
        free(str);
        return(NULL);
    }
    return (str);
}

char *find_line(char *buffer)
{
    char *line;
    int i;

    if (!buffer)
        return (NULL);
    i = 0;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc(i + 1);
    if (line)
    {
        ft_memcpy(line, buffer, i);
        line[i] = '\n';
    }
    return (line);
}

char    *find_rest(char *buffer)
{
    char *rest;
    int i;

    i = 0;
    while (buffer[i] != '\n')
    {
        i++;
    }
    rest = ft_strdup(&buffer[i + 1]);
    return (rest);
}

char *get_next_line(int fd)
{
    char *line;
    static char *rest;
    char *buffer;
    line = 0;
    line = ft_strjoin(line, rest);
    buffer = find_full_buffer(fd);
    line = ft_strjoin(line, find_line(buffer));
    rest = find_rest(buffer);
    return (line);
}


// int main()
// {
//     int fd = open("text.txt", O_RDONLY);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
// }