#include "../push_swap.h"

void sort_two(t_list **stack_a)
{
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

void sort_five(t_list **stack_a, t_list **stack_b)
{
    
}