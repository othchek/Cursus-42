/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:18:08 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/14 05:51:50 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] >= len)
	{
		if (haystack[i] == needle[j])
			return ((char *)&haystack[i]);
			i++;
	}
	if (haystack[i] != needle[j])
		return (0);
	return (0);
}

int main()
{
	char haystack[] = "pxazzay";
	char needle[] = "h";
	printf("%s\n", ft_strnstr(haystack, needle, 3));
	printf("%s\n", strnstr(haystack, needle, 3));
	
}
