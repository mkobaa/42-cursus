
#include <stdio.h>
#include <unistd.h>
#include "minitalk.h"
#include "ft_printf/ft_printf.h"

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include "ft_printf/ft_printf.h"

int zero_one(char s)
{
	if (s == '0')
		return 0;
	else
		return 1;
}

int power(int i, int j)
{
    int result = 1;
    while (j > 0)
    {
        result *= i;
        j--;
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
int convert(char *s)
{
    int i;
    int j;
    int number;
    int rslt;

    rslt = 0;
    i = 7;
    j = 0;
    while (i >= 0)
	{
        number = s[i] - '0';
        rslt = rslt + (number * (1 << j));
        i--;
        j++;
    }
    return rslt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


void handler(int signum)
{
    static char str[9];
    static int i = 0;

    if (signum == SIGUSR1 || signum == SIGUSR2)
    {
        if (i == 8)
        {
            ft_printf("%c", convert(str));
            i = 0;
        }
        if (signum == SIGUSR1) 
            str[i] = '0';
        else if (signum == SIGUSR2) 
            str[i] = '1';
        i++;
    }
}

int main()
{

	int pid = getpid();
	ft_printf("The PID is : %d\n", pid);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
	{
		pause();
	}


}
