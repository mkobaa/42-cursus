/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:25:37 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/26 02:25:37 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_in_array(int ac, char *av[], int size, int *tab)
{
	if (!check_arguments(ac, av))
		return (0);
	process_arguments(ac, av, tab);
	if (!check_duplicates(tab, size))
		return (0);
	if (!check_sorted(tab, size))
		return (0);
	return (1);
}

void	sort_more(t_list **stack_a, t_list **stack_b)
{
	push_a_to_b(stack_a, stack_b);
	reindex(stack_b);
	push_b_to_a(stack_a, stack_b);
}

void	reindex(t_list **stack)
{
	add_indices(stack);
	calculate_cost(stack);
	add_positions(stack);
}

void	declare_variables(t_list **node, t_list **s_a, t_list **s_b)
{
	*s_a = NULL;
	*node = *s_a;
	s_b = NULL;
}

int	main(int ac, char *av[])
{
	int		total_args;
	int		*tab;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*node;
	
	if (ac == 1)
	{
		return 0;
	}
	

	declare_variables(&node, &stack_a, &stack_b);
	total_args = calculate_args(ac, av);
	tab = malloc(total_args * sizeof(int));
	if (!check_in_array(ac, av, total_args, tab))
		return (free(tab), 0);
	lst_fill(total_args, tab, &stack_a);
	free(tab);
	add_indices(&stack_b);
	if (total_args <= 5)
		sort_cases(total_args, &stack_a, &stack_b);
	else
		sort_more(&stack_a, &stack_b);
	while (node)
	{
		free(node);
		node = node->next;
	}
}
