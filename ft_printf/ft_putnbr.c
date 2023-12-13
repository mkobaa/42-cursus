/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:49:06 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/13 01:19:58 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(long nb)
{
    int count = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
        count++;
    }
    if (nb < 10)
    {
        ft_putchar(nb + '0');
        return count + 1;
    }
    else
    {
        count += ft_putnbr(nb / 10);
        count += ft_putchar(nb % 10 + '0');
        return count;
    }
}

