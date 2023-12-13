/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:36:46 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/12 20:45:38 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putupperhex(unsigned long num)
{
    char hex_digits[] = "0123456789ABCDEF";
    int count = 0;

    if (num >= 16)
    {
        count += ft_putupperhex(num / 16);
    }
    ft_putchar(hex_digits[num % 16]);
    count++;

    return count;
}