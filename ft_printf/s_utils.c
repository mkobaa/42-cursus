/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:26:36 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/19 11:51:46 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count++;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return (count + 1);
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putchar(nb % 10 + '0');
		return (count);
	}
}

void	ft_putunsigned(long nb)
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

int	ft_putptr(void *ptr)
{
	unsigned long	ptr_value;

	ptr_value = (unsigned long)ptr;
	write(1, "0x", 2);
	return (2 + ft_putlowerhex(ptr_value));
}
