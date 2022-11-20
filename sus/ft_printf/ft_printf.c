/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/19 22:40:22 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char conditions(char c)
{
	va_list ap;
	
	va_start(ap, str);
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int));
	if (c == 'x')
		ft_putnbrx(va_arg(ap, unsigned int));
	
}

int	ft_printf(const char *str, ...)
{
	
}printf("nkjnfgndfgndjg%d jblkfjo %f", d,r);