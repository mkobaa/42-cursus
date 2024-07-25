/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:39:38 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/24 23:39:38 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_args(int ac, char *av[])
{
	int		i;
	int		number;
	int		args;
	char	**splitted;
	int		split_i;

	i = 1;
	number = 1;
	args = 0;
	while (number < ac)
	{
		splitted = ft_split(av[i], ' ');
		split_i = 0;
		while (splitted[split_i])
		{
			args++;
			split_i++;
		}
		free_splitted(splitted);
		number++;
		i++;
	}
	return (args);
}

void	process_arguments(int ac, char *av[], int *tab)
{
	int		i;
	int		number;
	int		tab_i;
	char	**splitted;
	int		split_i;

	i = 1;
	number = 1;
	tab_i = 0;
	while (number < ac)
	{
		splitted = ft_split(av[i], ' ');
		split_i = 0;
		while (split_i < count_words(av[i], ' '))
		{
			tab[tab_i] = ft_atoi(splitted[split_i]);
			split_i++;
			tab_i++;
		}
		free_splitted(splitted);
		number++;
		i++;
	}
}

int	check_arguments(int ac, char *av[])
{
	int		i;
	int		number;
	char	**splitted;
	int		split_i;

	i = 1;
	number = 1;
	while (number < ac)
	{
		splitted = ft_split(av[i], ' ');
		split_i = 0;
		while (split_i < count_words(av[i], ' '))
		{
			if (!all_checks(splitted[split_i], ac) || !all_checks_2(av[i], ac))
			{
				ft_puterror();
				return (free_splitted(splitted), 0);
			}
			split_i++;
		}
		free_splitted(splitted);
		number++;
		i++;
	}
	return (1);
}

void	free_splitted(char **splitted)
{
	int	j;

	j = 0;
	while (splitted[j] != NULL)
	{
		free(splitted[j]);
		j++;
	}
	free(splitted);
}

int	check_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}
