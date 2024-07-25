/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:32:02 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/25 00:32:02 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted_list(t_list *stack)
{
	while(stack)
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
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*stack_a)->pos > 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
	add_positions(stack_a);
	t_list *node = *stack_a; 
	if (check_sorted_list(node))
		return ;
	node = *stack_a;
	while (node)
	{
		if ((node)->pos == 0)
		{
		break;
		}
		node = node->next;
	}
	if (node->index < ft_lstsize(*stack_a) / 2)
	{
		while((*stack_a)->pos != 0)
			ra(stack_a);
				  
	}
	else
	{
		while((*stack_a)->pos != 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	node = *stack_a;
	while (node)
	{
		if ((node)->pos == 1)
		{
		break;
		}
		node = node->next;
	}
	if (node->index < ft_lstsize(*stack_a) / 2)
	{
		while((*stack_a)->pos != 1)
			ra(stack_a);
	}
	else
	{
		while((*stack_a)->pos != 1)
			rra(stack_a);
	}
	pb(stack_a, stack_b);



	node = *stack_a; 
	if (!check_sorted_list(node))
		sort_three(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}
