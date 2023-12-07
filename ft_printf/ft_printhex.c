#include "ft_printf.h"

void ft_printhexmaj(int num)
{
    char hexDigits[] = "0123456789ABCDEF";

    if (num > 0) {
        ft_printhexmaj(num / 16);
        putchar(hexDigits[num % 16]);
    }
}

void ft_printhex(int num)
{
    char hexDigits[] = "0123456789abcdef";

    if (num > 0) {
        ft_printhex(num / 16);
        putchar(hexDigits[num % 16]);
    }
}