/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:22:56 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/17 11:16:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*res;
	char	*str;	

	res = (char *)dst;
	str = (char *)src;
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		res[i] = str[i];
		i++;
	}
	while (i < len)
	{
		res[i] = '\0';
		i++;
	}
	return (str);
}
