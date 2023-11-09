/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:39:21 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/09 18:33:51 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		if (dstsize - 1 < src_len)
		{
			i = dstsize - 1;
		}
		else
		{
			i = src_len;
		}
		ft_memcpy(dst, src, i);
		dst[i] = '\0';
	}
	return (src_len);
}

// #include <stdio.h>
// int main()
// {
// 	char h[] = "hello world !";
// 	char *d;
// 	printf("%zu",ft_strlcpy(h, d, 20));
// }