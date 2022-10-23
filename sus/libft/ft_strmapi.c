/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:35:20 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/23 11:14:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ptr;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s) + 1;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (0);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main()
// {
// 	char *re = "PAPAY";
// 	char *s = ft_strmapi(re, ftolower); 
// 	printf("%s", s);
// }