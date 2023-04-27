/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:51:46 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/25 16:52:03 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	char		*str;
	char		*strr;
	int			len;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)s1;
	strr = (char *)s2;
	len = (ft_strlen(str) + ft_strlen(strr) + 1);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, len);
	ft_strlcat(ptr, strr, len);
	return (free(str), ptr);
}
