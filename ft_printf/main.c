#include <stdio.h>
#include "ft_printf.h"

int main()
{
    int c = 1337;
    ft_printf("% %c %s %d %i %p %x %X %h %% %\n", 'c', "string", 1337, 1337, &c, 1337, 1337, c);
}