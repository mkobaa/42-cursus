/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 02:16:05 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/07 02:47:38 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (len > ft_strlen(s))
	{
		return (NULL);
	}
	if (!ptr)
	{
		return (NULL);
	}
	while (s[start] != 0 && i < len)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = 0;
	return ptr;
}
