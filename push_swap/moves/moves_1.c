#include "../push_swap.h"

void sa(t_list **stack_a)
{
    int tmp = 0;
    tmp = (*stack_a)->value;
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->next->value = tmp;
    printf("sa\n");
}

void sb(t_list **stack_b)
{
    int tmp = 0;
    tmp = (*stack_b)->value;
    (*stack_b)->value = (*stack_b)->next->value;
    (*stack_b)->next->value = tmp;
    printf("sb\n");
}

void ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sa(stack_b);
    printf("ss\n");
}

void ra(t_list **stack_a)
{
    if (ft_lstsize(*stack_a) < 2)
        return;
    t_list *first = *stack_a;
    t_list *temp = *stack_a;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = first;
    *stack_a = first->next;
    first->next = NULL;
    printf("ra\n");
}

void rb(t_list **stack_b)
{
    t_list *first = *stack_b;
    t_list *temp = *stack_b;
    if (ft_lstsize(*stack_b) < 2)
        return;
    while (temp->next)
        temp = temp->next;
    temp->next = first;
    *stack_b = first->next;
    first->next = NULL;
    printf("rb\n");
}