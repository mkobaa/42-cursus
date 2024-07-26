/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:22:16 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/26 02:22:16 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	struct s_list	*next;
}	t_list;

void		ft_puterror(void);
int			check_number(char *s);
int			check_sign(char *s);
int			check_full_spaces(char *s);
int			check_null(char *s);
int			just_sign(char *s);
int			count_words(char const *s, char c);
int			word_len(const char *s, char c);
void		*ft_free(char **str, int i);
char		**ft_fill(char **str, char const *s, char c);
char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
int			check_duplicates(int *tab, int size);
void		ft_lstadd_back(t_list **stack_a, t_list *new);
t_list		*ft_lstnew(int content);
void		lst_fill(int total_args, int *tab, t_list **stack_a);
int			all_checks(char *s, int ac);
int			all_checks_2(char *s, int ac);
int			ft_lstsize(t_list *stack_a);
void		process_arguments(int ac, char *av[], int *tab);
int			calculate_args(int ac, char *av[]);
void		free_splitted(char **splitted);
int			check_arguments(int ac, char *av[]);
void		sa(t_list **stack_a);
void		sa(t_list **stack_b);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		sort_two(t_list **stack_a);
int			check_sorted(int *tab, int size);
void		sort_three(t_list **stack_a);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		sort_four(t_list **stack_a, t_list **stack_b);
void		add_positions(t_list **stack_a);
void		add_indices(t_list **stack_a);
void		sort_cases(int size, t_list **stack_a, t_list **stack_b);
void		push_a_to_b(t_list **stack_a, t_list **stack_b);
void		push_min_cost(t_list **stack_a, t_list **stack_b);
void		calculate_cost(t_list **stack);
void		push_b_to_a(t_list **stack_a, t_list **stack_b);
t_list		*find_node(t_list *node, int pos);
void		to_top(t_list *node, t_list **stack, int pos);
void		to_top_3(t_list *node, t_list **stack_a, t_list **stack_b);
void		to_top_2(t_list **stack_a, t_list **stack_b, int top, int bottom);
void		reindex(t_list **stack);
int			check_in_array(int ac, char *av[], int size, int *tab);

#endif