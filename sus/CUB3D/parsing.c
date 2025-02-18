/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/23 11:33:00 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkmap(t_cub *cub)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		if (strstr(cub->allmap[index], "F") 
			|| strstr(cub->allmap[index], "C") 
			|| strstr(cub->allmap[index], "NO") 
			|| strstr(cub->allmap[index], "SO") 
			|| strstr(cub->allmap[index], "WE") 
			|| strstr(cub->allmap[index], "EA"))
			count++;
		index++;
	}
	if (count != 6)
		ft_error("Invalid elements");
}

void	parse_rgb(t_cub *cub)
{
	int	index;
	int	count;
	int	key_counter;
	int	delimiter;
	int	value;
	int	j;

	index = 0;
	count = 0;
	key_counter = 0;
	while (cub->allmap[index])
	{
		j = 0;
		delimiter = 0;
		if (cub->allmap[index][j] == '\0')
		{
			index++;
			continue ;
		}
		while (cub->allmap[index][j])
		{
			if ((cub->allmap[index][j] == 'F' && cub->allmap[index][j + 1] != 'F') || (cub->allmap[index][j] == 'C' && cub->allmap[index][j + 1] != 'C'))
			{
				key_counter++;
				j++;
			}
			else if (cub->allmap[index][j] == ' ' || cub->allmap[index][j] == '\t' || cub->allmap[index][j] == '\r')
				j++;
			else if (cub->allmap[index][j] == ',' && ft_isdigit(cub->allmap[index][j + 1]) && ft_isdigit(cub->allmap[index][j - 1]))
			{
				delimiter++;
				j++;
			}
			else if (!ft_isdigit(cub->allmap[index][j]))
				ft_error("Invalid elements");
			else
			{
				value = 0;
				while (cub->allmap[index][j] && ft_isdigit(cub->allmap[index][j]))
				{
					value = value * 10 + (cub->allmap[index][j] - '0');
					j++;
				}
				while (cub->allmap[index][j] && (cub->allmap[index][j] == ' ' || cub->allmap[index][j] == '\t' || cub->allmap[index][j] == '\r'))
					j++;
				if (value < 0 || value > 255)
					ft_error("Invalid elements: RGB values must be between 0 and 255");
				if (cub->allmap[index][j] && cub->allmap[index][j] != ',' && !ft_isdigit(cub->allmap[index][j]))
					ft_error("Extra number found");
			}
		}
		count++;
		if (count == 2)
		{
			if (delimiter != 2)
				ft_error("Invalid elements");
			break ;
		}
		index++;
	}
	if (key_counter != 2)
		ft_error("Invalid elements");
}

void	parse_xpmfiles(t_cub *cub)
{
	int	index;
	int	count;
	int	j;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		j = 0;
		if ((strstr(cub->allmap[index], "NO"))
			|| strstr(cub->allmap[index], "SO")
			|| strstr(cub->allmap[index], "WE")
			|| strstr(cub->allmap[index], "EA"))
		{
			while (cub->allmap[index][j])
			{
				j += 2;
				if ((cub->allmap[index][j] == ' '
					|| cub->allmap[index][j] == '\t'
					|| cub->allmap[index][j] == '\r'))
					j++;
				if (cub->allmap[index][j])
					break ;
				else
					ft_error("Invalid Path");
				j++;
			}
			count++;
		}
		index++;
	}
	if (count != 4)
		ft_error("Invalid Path");
}

void	parse_map(t_cub *cub)
{
	int	index;
	int	flag;
	int	j;

	index = -1;
	flag = 0;
	while (cub->map && cub->map[++index])
	{
		j = 0;
		while (cub->map[index][j])
		{
			if (cub->map[index][j] == ' '
				|| cub->map[index][j] == '\t' || cub->map[index][j] == '\r')
				j++;
			else if (cub->map[index][j] == 'N' || cub->map[index][j] == 'S'
				|| cub->map[index][j] == 'W' || cub->map[index][j] == 'E')
			{
				cub->player_y = index * 32;
				cub->player_x = j * 32;
				j++;
				flag++;
			}
			else if (cub->map[index][j] != '0' && cub->map[index][j] != '1')
				ft_error("Invalid map: unknown character");
			j++;
		}
	}
	if (flag > 1 || flag == 0)
		ft_error("Invalid map: more than one or No player in the map");
}
