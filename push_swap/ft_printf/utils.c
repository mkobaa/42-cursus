/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:26:30 by mkobaa            #+#    #+#             */
/*   Updated: 2024/05/27 15:37:03 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putlowerhex(unsigned long num)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_putlowerhex(num / 16);
	}
	ft_putchar(hex_digits[num % 16]);
	count++;
	return (count);
}

int	ft_putupperhex(unsigned long num)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += ft_putupperhex(num / 16);
	}
	ft_putchar(hex_digits[num % 16]);
	count++;
	return (count);
}
