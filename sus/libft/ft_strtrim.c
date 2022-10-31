/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:17:44 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/31 13:13:05 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findr(char str, const char *c)
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
	int	i;
	int	j;

	if (!s1)
		return (0);
	j = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] != '\0' && findr((char)s1[i], set))
		i++;
	while (j >= 0 && findr((char)s1[j], set))
		j--;
	if (j == -1)
		return (ft_substr(s1, j, 0));
	return (ft_substr(s1, i, j - i + 1));
}

// int main()
// {
//     char *s1 = "          ";
//     char *set = " ";
//     printf("%s", ft_strtrim(s1, set));
// }