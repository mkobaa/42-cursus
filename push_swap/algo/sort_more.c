/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:22:35 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/26 00:22:35 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

void	calculate_cost(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		if (head->index <= ft_lstsize(*stack) / 2)
			head->cost = head->index;
		else
			head->cost = ft_lstsize(*stack) - head->index;
		head = head->next;
	}
}

static void	declare(int *chz, int *mct, int *mcb)
{
	*chz = 20;
	*mcb = INT_MAX;
	*mct = INT_MAX;
}

void	push_min_cost(t_list **stack_a, t_list **stack_b)
{
	int		chunk_size;
	int		min_cost_top;
	int		min_cost_bottom;
	t_list	*head;

	head = *stack_a;
	declare(&chunk_size, &min_cost_top, &min_cost_bottom);
	while (head && head->index < ft_lstsize(*stack_a) / 2)
	{
		if (head->pos < chunk_size)
			if (head->cost < min_cost_top)
				min_cost_top = head->cost;
		head = head->next;
	}
	head = *stack_a;
	while (head)
	{
		if (head->index >= ft_lstsize(*stack_a) / 2)
			if (head->pos < chunk_size)
				if (head->cost < min_cost_bottom)
					min_cost_bottom = head->cost;
		head = head->next;
	}
	to_top_2(stack_a, stack_b, min_cost_top, min_cost_bottom);
}

void	push_a_to_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
	{
		add_indices(stack_a);
		add_positions(stack_a);
		calculate_cost(stack_a);
		push_min_cost(stack_a, stack_b);
	}
}

void	push_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int		size;
	t_list	*head;

	size = ft_lstsize(*stack_b);
	while (size > 0)
	{
		head = *stack_b;
		while (head)
		{
			if (head->pos == size - 1)
				break ;
			head = head->next;
		}
		to_top_3(head, stack_a, stack_b);
		size--;
		add_indices(stack_b);
		calculate_cost(stack_b);
	}
}
