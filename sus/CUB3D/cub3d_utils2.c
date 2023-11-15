/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:40:11 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/15 18:43:57 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strfound(char *haystack, char *needle)
{
	int	needlelen;
	int	whitespaces;

	needlelen = ft_strlen(needle);
	while (*haystack != '\0') 
	{
		whitespaces = 0;
		while (ft_isspace(*haystack)) 
		{
			haystack++;
			whitespaces++;
		}
		if (ft_strncmp(haystack, needle, needlelen) == 0) 
		{
			if (haystack[needlelen] == '\0' || ft_isspace(haystack[needlelen]))
				return (1);
		}
		haystack += whitespaces;
		if (whitespaces == 0)
			haystack++;
	}
	return (0);
}

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
	while (cub->map[index])
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
