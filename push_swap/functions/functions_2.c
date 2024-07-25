/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:21:25 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/24 23:21:25 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	just_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i == 1)
	{
		if (s[0] == '+' || s[0] == '-')
			return (0);
	}
	return (1);
}

long long	ft_atoi(const char *str)
{
	long long	res;
	int			negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **stack_a, t_list *new)
{
	if (stack_a == NULL || new == NULL)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		return ;
	}
	while ((*stack_a)->next != NULL)
	{
		stack_a = &(*stack_a)->next;
	}
	(*stack_a)->next = new;
}

void	lst_fill(int total_args, int *tab, t_list **stack_a)
{
	int		i;
	t_list	*new_node;

	i = 0;
	while (i < total_args)
	{
		new_node = ft_lstnew(tab[i]);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}
