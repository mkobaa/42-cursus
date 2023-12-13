#include "ft_printf.h"

int	ft_putlowerhex(unsigned long num)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_putlowerhex(num / 16);
	}
	ft_putchar(hex_digits[num % 16]);
	count++;
	return (count);
}

int	ft_putupperhex(unsigned long num)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += ft_putupperhex(num / 16);
	}
	ft_putchar(hex_digits[num % 16]);
	count++;
	return (count);
}
