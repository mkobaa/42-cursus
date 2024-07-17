#include "../push_swap.h"

void add_indices(t_list **stack_a)
{
    int size = ft_lstsize(*stack_a);
    if (size == 0) return;

    t_list **nodes = (t_list **)malloc(size * sizeof(t_list *));
    t_list *current = *stack_a;
    int i = 0;
    while (i < size) {
        nodes[i] = current;
        current = current->next;
        i++;
    }
    i = 0;
    while (i < size - 1)
    {
        int j = i + 1;
        while (j < size) {
            if (nodes[i]->value > nodes[j]->value)
            {
                t_list *temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < size)
    {
        nodes[i]->index = i;
        i++;
    }
    free(nodes);
}


void sort_cases(int size, t_list **stack_a, t_list **stack_b)
{  
    if (size == 2)
        sort_two(stack_a);
    if (size == 3)
        sort_three(stack_a);
    if (size == 5 )
        sort_five(stack_a, stack_b);
    if (size == 4)
        sort_four(stack_a, stack_b);
}