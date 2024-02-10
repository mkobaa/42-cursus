/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:21:27 by mkobaa            #+#    #+#             */
/*   Updated: 2024/02/10 01:43:22 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putlowerhex(unsigned long num);
int		ft_putnbr(long nb);
int		ft_putstr(char *str);
int		ft_putupperhex(unsigned long num);
int		ft_unsignedlen(long nbr);
int		ft_putptr(void *ptr);
void	ft_putunsigned(long nb);

#endif