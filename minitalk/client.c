/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:05:58 by mkobaa            #+#    #+#             */
/*   Updated: 2024/06/17 18:09:27 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

char	*ascii_to_binary(char s)
{
	static char	binary[9];
	int			i;

	binary[8] = '\0';
	i = 7;
	while (s > 0 && i >= 0)
	{
		binary[i--] = (s & 1) + '0';
		s >>= 1;
	}
	while (i >= 0)
		binary[i--] = '0';
	return (binary);
}

void	kill_signal(char c, int pid)
{
	if (c == '0')
		kill(pid, SIGUSR1);
	else if (c == '1')
		kill(pid, SIGUSR2);
	usleep(500);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;
	int		i;
	char	*binary;
	int		j;

	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [MESSAGE]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		binary = ascii_to_binary(message[i]);
		j = 0;
		while (binary[j])
		{
			kill_signal(binary[j], pid);
			j++;
		}
		i++;
	}
}
