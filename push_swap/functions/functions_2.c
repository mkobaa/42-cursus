#include "../push_swap.h"

int just_sign(char *s)
{
    int i; 

    i = 0;
    while (s[i])
        i++;
    if (i == 1)
    {
        if (s[0] == '+' || s[0] == '-')
            return 0;
    }
    return 1;
}

long long	ft_atoi(const char *str)
{
	long long	res;
	int			negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
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


stack_a *ft_lstnew(int content)
{
    stack_a *new;

    new = malloc(sizeof(stack_a));
    if (!new)
        return (NULL);
    new->value = content;
    new->next = NULL;
    return (new);
}


void	ft_lstadd_back(stack_a **lst, stack_a *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next != NULL)
	{
		lst = &(*lst)->next;
	}
	(*lst)->next = new;
}

void lst_fill(int total_args, int *tab, stack_a **lst)
{
    int i = 0;
    while (i < total_args)
    {
        stack_a *new_node = ft_lstnew(tab[i]);
        ft_lstadd_back(lst, new_node);
        i++;
    }
}
