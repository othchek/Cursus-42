/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:08:15 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/04 12:37:09 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	width_check(t_ping *oth)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (oth->map[index])
	{
		if (ft_strlen(oth->map[0]) != ft_strlen(oth->map[index]))
			ft_error("Error\nmap width isnt correct");
		index++;
	}
	oth->map_width = ft_strlen(oth->map[0]);
	if (!oth->map_width)
		ft_error("Error\nMap format incorrect");
}

void	check_walls(t_ping *oth)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	width_check(oth);
	while (oth->map[0][j] && oth->map[oth->map_height - 1][j])
	{
		if (oth->map[0][j] != '1' ||
		oth->map[oth->map_height - 1][j] != '1')
			ft_error("Error\nThe map isnt surrounded by walls");
		j++;
	}
	j--;
	while (oth->map[index])
	{
		if (oth->map[index][0] != '1' ||
			oth->map[index][oth->map_width - 1] != '1')
			ft_error("Error\nThe map isnt surrounded by walls");
		index++;
	}
}

void	check_content(t_ping *oth)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	oth->ground = 0;
	oth->player = 0;
	while (oth->map[index])
	{
		j = 0;
		while (oth->map[index][j])
		{
			if (oth->map[index][j] != 'P' && oth->map[index][j] != '1'
				&& oth->map[index][j] != '0' && oth->map[index][j] != 'E'
				&& oth->map[index][j] != 'C')
				ft_error("Error\ninvalid character !");
			if (oth->map[index][j] == 'P')
				oth->player++;
			if (oth->map[index][j] == '0')
				oth->ground++;
			j++;
		}
		index++;
	}
}

void	check_content2(t_ping *oth)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	oth->collectibles = 0;
	oth->exits = 0;
	while (oth->map[index])
	{
		j = 0;
		while (oth->map[index][j])
		{
			if (oth->map[index][j] == 'C')
				oth->collectibles++;
			if (oth->map[index][j] == 'E')
				oth->exits++;
			j++;
		}
		index++;
	}
}

void	butts_ifs_and_maybes(t_ping *oth)
{
	if (oth->player != 1)
		ft_error("Error\nMultiple or missing players !");
	else if (oth->ground < 1)
		ft_error("Error\nMissing ground texture !");
	else if (oth->collectibles <= 0)
		ft_error("Error\nMissing collectibles !");
	else if (oth->exits != 1)
		ft_error("Error\nMultiple or missing exits !");
	else if (oth->map_width == oth->map_height)
		ft_error("Error\nMap is not rectangular !");
}
