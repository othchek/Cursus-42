/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:00:02 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/22 12:05:01 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conditions(va_list ap, char c)
{
	int	i;

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
		i += write(1, "0x", 2);
		i += ft_putadd(va_arg(ap, unsigned long long));
	}	
	if (c == 'u')
		i += ft_print_unsigned(va_arg(ap, unsigned int));
	if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j += ft_conditions(ap, str[i + 1]);
			i++;
		}
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (j);
}

// int main()
// {
// 	char s2[] = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
// 	printf("%d\n", ft_printf(" %s\n %s\n %s\n %s\n %s\n", " - ", "", "4", "", s2));
// }