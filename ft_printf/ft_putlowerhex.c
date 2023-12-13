/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowerhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:36:46 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/12 20:44:48 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putlowerhex(unsigned long num)
{
    char hex_digits[] = "0123456789abcdef";
    int count = 0;

    if (num >= 16)
    {
        count += ft_putlowerhex(num / 16);
    }
    ft_putchar(hex_digits[num % 16]);
    count++;

    return count;
}
