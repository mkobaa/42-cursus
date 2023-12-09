#include "ft_printf.h"

int ft_printhexmaj(int num)
{
    char hexDigits[] = "0123456789ABCDEF";
    int length = 0;

    if (num == 0) {
        ft_putchar(hexDigits[0]);
        return 1;
    }

    if (num > 0) {
        length += ft_printhexmaj(num / 16);
        ft_putchar(hexDigits[num % 16]);
        length++;
    }

    return length;
}

int ft_printhex(int num)
{
    char hexDigits[] = "0123456789abcdef";
    int length = 0;

    if (num == 0) {
        ft_putchar(hexDigits[0]);
        return 1;
    }

    if (num > 0) {
        length += ft_printhex(num / 16);
        ft_putchar(hexDigits[num % 16]);
        length++;
    }

    return length;
}
