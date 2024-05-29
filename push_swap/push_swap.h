/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:34:38 by mkobaa            #+#    #+#             */
/*   Updated: 2024/05/27 18:30:33 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putlowerhex(unsigned long num);
int		ft_putnbr(long nb);
int		ft_putstr(char *str);
int		ft_putupperhex(unsigned long num);
int		ft_unsignedlen(long nbr);
int		ft_putptr(void *ptr);
void	ft_putunsigned(long nb);
int		check_int(char *s);
int		check_space(char *s);
char	**ft_split(char const *s, char c);
int		count_words(char const *s, char c);
int     process_arguments(int argc, char *argv[]);
int     ft_strlen(char *s);

#endif