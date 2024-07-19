#include "../push_swap.h"
#include <limits.h>

void push_to_b(int size, t_list **stack_a, t_list **stack_b)
{
    int cost_a = -1;
    int cost_b = -1;
    int a;
    int b;
    // if (size == 20)
    while (*stack_a)
    {
        t_list *node = *stack_a;
        while (node->index < size / 2)
        {
            if (node->pos < 19)
            {
                cost_a = node->index;
                a = node->index;
                break;
            }
            node = node->next;
        }
        while (node && node->index < size / 2)
            node = node->next;
        while (node)
        {
            if (node->pos <= 19)
            {
                cost_b = size - node->index;
                b = node->index;
            }
            node = node->next;
        }
        printf("%d\n", cost_a);
        printf("%d\n", cost_b);
        int i = 0;
        // printf("%d\n", cost_a);
        // printf("%d\n", cost_b);
        if (cost_a > cost_b)
        {
            while (i != cost_a)
            {
                ra(stack_a);
                i++;
            }
            pb(stack_a, stack_b);
        }
        else
        {
            while(i != cost_b)
            {
                rra(stack_a);
                i++;
            }
            pb(stack_a, stack_b);
        }
        add_positions(stack_a);
        add_indices(stack_a);
    }
}