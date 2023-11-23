/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:40:11 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/23 11:31:50 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_whitespaces(char *str)
{
	if (!str)
		return ;
	while (*str && (*str == ' ' || *str == '\t'
			|| *str == '\n' || *str == '\r'))
		str++;
}

void	width_check(t_cub *cub)
{
	int	index;
	int	j;

	index = 0;
	cub->map_width = 0;
	while (cub->map && cub->map[index])
	{
		j = 0;
		while (cub->map[index][j])
		{
			if (cub->map[index][j] == ' ' 
			|| cub->map[index][j] == '\t' || cub->map[index][j] == '\r')
				j++;
			j++;
		}
		if (j > cub->map_width)
			cub->map_width = j;
		index++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (s)
	{
		i = ft_strlen(s);
		j = 0;
		if (len > i)
			len = i;
		ptr = malloc(len + 1);
		if (!ptr)
			return (NULL);
		while (j < len && start < i)
		{
			ptr[j] = s[start];
			start++;
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
