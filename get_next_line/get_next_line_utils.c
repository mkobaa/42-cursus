/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:36:03 by mkobaa            #+#    #+#             */
/*   Updated: 2024/03/13 00:30:09 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s2 && !s1)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		ptr[i++] = s2[j++];
	ptr[i] = 0;
	return (free(s1), ptr);
}


int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (1);
	return (0);
}

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size;
	size_t i;

	i = 0;
    total_size = count * size;
    if (count != 0 && total_size / count != size)
        return NULL;
    ptr = malloc(total_size);
    if (!ptr)
        return NULL;
    while (i < total_size)
	{
        ((unsigned char *)ptr)[i] = '\0';
        i++;
    }
    return ptr;
}
