/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:30:27 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/05 08:08:34 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_puterror();
int check_number(char *s);
int check_sign(char *s);
int check_full_spaces(char *s);
int check_null(char *s);
int just_sign(char *s);
int	count_words(char const *s, char c);
static int	word_len(const char *s, char c);
static void	*ft_free(char **str, int i);
static char	**ft_fill(char **str, char const *s, char c);
char	**ft_split(char const *s, char c);
static int	skip_spaces(const char *str);
int	ft_atoi(const char *str);
int check_duplicates(int *tab, int size);

#endif
