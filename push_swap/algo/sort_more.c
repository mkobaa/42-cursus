#include "../push_swap.h"
#include <limits.h>

int calculate_cost(t_list **stack_a, int index)
{
    int size = ft_lstsize(*stack_a);
    int cost;
    
    if (index < size / 2)
        cost = index;
    else
        cost = size - index;

    return cost;
}

void sort_38(int size, t_list **stack_a, t_list **stack_b)
{
    int j = 0;
    int chunk_size;

    if (size >= 20)
        chunk_size = 20;
    else
        chunk_size = size;

    while (j < chunk_size)
    {
        t_list *node = *stack_a;
        int best_cost = INT_MAX;
        int best_pos = -1;
        int best_index = -1;

        while (node != NULL)
        {
            if (node->index <= size / 2 && node->pos >= 0 && node->pos < chunk_size)
            {
                int cost = calculate_cost(stack_a, node->index);
                if (cost < best_cost)
                {
                    best_cost = cost;
                    best_pos = node->pos;
                    best_index = node->index;
                }
            }
            node = node->next;
        }

        if (best_index != -1)
        {
            node = *stack_a;
            int i = 0;
            while (node != NULL && node->index != best_index)
            {
                node = node->next;
                i++;
            }
            if (i <= ft_lstsize(*stack_a) / 2)
            {
                int rotate_count = i;
                while (rotate_count > 0)
                {
                    ra(stack_a);
                    rotate_count--;
                }
            }
            else
            {
                int reverse_rotate_count = ft_lstsize(*stack_a) - i;
                while (reverse_rotate_count > 0)
                {
                    rra(stack_a);
                    reverse_rotate_count--;
                }
            }
            pb(stack_a, stack_b);
            add_indices(stack_a);
            add_indices(stack_b);
        }
        j++;
    }
    t_list *node = *stack_a;
    while (node)
    {
        pb(stack_a, stack_b);
        node = node->next;
    }
    
}



void sort_all_cases(int size, t_list **stack_a, t_list **stack_b)
{
    if (size >= 79 && size <= 100)
    {
        sort_38(size, stack_a, stack_b);
        add_positions(stack_a);
        sort_38(size, stack_a, stack_b);
        add_positions(stack_a);
        sort_38(size, stack_a, stack_b);
        add_positions(stack_a);
        sort_38(size, stack_a, stack_b);
    }
    else if (size >= 59 && size < 79)
    {
        sort_38(size, stack_a, stack_b);
        add_positions(stack_a);
        sort_38(size, stack_a, stack_b);
        add_positions(stack_a);
        sort_38(size, stack_a, stack_b);
    }
    else if (size >= 39 && size < 59)
    {
        sort_38(size, stack_a, stack_b);
        add_positions(stack_a);
        sort_38(size, stack_a, stack_b);
    }
    else if (size >= 20 && size < 39)
        sort_38(size, stack_a, stack_b);



while (*stack_b) {
    int max = size - 1;
    t_list *node = *stack_b;
    int best_cost = INT_MAX;
    int best_pos = -1;
    int best_index = -1;

    // Single traversal to find the best cost node
    while (node != NULL) {
        if (node->index <= size / 2 && (node->pos == max || node->pos == max - 1)) {
            int cost = calculate_cost(stack_a, node->index);
            if (cost < best_cost) {
                best_cost = cost;
                best_pos = node->pos;
                best_index = node->index;
            }
        }
        node = node->next;
    }

    // Rotate to the best position
    while ((*stack_b)->pos != best_pos) {
        rb(stack_b);
    }
    pa(stack_a, stack_b);
}



// printf("%d", best_pos);


}

