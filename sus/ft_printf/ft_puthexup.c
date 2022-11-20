/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:45:31 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/20 20:52:52 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putnbrx(size_t i)
{
    char    *h;

    h = "0123456789ABCDEF";
    if (i < 16)
        ft_putchar(h[i]);
    if (i >= 16)
    {
        ft_putnbrx(i / 16);
        ft_putchar(h[i % 16]);
    }
    return (countlen(i));
}
