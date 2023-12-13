/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:20:01 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/12 23:10:28 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putunsigned(long nb)
{
    if (nb < 0)
    {
        ft_putnbr(4294967038);
    }
    if (nb < 10)
    {
        ft_putchar(nb + '0');
        return ;
    }
    ft_putunsigned(nb / 10);
    ft_putunsigned(nb % 10);
}