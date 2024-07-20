#include "../push_swap.h"
#include <limits.h>

void to_top(t_list **stack, int value, void (*rotate)(t_list**), void (*reverse_rotate)(t_list**))
{
    int size = ft_lstsize(*stack);
    int half_size = size / 2;
    int pos = 0;
    t_list *node = *stack;

    while (node && node->index != value)
    {
        pos++;
        node = node->next;
    }

    if (pos <= half_size)
    {
        while ((*stack)->index != value)
            rotate(stack);
    }
    else
    {
        while ((*stack)->index != value)
            reverse_rotate(stack);
    }
}

void push_smallest_to_b(t_list **stack_a, t_list **stack_b, int batch_size)
{
    int pushed = 0;

    while (pushed < batch_size && *stack_a)
    {
        t_list *node = *stack_a;
        t_list *min_node = *stack_a;

        // Find the node with the smallest value
        while (node)
        {
            if (node->value < min_node->value)
                min_node = node;
            node = node->next;
        }

        to_top(stack_a, min_node->index, ra, rra);
        pb(stack_a, stack_b);
        pushed++;
    }
}

void push_to_b(t_list **stack_a, t_list **stack_b)
{
    int total_size = ft_lstsize(*stack_a);
    int batch_size = 20;

    while (total_size > 0)
    {
        if (total_size < batch_size)
            batch_size = total_size;
        push_smallest_to_b(stack_a, stack_b, batch_size);
        total_size -= batch_size;
    }
}

void push_to_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        t_list *node = *stack_b;
        t_list *max_node = *stack_b;

        // Find the node with the largest value
        while (node)
        {
            if (node->value > max_node->value)
                max_node = node;
            node = node->next;
        }

        to_top(stack_b, max_node->index, rb, rrb);
        pa(stack_a, stack_b);
    }
}

void sort_stack(t_list **stack_a, t_list **stack_b)
{
    push_to_b(stack_a, stack_b);
    push_to_a(stack_a, stack_b);
}
