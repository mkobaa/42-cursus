/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:46:33 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/07 00:46:16 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] != 0 && len >= ft_strlen(needle))
	{
		if (ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			return ((char *)&haystack[i]);
		}
		i++;
		len--;
	}
	return (0);
}
