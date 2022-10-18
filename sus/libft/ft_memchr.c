/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:24:22 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/18 16:04:24 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (0);
}
