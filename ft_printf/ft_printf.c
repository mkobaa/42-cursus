#include "ft_printf.h"


void ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int i;

    i = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] != 0)
        {
            i++;
            if (format[i] == 's')
                ft_putstr(va_arg(args, char *));
            else if (format[i] == 'c')
                ft_putchar(va_arg(args, int));
            else if (format[i] == 'd')
                ft_putnbr(va_arg(args, int));
            else if (format[i] == 'i')
                ft_putnbr(va_arg(args, int));
            else if (format[i] == 'u')
                ft_putunsigned(va_arg(args, unsigned long));
            else if (format[i] == 'X')
                ft_printhexmaj(va_arg(args, int));
            else if (format[i] == 'x')
                ft_printhex(va_arg(args, int));
            else if (format[i] == '%')
                ft_putchar('%');
            else if (format[i] == 'p')
            {
                ft_putstr("0x");
                ft_printhex((uintptr_t)va_arg(args, void *));
            }    
        }
        else 
            ft_putchar(format[i]);
        i++;
    }
    va_end(args);
}

int main()
{
    char *ptr = "str";
    ft_printf("%%%%\n", &ptr);
    printf("%p", &ptr);
}