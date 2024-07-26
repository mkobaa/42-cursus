/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:02:36 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/26 02:15:23 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	to_top_3(t_list *node, t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (node->index < size / 2)
	{
		while ((*stack_b)->pos != node->pos)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (node->index >= size / 2)
	{
		while ((*stack_b)->pos != node->pos)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
}

void	to_top_2(t_list **stack_a, t_list **stack_b, int top, int bottom)
{
	int	i;

	i = 0;
	if (top < bottom)
	{
		while (i < top)
		{
			ra(stack_a);
			i++;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (i < bottom)
		{
			rra(stack_a);
			i++;
		}
		pb(stack_a, stack_b);
	}
}
