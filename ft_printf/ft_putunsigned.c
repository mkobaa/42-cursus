#include "ft_printf.h"
#include <limits.h>  // Include for ULONG_MAX

int ft_putunsigned(unsigned long n) {
    int length = 0;

    if (n > ULONG_MAX)
    {
        length += ft_putnbr(4294961812);
    } else if (n < 10)
    {
        length += ft_putchar(n + '0');
    } else {
        length += ft_putnbr(n / 10);
        length += ft_putnbr(n % 10);
    }

    return length;
}
