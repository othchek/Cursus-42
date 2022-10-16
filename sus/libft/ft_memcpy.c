/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:06:54 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/16 17:02:22 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int		i;
	char	*str;
	char	*res;

	str = (char *) src;
	res = (char *) dst;
	i = 0;
	while ((str[i] != '\0') && i < n)
	{
		res[i] = str[i];
		i++;
	}
	while (i < n)
	{
		res[i] = '\0';
			i++;
	}
	return (res);
}
