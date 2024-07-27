/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 01:14:11 by mkobaa            #+#    #+#             */
/*   Updated: 2024/07/27 05:03:04 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_puterror(void)
{
	write(2, "Error", 5);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	check_extension(char *s)
{
	int		i;
	char	*extension;

	extension = ".ber";
	i = 0;
	while (i < (ft_strlen(s) - 4))
		i++;
	if (ft_strncmp(&s[i], extension, 4))
		return (1);
	return (0);
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
