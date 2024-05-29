/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:48:23 by mkobaa            #+#    #+#             */
/*   Updated: 2024/05/27 19:47:27 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

int check_int(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '-' || s[i] == '+')
		{
			if (ft_strlen(s) > 1 && check_space(s) == 0)
				i++;
			else
				return 0;
		}
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
			return (0);
		else
			i++;
	}
	return (1);
}

int check_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		else
			i++;
	}
	return (0);
}
