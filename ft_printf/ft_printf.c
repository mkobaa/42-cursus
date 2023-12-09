#include "ft_printf.h"

int handle_format_specifier(const char *format, va_list args, int *count) {
    if (format[1] == 's')
        *count += ft_putstr(va_arg(args, char *));
    else if (format[1] == 'c')
        *count += ft_putchar(va_arg(args, int));
    else if (format[1] == 'd' || format[1] == 'i')
        *count += ft_putnbr(va_arg(args, int));
    else if (format[1] == 'u')
        *count += ft_putunsigned(va_arg(args, unsigned long));
    else if (format[1] == 'X')
        *count += ft_printhexmaj(va_arg(args, int));
    else if (format[1] == 'x')
        *count += ft_printhex(va_arg(args, int));
    else if (format[1] == 'p') {
        *count += ft_putstr("0x");
        *count += ft_printhexmaj((unsigned long)va_arg(args, void *));
    }
    else if (format[1] == '%')
        *count += ft_putchar('%');

    return 2;
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    int i = 0;

    while (format[i])
	{
        if (format[i] == '%' && format[i + 1] != 0) {
            i += handle_format_specifier(format + i, args, &count);
        } else {
            ft_putchar(format[i]);
            count++;
            i++;
        }
    }

    va_end(args);
    return count;
}

int main()
{
	int d = 4842;
	ft_printf("%x\n", d);
	printf("%x", d);
}