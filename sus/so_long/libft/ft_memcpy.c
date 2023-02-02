/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:06:54 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/17 20:08:14 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*res;

	str = (char *) src;
	res = (char *) dst;
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
