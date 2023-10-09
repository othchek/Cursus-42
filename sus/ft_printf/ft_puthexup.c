/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:45:31 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/22 18:57:56 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(size_t i)
{
	char	*h;

	h = "0123456789ABCDEF";
	if (i < 16)
		ft_putchar(h[i]);
	if (i >= 16)
	{
		ft_puthexup(i / 16);
		ft_puthexup(i % 16);
	}
	return (ft_countlen_x(i));
}
