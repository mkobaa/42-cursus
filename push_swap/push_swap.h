#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             value;
    int             index;
    struct s_list   *next;
} t_list ;

void ft_puterror();
int check_number(char *s);
int check_sign(char *s);
int check_full_spaces(char *s);
int check_null(char *s);
int just_sign(char *s);
int	count_words(char const *s, char c);
int	word_len(const char *s, char c);
void	*ft_free(char **str, int i);
char	**ft_fill(char **str, char const *s, char c);
char	**ft_split(char const *s, char c);
int	skip_spaces(const char *str);
long long	ft_atoi(const char *str);
int check_duplicates(int *tab, int size);
void	ft_lstadd_back(t_list **stack_a, t_list *new);
t_list	*ft_lstnew(int content);
void lst_fill(int total_args, int *tab, t_list **stack_a);
int all_checks(char *s, int ac);
int all_checks_2(char *s, int ac);
int	ft_lstsize(t_list *stack_a);
void process_arguments(int ac, char *av[], int *tab);
int calculate_args(int ac, char *av[]);
void free_splitted(char **splitted);
int check_arguments(int ac, char *av[]);
void sa(t_list **stack_a);
void sa(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
void sort_two(t_list **stack_a);
int check_sorted(int *tab, int size);
void sort_three(t_list **stack_a);
void sort_five(t_list **stack_a, t_list **stack_b);
void sort_four(t_list **stack_a, t_list **stack_b);
void add_indices(t_list **stack_a);
void sort_cases(int size, t_list **stack_a, t_list **stack_b);

#endif