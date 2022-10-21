/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:33:06 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/21 13:46:34 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		srclen;

	i = 0;
	srclen = strlen(src);
	if(dstsize == 0)
		return (srclen);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// int main()
// {
//  	char name[0] = "";
//  	char namee[20] = "kfotlane";
//  	printf("%zu, %s" , ft_strlcpy(name, namee, 0), name);
// }