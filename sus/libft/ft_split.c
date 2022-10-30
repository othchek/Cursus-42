/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:29:56 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/30 10:55:31 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	countwords(char *str, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			wc++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	ptr = (char **)malloc(sizeof(char *) * (countwords((char *)s, c) + 1));
	if (!ptr)
		return (NULL);
	while (k < countwords((char *)s, c))
	{
		k++;
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		ptr[k] = ft_substr(s, j, i - j);
	}
	return (ptr[k] = NULL, ptr);
}

// int main(void)
// {
//     char str[] = "..hhhh....hhhh......hhhh...";
//     printf("%d", ft_split(str, '.'));
// }