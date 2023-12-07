#include "ft_printf.h"
#include <limits.h>  // Include for ULONG_MAX

void ft_putunsigned(unsigned long n)
{
    if (n > ULONG_MAX)  // Handle case where n is larger than ULONG_MAX
    {
        ft_putnbr(4294961812);
    }
    else if (n < 10)
    {
        ft_putchar(n + '0');
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}
