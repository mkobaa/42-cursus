#include "../push_swap.h"
#include <limits.h>

void calculate_cost(t_list **stack)
{
    t_list *head = *stack;
    while (head)
    {
        if (head->index <= ft_lstsize(*stack) / 2)
            head->cost = head->index;
        else
            head->cost = ft_lstsize(*stack) - head->index;
        head = head->next;
    }
}

void push_min_cost(t_list **stack_a, t_list **stack_b)
{
    calculate_cost(stack_a);
    int size = ft_lstsize(*stack_a);
    int chunk_size = 20;
    int half_size = size / 2;
    int min_cost_top = INT_MAX;
    int min_cost_bottom = INT_MAX;
    t_list *head = *stack_a;
    int count = 0;

 
    while (head && head->index < half_size)
    {
        if (head->pos < chunk_size)
        {
            if (head->cost < min_cost_top)
            {
                min_cost_top = head->cost;
            }
        }
        head = head->next;
    }

    head = *stack_a;
    while (head)
    {
        if (head->index >= half_size)
        {
            if (head->pos < chunk_size)
            {
                if (head->cost < min_cost_bottom)
                {
                    min_cost_bottom = head->cost;
                }
            }
        }
        head = head->next;
    }
    int i = 0;
    if (min_cost_top < min_cost_bottom)
    {
        while (i < min_cost_top)
        {
            ra(stack_a);
            i++;
        }
        pb(stack_a, stack_b);
    }
    else
    {
        while (i < min_cost_bottom)
        {
            rra(stack_a);
            i++;
        }
        pb(stack_a, stack_b);
    }
}

void push_a_to_b(t_list **stack_a, t_list **stack_b)
{
    while (*stack_a)
    {
        add_indices(stack_a);
        add_positions(stack_a);
        calculate_cost(stack_a);
        push_min_cost(stack_a, stack_b);
    }
    
}


void push_b_to_a(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_b);
    while (size > 0)
    {
        t_list *head = *stack_b;
        while (head)
        {
            if (head->pos == size - 1)
            {
                break;
            }
            head = head->next;
        }
        if (head->index < size / 2)
        {
            while ((*stack_b)->pos != head->pos)
            {
                rb(stack_b);
            }
            pa(stack_a, stack_b);
        }
        else if (head->index >= size / 2)
        {
            while ((*stack_b)->pos != head->pos)
            {
                rrb(stack_b);
            }
            pa(stack_a, stack_b);
        }
        size--;
        add_indices(stack_b);
        calculate_cost(stack_b);
    }
}