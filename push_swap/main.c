#include "push_swap.h"

int main(int ac, char *av[])
{
    int total_args = calculate_args(ac, av);
    int *tab = malloc(total_args * sizeof(int));
    stack_a *lst = NULL;
    int size = 0;

    if (!check_arguments(ac, av))
        return 0;
    process_arguments(ac, av, tab, &size);
    if (!check_duplicates(tab, total_args))
	{
		return 0;
		free(tab);
	}
	lst_fill(total_args, tab, &lst);
    printf("%d", ft_lstsize(lst));
    free(tab);
    return 0;
}