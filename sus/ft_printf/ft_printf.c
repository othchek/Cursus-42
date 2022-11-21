/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/21 14:46:12 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char ft_conditions(va_list ap, char c)
{
	int i;

	i = 0;
	if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(ap, int));
	if (c == 'x')
		i += ft_puthex(va_arg(ap, unsigned int));
	if (c == 'X')
		i += ft_puthexup(va_arg(ap, unsigned int));
	if (c == 'p')
	{
		write(1, "0x", 2);
		i += ft_putadd(va_arg(ap, unsigned long long));
	}	
	if (c == 'u')
		i += (va_arg(ap, unsigned int));
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int i;
	
	i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			ft_conditions(ap, str[i + 1]);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
