/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:40:39 by mkobaa            #+#    #+#             */
/*   Updated: 2024/01/11 17:08:29 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strlen(const char *str)
{
    int i;
    i = 0;
	if (str)
    while (str[i] != 0)
    {
        i++;
    }
    return (i);
}
int ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] != (char)c)
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	if (s1)
		while (s1[i] != 0)
		{
			ptr[i] = s1[i];
			i++;
		}
	if (s2)
	while (s2[j] != 0)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!ptr)
	{
		return (NULL);
	}
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
	{
		return ((void *) dst);
	}
	if (dst == 0 && src == 0)
	{
		return (0);
	}
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
