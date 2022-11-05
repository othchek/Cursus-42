/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:29:56 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/05 09:57:18 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char *str, char c)
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

static void	allfree(char **str, int k)
{
	while (k)
	{
		free(str[k]);
		k--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc((countwords((char *)s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (k < countwords((char *)s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		ptr[k] = ft_substr(s, j, i - j);
		if (!ptr[k])
			return (allfree(ptr, k), NULL);
		k++;
	}
	return (ptr[k] = NULL, ptr);
}
