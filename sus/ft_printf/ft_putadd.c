/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:38:04 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/22 09:16:27 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long long i)
{
	char	*h;

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
