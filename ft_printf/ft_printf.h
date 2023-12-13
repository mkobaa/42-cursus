#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(char c);
int ft_putlowerhex(unsigned long num);
int ft_putnbr(long nb);
int ft_putstr(char *str);
void ft_putunsigned(long nb);
int ft_putupperhex(unsigned long num);
int ft_unsignedlen(long nbr);
int ft_putptr(void *ptr);

#endif