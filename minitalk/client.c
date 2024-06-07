#include "minitalk.h"

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
		if (rslt < max && sign == -1)
			return (0);
		if (rslt < max && sign == 1)
			return (-1);
		i++;
		max = rslt;
	}
	return ((int)(sign * rslt));
}

char ascii_to_binary(char *s)
{
	char *binary;
	int i;
	int l;
	int j;
	int k;

	i = 0;
	while (s[i])
	{
		j = s[i] / 2;
		while (j != 0)
		{
			k = s[i] % 2;
			binary[l] = k;

		}
		i++;
	}

	

}

int main(int argc, char *argv[])
{
	if (argc == 3 && ft_atoi(argv[1]))
	{
		int pid = ft_atoi(argv[1]);
		printf("%d", 'A' % 2);
	}
	else
		printf("%s", "please add the PID first then the text to send");
}