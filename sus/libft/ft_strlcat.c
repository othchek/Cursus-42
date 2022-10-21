/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:36:03 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/21 15:31:53 by otchekai         ###   ########.fr       */
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
	if (srclen > dstlen)
		return(srclen + dstsize);
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

// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char a[20] = "";
// 	char *b = "the cake is a lie !\0I'm hidden lol\r\n";
// 	char c[100] = "there is no stars in the sky";
// 	printf("%lu    :   %s\n", ft_strlcat(c, b, strlen("the cake is a lie !\0I'm hidden lol\r\n")), c);
// 	printf("%lu    :   %s\n", strlcat(c, b, strlen("the cake is a lie !\0I'm hidden lol\r\n")), c);
// 	printf("%lu\n", strlen("the cake is a lie !\0I'm hidden lol\r\n"));
// 	printf("%lu", strlen("there is no stars in the sky"));
// }