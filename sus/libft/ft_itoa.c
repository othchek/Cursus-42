/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:52:44 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/26 17:57:08 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static	int	count(long int nmb)
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

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;
	long	nb;

	nb = (long)n;
	i = count(nb);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ptr[i--] = '\0';
	if (nb == 0)
		ptr[0] = nb + '0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = nb * -1;
	}
	while (nb != 0)
	{
		ptr[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (ptr);
}

// int main()
// {
//     printf("%s", ft_itoa(0));
// }   