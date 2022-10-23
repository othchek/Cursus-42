/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:17:44 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/22 17:59:28 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	findr(char str, const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (str == c[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*l;

	if (!s1)
		return (0);
	j = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] != '\0' && findr((char)s1[i], set))
		i++;
	while (j >= 0 && findr((char)s1[j], set))
		j--;
	l = ft_substr(s1, i, j - i + 1);
	return (l);
}

// int main()
// {
//     char name[] = "ABCCCCDSABCCFRABBCCAAA";
//     char namee[] = "ABC";
//     printf("%s", ft_strtrim(name, namee));
// }