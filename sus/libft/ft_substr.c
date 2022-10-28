/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:51:14 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/27 18:47:06 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	ptr = malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	if (start >= i)
		return (ptr);
	while (s[j] != '\0' && j < len)
	{
		ptr[j] = s[start];
		start++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
