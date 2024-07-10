#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             value;
    struct s_list   *next;
} stack_a ;

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
void	ft_lstadd_back(stack_a **lst, stack_a *new);
stack_a	*ft_lstnew(int content);
void lst_fill(int total_args, int *tab, stack_a **lst);
int all_checks(char *s, int ac);
int all_checks_2(char *s, int ac);
int	ft_lstsize(stack_a *lst);
void process_arguments(int ac, char *av[], int *tab, int *size);
int calculate_args(int ac, char *av[]);
void free_splitted(char **splitted);
int check_arguments(int ac, char *av[]);

#endif