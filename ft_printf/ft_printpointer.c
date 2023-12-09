#include "ft_printf.h"

int handle_pointer(const char *format, va_list args, int *count) {
    void *ptr = va_arg(args, void*);

    if (ptr == NULL) {
        *count += ft_putstr("(nil)");
        return 5; // Return the number of characters printed for "(nil)"
    }

    *count += ft_putstr("0x");
    *count += ft_printhexmaj((unsigned long)ptr);

    return 2 + ft_printhexmaj((unsigned long)ptr);
}