/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:12:14 by mkobaa            #+#    #+#             */
/*   Updated: 2024/06/07 22:34:25 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int get_pid()
{
	pid_t pid = getpid();
	return (pid);
}

int main() 
{
	int pid;
	
	pid = get_pid();
	ft_printf("The PID is : %d\n", pid);
	while (1)
	{
		
	}
	return 0;
}