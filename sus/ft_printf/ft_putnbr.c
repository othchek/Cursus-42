/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:43:01 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/19 21:43:29 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count(long int nmb)
{
	int	i;

	i = 0;
	if (nmb < 0 || nmb == 0)
		i++;
	while (nmb != 0)
	{
		nmb /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
}