/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:53:44 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/08 21:33:36 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str)
{
    if (str == NULL) {
        // Handle the case where str is NULL
        ft_putstr("(null)");
        return 6; // Return the number of characters printed for "(null)"
    }

    int i = 0;

    while (str[i] != '\0') {
        ft_putchar(str[i]);
        i++;
    }

    return i;
}


