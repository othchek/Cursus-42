/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/20 19:44:39 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char ft_conditions(va_list ap, char c)
{
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int));
	if (c == 'x')
		ft_putnbrx(va_arg(ap, unsigned int));
	if (c == 'X')
		ft_putnbrx(va_arg(ap, unsigned int));
	if (c == 'p')
		ft_putadd(va_arg(ap, unsigned long long));
	if (c == 'u')
		(va_arg(ap, unsigned int));
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
