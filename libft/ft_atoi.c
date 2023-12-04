/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:47:10 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/29 20:34:00 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' 
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	rslt;
	int		i;
	int		sign;
	long	max;

	sign = 1;
	i = skip_spaces(str);
	rslt = 0;
	max = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt = rslt * 10 + (str[i] - '0');
		if (rslt < max && sign == -1)
			return (0);
		if (rslt < max && sign == 1)
			return (-1);
		i++;
		max = rslt;
	}
	return ((int)(sign * rslt));
}
