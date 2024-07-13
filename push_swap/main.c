#include "push_swap.h"

int main(int ac, char *av[])
{
    int total_args = calculate_args(ac, av);
    int *tab = malloc(total_args * sizeof(int));    
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    int size = 0;

    if (!check_arguments(ac, av))
        return 0;
    process_arguments(ac, av, tab, &size);
    if (!check_duplicates(tab, total_args))
	{
		return 0;
		free(tab);
	}
    if (!check_sorted(tab, total_args))
    {
        return 0;
        free(tab);
    }
	lst_fill(total_args, tab, &stack_a);
    if (total_args == 2)
        sort_two(&stack_a);
    if (total_args == 3)
        sort_three(&stack_a);
    if (total_args == 5)
        sort_five(&stack_a, &stack_b);

    // printf("stack a :\n");
    
    // while(stack_a)
    // {
    //     printf("%d ", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    // printf("\n");
    // printf("stack b :\n");
    // while(stack_b)
    // {
    //     printf("%d ", stack_b->value);
    //     stack_b = stack_b->next;
    // }
    free(tab);
    return 0;
}