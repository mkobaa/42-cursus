#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    int i = 0;
    
    if (write(1, "0", 0))
        return (-1);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            if (format[i] == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd' || format[i] == 'i')
                count += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += ft_putnbr((unsigned long)num);
            }
            else if(format[i] == 'x')
                count += ft_putlowerhex(va_arg(args, unsigned int));
            else if(format[i] == 'X')
                count += ft_putupperhex(va_arg(args, unsigned int));
            else if(format[i] == 'p')
                count += ft_putptr((void *)va_arg(args, void *));
            else if(format[i] == '%')
                count +=ft_putchar('%');
            i++;
        }
        else
        {
            ft_putchar(format[i]);
            i++;
            count++;
        }
    }
    va_end(args);
    return count;
}

// int main()
// {
//     printf("\n%d\n", ft_printf("%u", 0));
//     printf("\n%d\n", printf("%u", 0));
// }