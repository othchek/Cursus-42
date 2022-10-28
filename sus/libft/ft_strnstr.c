/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:18:08 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/28 14:07:45 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!haystack && !len)
		return (NULL);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		while (i < len && needle[j] == haystack[i])
		{
			j++;
			i++;
			if (needle[j] == '\0')
				return ((char *)haystack + k);
		}
		j = 0;
		i++;
		k++;
	}
	return (0);
}

// int main()
// {
// 	char hay [] = "lorem ipsum lodorr";
// 	char ned [] = "lodorr"
// }