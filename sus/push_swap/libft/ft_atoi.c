/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:30:41 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/25 16:37:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	size_t			i;
	long long		k;
	long long		sign;

	i = 0;
	k = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (i == ft_strlen(str))
		ft_error("Error\nNot Valid");
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	return (k * sign);
}
