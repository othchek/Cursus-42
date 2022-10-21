/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:51:46 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/21 17:40:44 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	char		*str;
	char		*strr;
	int			len;

	str = (char *)s1;
	strr = (char *)s2;
	len = ft_strlen(str) + ft_strlen(strr);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, strr, len);
	ft_strlcpy(ptr + ft_strlen(str), str, len);
	return (ptr);
}

// int main()
// {
// 	char s1[] = "bachar";
// 	char s2[] = "zamel";

// 	printf("%s", ft_strjoin(s1, s2));
// }
