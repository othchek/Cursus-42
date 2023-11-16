/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:52:05 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/16 16:57:07 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_surrounding(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

int	player_valid_surrounding(char c)
{
	if (c == '1' || c == '0')
		return (1);
	else
		return (0);
}

// int	is_zero_valid(t_cub *cub, int i, int j)
// {
// 	if ((i != 0 && is_valid_surrounding(cub->defmap[i - 1][j])) &&
// 		(i <= cub->map_height && is_valid_surrounding(cub->defmap[i + 1][j])) &&
// 		((i != 0 && j != 0) && is_valid_surrounding(cub->defmap[i - 1][j - 1])) &&
// 		(is_valid_surrounding(cub->defmap[i][j + 1]) && cub->defmap[i][j + 1] != '\0'))
// 		return (1);
// 	else
// 		return (0);
// }

int	is_zero_valid(t_cub *cub, int i, int j)
{
	if ((i == 0 || j == 0 || i == cub->ones_length - 1 || j == ft_strlen(cub->defmap[i]) - 1))
		return (0);
	if (!is_valid_surrounding(cub->defmap[i - 1][j])
	||!is_valid_surrounding(cub->defmap[i + 1][j])
	||!is_valid_surrounding(cub->defmap[i][j + 1]) 
	|| !is_valid_surrounding(cub->defmap[i][j - 1]))
		return (0);
	return (1);
}

int	player_valid(t_cub *cub, int i, int j)
{
	if ((i != 0 && player_valid_surrounding(cub->defmap[i - 1][j])) &&
		(i <= cub->ones_length && player_valid_surrounding(cub->defmap[i + 1][j])) &&
		(i != 0 && player_valid_surrounding(cub->defmap[i][j - 1])) &&
		(player_valid_surrounding(cub->defmap[i][j + 1]) && cub->defmap[i][j + 1] != '\0'))
		return (1);
	else
	{
		printf("%s\n", cub->map[i]);
		return (0);
	}
}

void	parse_zeros(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->defmap[i])
	{
		j = 0;
		while (cub->defmap[i][j])
		{
			if (cub->defmap[i][j] == '0' && !is_zero_valid(cub, i, j))
				ft_error("Invalid map: 0 not surrounded with valid elements");
			j++;
		}
		i++;
	}
}
