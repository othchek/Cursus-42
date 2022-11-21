/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putheX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:52:00 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/21 13:16:08 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_countlen_x(long int nmb)
{
	int	i;

	i = 0;
	if (nmb < 0 || nmb == 0)
		i++;
	while (nmb != 0)
	{
		nmb /= 16;
		i++;
	}
	return (i);
}

int ft_puthex(size_t i)
{
	char    *h;

	h = "0123456789abcdef";
	if (i < 16)
		ft_putchar(h[i]);
	if (i >= 16)
	{
		ft_puthex(i / 16);
		ft_putchar(h[i % 16]);
	}
	return (ft_countlen_x(i));
}
