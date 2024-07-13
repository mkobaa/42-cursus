#include "../push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_b) == 0)
        return;

    t_list *first_b = *stack_b;
    *stack_b = first_b->next;

    first_b->next = *stack_a;
    *stack_a = first_b;
    printf("pa\n");
}


void pb(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) == 0)
        return;

    t_list *first_a = *stack_a;
    *stack_a = first_a->next;

    first_a->next = *stack_b;
    *stack_b = first_a;
    printf("pb\n");
}
void rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    printf("rr\n");
}

void rra(t_list **stack_a)
{
    if (ft_lstsize(*stack_a) < 2)
        return;
    t_list *first = *stack_a;
    t_list *last = (*stack_a)->next;
    while (last->next)
    {
        first = first->next;
        last = last->next;
    }
    first->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    printf("rra\n");
}

void rrb(t_list **stack_b)
{
    if (ft_lstsize(*stack_b) < 2)
        return;
    t_list *first = *stack_b;
    t_list *last = (*stack_b)->next;
    while (last->next)
    {
        first = first->next;
        last = last->next;
    }
    first->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    printf("rrb\n");
}
