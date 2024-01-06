/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:17:20 by mkobaa            #+#    #+#             */
/*   Updated: 2024/01/06 19:59:12 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *rest;
    char *ptr;
    char *str;
    char *buffer;
    char *line;
    int i;
    int j;
    int k;
    ptr = malloc(BUFFER_SIZE);
    str = malloc(0);
    i = 0;
    j = 0;
    k = 0;
    rest = NULL;
    read(fd, ptr, BUFFER_SIZE);
    while (ft_strchr(str, '\n') != 1)
    {
        str = ft_strjoin(str, ptr);
        if (ft_strchr(str, '\n'))
            break;
        read(fd, ptr, BUFFER_SIZE);
    }
    while (str[i] && str[i] != '\n')
        i++;
    buffer = malloc(i + 1);
    while (rest[j])
    {
        buffer[j] = rest[j];
        j++;
    }
    while (str[k] && str[k] != '\n')
    {
        buffer[j] = str[k];
        j++;
    }
    buffer[i] = '\n';
    j = 0;
    return (buffer);
    rest = &str[i];
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));

}