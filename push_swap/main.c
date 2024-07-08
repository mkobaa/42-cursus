#include "push_swap.h"

int all_checks(char *s, int ac)
{
	if (ac == 1)
        return 0;
	if (!check_number(s) || !check_sign(s) ||
				!check_null(s) || !check_full_spaces(s) || !just_sign(s) || !ft_atoi(s))
		return 0;
	return 1;
}


int main(int ac, char *av[])
{
    // int i = 1;
    // int number = 1;
	// int *tab;
	// int tab_i = 0;
	// int size = 0;
    

	// while (number < ac)
	// {
	// 	char **splitted = ft_split(av[i], ' ');
	// 	int split_i = 0;
	// 	int word_count = count_words(av[i], ' ');
	// 	while (split_i < word_count)
	// 	{
	// 		if (!all_checks(splitted[split_i], ac))
	// 		{
	// 			ft_puterror();
	// 			return 0;
	// 		}
	// 		split_i++;
	// 	}
	// 	if (!all_checks(av[i], ac))
	// 	{
	// 		ft_puterror();
	// 		return 0;
	// 	}
	// 	number++;
	// 	i++;
	// }
	// number = 1;
	// i = 1;
    // while (number < ac)
	// {
	// 	tab = malloc(number * sizeof(int));
	// 	char **splitted = ft_split(av[i], ' ');
	// 	int split_i = 0;
	// 	int word_count = count_words(av[i], ' ');

	// 	while (split_i < word_count)
	// 	{
	// 		tab[tab_i] = ft_atoi(splitted[split_i]);
	// 		split_i++;
	// 		tab_i++;
	// 		size++;
	// 	}
	// 	split_i = 0;
	// number++;
	// i++;
	// }
	int tab[3] = {1, 2, 1};
	if (!check_duplicates(tab, 3))
	{
		ft_puterror();
		return 0;
	}
}


