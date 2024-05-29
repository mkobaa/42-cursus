/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:32:26 by mkobaa            #+#    #+#             */
/*   Updated: 2024/05/27 23:06:04 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checks(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (check_int(argv[i]))
		{
			if (check_space(argv[i]) == 1)
			{
				ft_split(argv[i], ' ');
				while (j < count_words(argv[i], ' '))
					j++;
				j = 0;
			}
		}
		else
			return 0;
		i++;
	}
	return 1;
}


int main(int argc, char *argv[])
{
	char **str_array;
	int i;
	int j;
	int number_of_chars;
	int spaces;

	i = 1;
	j = 0;
	number_of_chars = 0;
	spaces = 0;
	while (i < argc)
	{
		if (check_space(argv[i]))
		{
			while (argv[i][j])
			{
				if (argv[i][j] == ' ')
					spaces++;
				j++;
			}
			number_of_chars =number_of_chars + j - spaces;
			j = 0;
		}
		else
			number_of_chars = number_of_chars + ft_strlen(argv[i]);
		i++;
	}
	str_array = malloc(number_of_chars * argc);
	if (checks(argc, argv))
		ft_printf("%d", number_of_chars);
	else
		ft_printf("no");
}
