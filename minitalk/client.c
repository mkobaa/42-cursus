/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:05:58 by mkobaa            #+#    #+#             */
/*   Updated: 2024/06/08 00:07:02 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

char	*ascii_to_binary(char s)
{
	static char	binary[9];
	int			i;

	binary[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		if (s % 2)
			binary[i] = '1';
		else
			binary[i] = '0';
		s /= 2;
		i--;
	}
	return (binary);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		pid;
	char	*binary;

	i = 0;
	if (argc == 3 && ft_atoi(argv[1]) > 0)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			binary = ascii_to_binary(argv[2][i]);
			while (binary[j])
			{
				if (binary[j] == 0)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				j++;
			}
			i++;
		}
	}
	else
		printf("%s", "please add the PID first then the text to send");
}
