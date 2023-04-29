/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:51:46 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 17:00:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
