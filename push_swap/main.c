#include "push_swap.h"

void visualizeStack(t_list* top, const char* stackName) {
    printf("%s:\n", stackName);
    while (top != NULL) {
        printf("| Value: %d, pos: %d, index: %d | \n", top->value, top->pos, top->index);
        top = top->next;
    }
    printf("---------------\n");
}

int main(int ac, char *av[])
{
    int total_args = calculate_args(ac, av);
    int *tab = malloc(total_args * sizeof(int));    
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    if (!check_arguments(ac, av))
        return 0;
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
    push_to_b(total_args, &stack_a, &stack_b);
    // printf("%s", "\n");
    // visualizeStack(stack_a, "Stack A");
    // visualizeStack(stack_b, "Stack B");
    free(tab);
    return 0;
}