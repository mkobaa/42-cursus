/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:09:19 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/26 19:41:37 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int to_allocate(char *str)
{
    int i;
    i = 0;
    while (str && str[i] && str[i] != '\n')
    {
        i++;
    }
    return (i);
}

char *get_next_line(int fd)
{
    int i;
    int size;
    int to_read;
    char *str;
    i = 0;
    char *buff = malloc(buff_size * sizeof(char));
    to_read = size;
    read(fd, buff, to_read);
    if (size > buff_size)
    {
        str = malloc(to_allocate(buff) + 1);
        while(i != '\n')
        {
            str[i] = buff[i];
            i++;
        }
        str[i] = '\n';
    }
    return(str);
}

int main()
{
    int fd = open("text.txt", O_RDONLY);
    // printf("%d", to_allocate("hello world\n"));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}