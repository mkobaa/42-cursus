/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:34:02 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/24 23:34:02 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_duplicates(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= (size))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
			{
				ft_puterror();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	all_checks(char *s, int ac)
{
	int	max;
	int	min;

	max = 2147483647;
	min = -2147483648;
	if (ac == 1)
		return (0);
	if (!check_full_spaces(s) || !check_sign(s) || !check_null(s)
		|| !check_number(s) || !just_sign(s) || ft_atoi(s) > max
		|| ft_atoi(s) < min)
		return (0);
	return (1);
}

int	all_checks_2(char *s, int ac)
{
	int	max;
	int	min;

	max = 2147483647;
	min = -2147483648;
	if (ac == 1)
		return (0);
	if (!check_sign(s) || !check_null(s) || !check_full_spaces(s)
		|| !just_sign(s) || ft_atoi(s) > max || ft_atoi(s) < min)
		return (0);
	return (1);
}

int	ft_lstsize(t_list *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}
