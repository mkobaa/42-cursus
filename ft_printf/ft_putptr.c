/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkobaa <mkobaa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:21:47 by mkobaa            #+#    #+#             */
/*   Updated: 2023/12/12 20:46:06 by mkobaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    unsigned long ptr_value = (unsigned long)ptr;
    write(1, "0x", 2);
    return 2 + ft_putlowerhex(ptr_value);
}