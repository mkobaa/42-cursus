/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:12:14 by mkobaa            #+#    #+#             */
/*   Updated: 2024/06/07 02:42:11 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int get_pid()
{
	pid_t pid = getpid();
	return (pid);
}

int main() 
{
	int pid;
	
	pid = get_pid();
	printf("The PID is : %d\n", pid);
	while (1)
	{
		
	}
	return 0;
}