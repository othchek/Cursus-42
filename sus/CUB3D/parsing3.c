/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:52:40 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/16 12:23:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->defmap[i])
	{
		j = 0;
		while (cub->defmap[i][j])
		{
			if ((cub->defmap[i][j] == 'N' || cub->defmap[i][j] == 'S'
				|| cub->defmap[i][j] == 'W' || cub->defmap[i][j] == 'E')
				&& !player_valid(cub, i, j))
				ft_error("Invalid map: player");
			j++;
		}
		i++;
	}
}

void	parse_empty_line(t_cub *cub)
{
	int	index;

	index = 0;
	while (cub->map[index])
	{
		if (cub->map[index][0] == '\0')
			ft_error("Invalid map: Empty line in map");
		index++;
	}
}
