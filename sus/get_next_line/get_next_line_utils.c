/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:38 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/29 17:15:30 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)(c))
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*l;
	int			u;
	int			j;
	int			slenght;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	slenght = ft_strlen(s1) + ft_strlen(s2);
	u = 0;
	j = 0;
	l = malloc((slenght + 1) * sizeof(char));
	if (!l)
		return (NULL);
	while (s1[u] != '\0')
	{
		l[u] = s1[u];
		u++;
	}
	while (s2[j] != '\0')
		l[u++] = s2[j++];
	l[u] = '\0';
	free(s1);
	return (l);
}

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (s1[i])
	{
		str[i] = s1[i];
		i--;
	}
	return (str);
}
