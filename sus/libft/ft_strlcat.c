/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:36:03 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/21 09:26:07 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		srclen;
	int		dstlen;

	j = 0;
	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	while (dst[j] != '\0')
		j++;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srclen + dstlen);
}
