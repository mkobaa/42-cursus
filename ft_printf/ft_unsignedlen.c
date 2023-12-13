/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:21:10 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/13 01:15:01 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsignedlen(long nbr)
{
    int count;
    
    count = 0;
    if (nbr < 0)
        count = 10;
    if (nbr == 0)
    {
        return 1;
    }
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    
    return count;
        
    return (count);
}