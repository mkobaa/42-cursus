/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:56:36 by mkobaa            #+#    #+#             */
/*   Updated: 2024/03/25 11:29:29 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ff()
{
    system("leaks a.out");
}
int main()
{
    // atexit(ff);
    char *line;

    int fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);   
    printf("%s", line);
    free(line); 
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    ////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    // //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    // //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    // //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    // //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //////////////////////////////
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
}

// // #include <stdio.h>
// // #include <stdlib.h>
// // int main ()
// // {
// //     char *rest = malloc(1);
// //     rest = NULL;
// //     if (!rest)
// //     {
// //         printf("null");
// //     }
// //     else 
// //     {
// //         printf("not null");
// //     }
// // }
