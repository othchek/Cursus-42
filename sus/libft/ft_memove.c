/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:22:56 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/17 11:19:07 by otchekai         ###   ########.fr       */
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
	while (str[i] != '\0' && i < n)
	{
		res[i] = str[i];
		i++;
	}
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
	return (str);
}
