/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:13:12 by mkobaa            #+#    #+#             */
/*   Updated: 2023/11/07 17:58:23 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char *ptr;
    char srtnstr;

    ptr = (char *)malloc(sizeof(char) * (ft_strlen(set) + 1));
    if (!ptr)
    { 
        return (NULL);
    }
    ptr = stnstr
}