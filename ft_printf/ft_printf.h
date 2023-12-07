/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:52:10 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/07 21:51:07 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(long n);
void	ft_putunsigned(unsigned long n);
void	ft_printhexmaj(int num);
void	ft_printhex(int num);

#endif