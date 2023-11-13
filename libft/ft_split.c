/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:15:08 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/13 15:00:06 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			k++;
			j = 0;
		}
	}
	return (k);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_fill(char **str, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i] != 0)
		{
			str[j] = malloc(sizeof(char) * (word_len(s + i, c) + 1));
			if (str[j] == 0)
				return (ft_free(str, j));
			while (s[i] != c && s[i] != 0)
				str[j][k++] = s[i++];
			str[j++][k] = '\0';
			k = 0;
		}
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	str = ft_fill(str, s, c);
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
//     char const *input_string = "Hello World,Split,Me";
//     char c = ',';
//     char **result = ft_split(input_string, c);
//     int i = 0;
//     while (result[i] != NULL)
//     {
//         printf("%s\n", result[i]);
//         i++;
//     }
//     i = 0;
//     while (result[i] != NULL)
//     {
//         free(result[i]);
//         i++;
//     }
//     free(result);

//     return 0;
// }
