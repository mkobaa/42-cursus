/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:03:06 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/25 00:03:06 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_positions(t_list **stack_a)
{
	t_list	*current;
	t_list	*compare;
	int		pos;

	current = *stack_a;
	while (current != NULL)
	{
		pos = 0;
		compare = *stack_a;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				pos++;
			compare = compare->next;
		}
		current->pos = pos;
		current = current->next;
	}
}

void	add_indices(t_list **stack_a)
{
	t_list	*node;
	int		i;

	node = *stack_a;
	i = 0;
	while (node)
	{
		node->index = i;
		node = node->next;
		i++;
	}
}

void	sort_cases(int size, t_list **stack_a, t_list **stack_b)
{
	if (size == 2)
		sort_two(stack_a);
	if (size == 3)
		sort_three(stack_a);
	if (size == 5)
		sort_five(stack_a, stack_b);
	if (size == 4)
		sort_four(stack_a, stack_b);
}

void	to_top(t_list *node, t_list **stack, int pos)
{
	if (node->index < ft_lstsize(*stack) / 2)
	{
		while ((*stack)->pos != pos)
			ra(stack);
	}
	else
	{
		while ((*stack)->pos != pos)
			rra(stack);
	}
}

t_list	*find_node(t_list *node, int pos)
{
	while (node)
	{
		if ((node)->pos == pos)
			break ;
		node = node->next;
	}
	return (node);
}
