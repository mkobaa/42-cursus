/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:18:15 by mkobaa            #+#    #+#             */
/*   Updated: 2024/05/27 15:36:58 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_printf_helper(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr((unsigned long)va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_putlowerhex(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (ft_putupperhex(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(specifier));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (write(1, "0", 0))
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += ft_printf_helper(format[i + 1], args);
			i += 2;
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				break ;
			ft_putchar(format[i++]);
			count++;
		}
	}
	return (va_end(args), count);
}
