/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:03:25 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/29 20:28:37 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
