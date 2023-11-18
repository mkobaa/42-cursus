/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:47:10 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/18 10:52:13 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces(const char *str)
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
	int	i;
	int	sign;
	int	rslt;

	i = skip_spaces(str);
	rslt = 0;
	sign = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		sign++;
		i++;
	}
	if (sign == 1 && str[i - 1] == '-')
		sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt = rslt * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1 || sign == 1)
		return (rslt * sign);
	else if (sign == 0)
		return (rslt);
	return (0);
}
