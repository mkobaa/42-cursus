/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:20:22 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/25 22:20:22 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted_list(t_list *stack)
{
	while (stack)
	{
		if (stack->next && stack->pos > stack->next->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a);
		else if ((*stack_a)->value > (*stack_a)->next->next->value
			&& (*stack_a)->next->value < (*stack_a)->next->next->value)
			ra(stack_a);
		else if ((*stack_a)->value > (*stack_a)->next->next->value
			&& (*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
	else if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	add_positions(stack_a);
	node = *stack_a;
	if (check_sorted_list(node))
		return ;
	node = *stack_a;
	node = find_node(node, 0);
	to_top(node, stack_a, node->pos);
	pb(stack_a, stack_b);
	node = *stack_a;
	if (!check_sorted_list(node))
		sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	add_positions(stack_a);
	node = *stack_a;
	if (check_sorted_list(node))
		return ;
	node = *stack_a;
	node = find_node(node, 0);
	to_top(node, stack_a, node->pos);
	pb(stack_a, stack_b);
	node = *stack_a;
	node = find_node(node, 1);
	to_top(node, stack_a, node->pos);
	pb(stack_a, stack_b);
	node = *stack_a;
	if (!check_sorted_list(node))
		sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
