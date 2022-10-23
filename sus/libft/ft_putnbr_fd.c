/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:00:16 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/23 10:52:33 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483647)
		write(fd, "-2147483647", 11);
	else if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putchar(n * (-1));
	}
	else
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
}
