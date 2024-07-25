/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:18:07 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/24 23:18:07 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_puterror(void)
{
	write(2, "Error\n", 6);
}

int	check_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9'))
		{
			if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
				i++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i - 1] != ' ' && i != 0)
				return (0);
			if (s[++i] < '0' || s[++i] > '9')
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	check_full_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_null(char *s)
{
	if (s[0] == 0)
		return (0);
	return (1);
}
