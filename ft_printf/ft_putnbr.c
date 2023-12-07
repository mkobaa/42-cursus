#include "ft_printf.h"

void    ft_putnbr(long n)
{
        if (n < 0)
        {
                if (n == -2147483648)
                {
                        write(1, "-2147483648", 11);
                        return ;
                }
                n = -n;
                ft_putchar('-');
        }
        if (n < 10)
        {
                ft_putchar(n + '0');
                return ;
        }
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
}
