/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:28:48 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/25 00:28:48 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	first_b = *stack_b;
	*stack_b = first_b->next;
	first_b->next = *stack_a;
	*stack_a = first_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;

	first_a = *stack_a;
	if (ft_lstsize(*stack_a) == 0)
		return ;
	*stack_a = first_a->next;
	first_a->next = *stack_b;
	*stack_b = first_a;
	write(1, "pb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	first = *stack_a;
	last = (*stack_a)->next;
	while (last->next)
	{
		first = first->next;
		last = last->next;
	}
	first->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	first = *stack_b;
	last = (*stack_b)->next;
	while (last->next)
	{
		first = first->next;
		last = last->next;
	}
	first->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
