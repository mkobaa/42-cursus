/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:41:07 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/19 17:00:52 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*srcc;

	dest = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	index = 1;
	if (dst == 0 && src == 0)
		return (0);
	if (src < dst)
	{
		while (index <= len)
		{
			dest[len - index] = srcc[len - index];
			index++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
