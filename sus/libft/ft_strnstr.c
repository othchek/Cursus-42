/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:18:08 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/24 08:58:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	j = 0;
	if (len == 0)
		return (0);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] == needle[j])
	{
		
		return ((char *)&haystack[i] + k);
		i++;
		k++;
	}
	if (haystack[i] != needle[j])
		return (0);
	return (0);
}
