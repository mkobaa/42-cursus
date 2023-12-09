#include "ft_printf.h"


int ft_putnbr(long n)
{
    int length = 0;

    if (n < 0) {
        if (n == -2147483648) {
            write(1, "-2147483648", 11);
            return 11;
        }
        n = -n;
        length += ft_putchar('-');
    }

    if (n < 10) {
        length += ft_putchar(n + '0');
        return length;
    }

    length += ft_putnbr(n / 10);
    length += ft_putnbr(n % 10);

    return length;
}
