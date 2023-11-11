/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/11 22:45:27 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const	char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
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
	while (s2[j])
		l[u++] = s2[j++];
	l[u] = '\0';
	free(s1);
	return (l);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*gnl;
	int		pr;
	int		sec;

	if (!s1)
		return (NULL);
	sec = 0;
	i = ft_strlen(s1);
	gnl = malloc(i + 1);
	if (!gnl)
		return (NULL);
	pr = 0;
	while (s1[sec])
		gnl[pr++] = s1[sec++];
	gnl[pr] = '\0';
	return (gnl);
}

size_t ft_numlen(int num)
{
    size_t len;

	len = 1;
    while (num /= 10)
        len++;
    return len;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	sign;

	i = 0;
	k = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	return (k * sign);
}