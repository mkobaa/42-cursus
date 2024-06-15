/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 00:05:58 by mkobaa            #+#    #+#             */
/*   Updated: 2024/06/15 08:39:27 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int skip_spaces(const char *str)
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\n'
        || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
        i++;
    return i;
}

int ft_atoi(const char *str)
{
    long rslt = 0;
    int i = skip_spaces(str);
    int sign = 1;
    long max = 0;

    if (str[i] == '+' || str[i] == '-')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        rslt = rslt * 10 + (str[i] - '0');
        if (rslt < max && sign == -1)
            return 0;
        if (rslt < max && sign == 1)
            return -1;
        i++;
        max = rslt;
    }
    return (int)(sign * rslt);
}

char *ascii_to_binary(char s)
{
    static char binary[9];
    binary[8] = '\0';
    int i = 7;
    while (s > 0 && i >= 0)
    {
        binary[i--] = (s & 1) + '0';
        s >>= 1;
    }
    while (i >= 0)
        binary[i--] = '0';
    return binary;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s [PID] [MESSAGE]\n", argv[0]);
        return 1;
    }

    int pid = ft_atoi(argv[1]);
    char *message = argv[2];

	int i = 0;
	while (message[i])
    {
		char *binary = ascii_to_binary(message[i]);
		int j = 0;
		while (binary[j])
        {
			if (binary[j] == '0')
				kill(pid, SIGUSR1);
			else if (binary[j] == '1')
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
    return 0;
}
