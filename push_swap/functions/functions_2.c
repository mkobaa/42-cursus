#include "../push_swap.h"

int just_sign(char *s)
{
    int i; 

    i = 0;
    while (s[i])
        i++;
    if (i == 1)
    {
        if (s[0] == '+' || s[0] == '-')
            return 0;
    }
    return 1;
}

static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	rslt;
	int		i;
	int		sign;
	long	max;

	sign = 1;
	i = skip_spaces(str);
	rslt = 0;
	max = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt = rslt * 10 + (str[i] - '0');
        if (str[i] == '-' || str[i] == '+')
            return (0);
		if (rslt < max && sign == -1)
			return (0);
		if (rslt < max && sign == 1)
			return (-1);
		i++;
		max = rslt;
	}
	return ((int)(sign * rslt));
}