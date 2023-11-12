/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/12 17:04:37 by otchekai         ###   ########.fr       */
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
		if (ft_strfound(cub->allmap[index], "F") || ft_strfound(cub->allmap[index], "C") || ft_strfound(cub->allmap[index], "NO")
			|| ft_strfound(cub->allmap[index], "SO") || ft_strfound(cub->allmap[index], "WE")
			|| ft_strfound(cub->allmap[index], "EA"))
			count++;
		index++;
	}
	if (count != 6)
		ft_error("Invalid elements");
}
void	parse_rgb(t_cub *cub)
{
	int index;
	int count;
	int key_counter;
	int delimiter;
	int value;
	int j;

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
			continue;
		}
		while (cub->allmap[index][j])
		{
			if ((cub->allmap[index][j] == 'F' && cub->allmap[index][j + 1] != 'F')
				|| (cub->allmap[index][j] == 'C' && cub->allmap[index][j + 1] != 'C'))
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
	int index;
	int count;
	int j;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		j = 0;
		if ((ft_strfound(cub->allmap[index], "NO")) || ft_strfound(cub->allmap[index], "SO") 
			|| ft_strfound(cub->allmap[index], "WE") || ft_strfound(cub->allmap[index], "EA"))
		{
			count++;
			while (cub->allmap[index][j])
			{
				j += 2;
				if (cub->allmap[index][j] && (cub->allmap[index][j] == ' ' || cub->allmap[index][j] == '\t' || cub->allmap[index][j] == '\r'))
					j++;
				if (cub->allmap[index][j])
					break;
				else
					ft_error("Invalid Path");
				j++;
			}
		}
		index++;
	}
	if (count != 4)
		ft_error("Invalid Path");
}
