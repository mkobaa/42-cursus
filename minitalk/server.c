#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include "ft_printf/ft_printf.h"



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

void	handler(int signum, siginfo_t *info, void *context)  
{
    static char str[9];
    static int i = 0;
    static pid_t pid;

    if (signum == SIGUSR1 || signum == SIGUSR2)
    {
        (void)context;
        if (pid != info->si_pid)
        {
            i = 0;
            pid = info->si_pid;
        }
        if (signum == SIGUSR1) 
            str[i] = '0';
        else if (signum == SIGUSR2) 
            str[i] = '1';
        i++;
        if (i == 8)
        {
            ft_printf("%c", convert(str));
            i = 0;
        }
    }
}

int main()
{
    int i;
    struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("The PID is : %d\n", getpid());
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);
	while (1)
	{
        pause();
	}
}
