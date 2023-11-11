/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/10 13:03:37 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkmap(t_cub *cub, char c)
{
	int	index;
	int	j;
	int	count;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		j = 0;
		while (cub->allmap[index][j])
		{
			if (cub->allmap[index][j] == c)
				count++;
			j++;
		}
		index++;
	}
	if (count > 1)
		ft_error("Invalid map");
}
