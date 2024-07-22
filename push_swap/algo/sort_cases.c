#include "../push_swap.h"

void sort_two(t_list **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void sort_three(t_list **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value)
    {
        if ((*stack_a)->value < (*stack_a)->next->next->value)
            sa(stack_a);
        else if ((*stack_a)->value > (*stack_a)->next->next->value && (*stack_a)->next->value < (*stack_a)->next->next->value)
            ra(stack_a);
        else if ((*stack_a)->value > (*stack_a)->next->next->value && (*stack_a)->next->value > (*stack_a)->next->next->value)
        {
            sa(stack_a);
            rra(stack_a);
        }
    }
    else if ((*stack_a)->value < (*stack_a)->next->value)
    {
        if ((*stack_a)->value < (*stack_a)->next->next->value)
        {
            sa(stack_a);
            ra(stack_a);
        }
        else
            rra(stack_a);
    }
}

void sort_four(t_list **stack_a, t_list **stack_b)
{
    int i = 0;
    while(i < 4)
    {
        if ((*stack_a)->pos > 2)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
    sort_three(stack_a);
    pa(stack_a, stack_b);
    ra(stack_a);
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
    int i = 0;
    while(i < 5)
    {
        if ((*stack_a)->pos > 2)
        {
            pb(stack_a, stack_b);
        }
        else
        {
            ra(stack_a);
        }
        i++;
    }
    sort_three(stack_a);
    sort_two(stack_b);
    pa(stack_a, stack_b);
    ra(stack_a);
    pa(stack_a, stack_b);
    ra(stack_a);
}