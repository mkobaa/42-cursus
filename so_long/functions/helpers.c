/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:25:28 by mkobaa            #+#    #+#             */
/*   Updated: 2024/08/01 02:28:36 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static int	count_n(int count)
{
	int	index;

	index = 0;
	if (count <= 0)
		index++;
	while (count)
	{
		count = count / 10;
		index++;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	int		index;
	int		size;
	char	*str;

	index = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_n(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n != 0)
	{
		str[size - index++] = ((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	if (!ptr)
		return (NULL);
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	flood_fill(t_list *d, int x, int y)
{
	if (d->map_copy[y][x] == 'E')
		d->map_copy[y][x] = 'R';
	if (y < 0 || y >= d->lines || x < 0 || x >= d->columns)
		return ;
	if (d->map_copy[y][x] == '1' || d->map_copy[y][x] == 'R')
		return ;
	d->map_copy[y][x] = 'R';
	flood_fill(d, x + 1, y);
	flood_fill(d, x - 1, y);
	flood_fill(d, x, y + 1);
	flood_fill(d, x, y - 1);
}
