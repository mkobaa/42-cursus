#include "../push_swap.h"

int calculate_args(int ac, char *av[])
{
    int i = 1;
    int number = 1;
    int args = 0;

    while (number < ac)
	{
        char **splitted = ft_split(av[i], ' ');
        int split_i = 0;

        while (splitted[split_i])
		{
            args++;
            split_i++;
        }
        free_splitted(splitted);
        number++;
        i++;
    }

    return args;
}

void process_arguments(int ac, char *av[], int *tab)
{
    int i = 1;
    int number = 1;
    int tab_i = 0;

    while (number < ac)
	{
        char **splitted = ft_split(av[i], ' ');
        int split_i = 0;
        int word_count = count_words(av[i], ' ');

        while (split_i < word_count)
		{
            tab[tab_i] = ft_atoi(splitted[split_i]);
            split_i++;
            tab_i++;
        }
        free_splitted(splitted);
        number++;
        i++;
    }
}


int check_arguments(int ac, char *av[])
{
    int i = 1;
    int number = 1;

    while (number < ac)
	{
        char **splitted = ft_split(av[i], ' ');
        int split_i = 0;
        int word_count = count_words(av[i], ' ');

        while (split_i < word_count)
		{
            if (!all_checks(splitted[split_i], ac))
			{
                ft_puterror();
                free_splitted(splitted);
                return 0;
            }
            split_i++;
        }
        if (!all_checks_2(av[i], ac))
		{
            ft_puterror();
            free_splitted(splitted);
            return 0;
        }
        free_splitted(splitted);
        number++;
        i++;
    }
    return 1;
}

void free_splitted(char **splitted)
{
    int j = 0;
    while (splitted[j] != NULL)
	{
        free(splitted[j]);
        j++;
    }
    free(splitted);
}

int check_sorted(int *tab, int size)
{
    int i;
    i = 0;
    while(i < size - 1)
    {
        if (tab[i] > tab[i + 1])
            return 1;
        i++;
    }
    return 0;
}