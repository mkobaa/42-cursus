#include "../push_swap.h"
#include <limits.h>

void to_top(t_list **stack_a, int value)
{
    if ((*stack_a)->index == value ) return;
    while ((*stack_a)->index != value)
    {
        ra(stack_a);
        
    }
}
void push_to_b(int size, t_list **stack_a, t_list **stack_b)
{
    t_list *node = *stack_a;
    int min = 0;
    int moyenne = 0;
    int i = 0;
    while(*stack_a)
    {

        while (node)
        {
            if (node->pos == 19)
            {
                min = node->value;
            }
            if (node->pos == 19)
            {
                moyenne = node->value;
            }
            node = node->next;
        }
        while (i < 20)
        {
            node = *stack_a;
            while(node)
            {
                if (node->value < min)
                {
                    to_top(stack_a, node->index);
                    break ;
                }
                node = node->next;
            }
            pb(stack_a, stack_b);
            i++;
        }
        add_positions(stack_a);
        i = 0;
        node = *stack_a;
    }
}


void push_to_a(int size, t_list **stack_a, t_list **stack_b)
{
    t_list *node = *stack_b;
    while (node)
    {
        
    }
}