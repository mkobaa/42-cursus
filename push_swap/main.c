#include "push_swap.h"

void visualizeStack(t_list* top, const char* stackName) {
    printf("%s:\n", stackName);
    while (top != NULL) {
        printf("| Value: %d, pos: %d, index: %d, cost: %d | \n", top->value, top->pos, top->index, top->cost);
        top = top->next;
    }
    printf("---------------\n");
}

void f()
{
    system("leaks push_swap");
}


int main(int ac, char *av[])
{
    atexit(f);
    int total_args = calculate_args(ac, av);
    int *tab = malloc(total_args * sizeof(int));    
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    if (!check_arguments(ac, av))
    {
        free(tab);
        return 0;
    }
    process_arguments(ac, av, tab);
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
    add_positions(&stack_a);
    add_indices(&stack_a);
    add_indices(&stack_b);
    if (total_args <= 5)
        sort_cases(total_args, &stack_a, &stack_b);
    else
    {
        push_a_to_b(&stack_a, &stack_b);
        add_indices(&stack_b);
        calculate_cost(&stack_b);
        add_positions(&stack_b);
        push_b_to_a(&stack_a, &stack_b);
    }
    calculate_cost(&stack_a);
    // printf("%s", "\n");
    add_positions(&stack_a);
    // visualizeStack(stack_a, "Stack A");
    // visualizeStack(stack_b, "Stack B");
    t_list *node = stack_a;
    while (node)
    {
        free(node);
        node = node->next;
    }
    // free(stack_a);
    // free(stack_b);
    // while ()
    // free(stack_b);
    // printf("%p", &stack_a);
    free(tab);
    return 0;
}
