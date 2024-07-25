/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:28:37 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/25 00:28:37 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sa(stack_b);
	write(1, "ss\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*temp;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	first = *stack_a;
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*stack_a = first->next;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*temp;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	first = *stack_b;
	temp = *stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	*stack_b = first->next;
	first->next = NULL;
	write(1, "rb\n", 3);
}
