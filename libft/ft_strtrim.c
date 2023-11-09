/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:13:12 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/08 17:15:30 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	ptr = (char *)malloc (sizeof(char) * (j - i + 2));
	if (!ptr)
		return (NULL);
	while (i <= j)
	{
		ptr[k] = s1[i];
		k++;
		i++;
	}
	ptr[k] = 0;
	return (ptr);
}

// int main()
// {
//     char *s1 = "";
//  	char *s2 = "";
//  	char *ret = ft_strtrim("", "");
//  	printf("%s", ret);
// }