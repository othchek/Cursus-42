/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:22:56 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/18 13:36:59 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*res;
	char	*str;	

	res = (char *)dst;
	str = (char *)src;
	i = 0;
	if (str == 0 && res == 0)
		return (0);
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
