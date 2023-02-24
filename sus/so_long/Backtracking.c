/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:46:33 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/24 15:38:45 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	playerposition(t_ping *oth)
{
	int	index;
	int	j;

	index = 0;
	while (oth->map[index])
	{	
		j = 0;
		while (oth->map[index][j])
		{
			j++;
			if (oth->map[index][j] == 'P')
			{
				oth->player_y = index;
				oth->player_x = j;
				break ;
			}
		}
		index++;
	}
}

int	floodfill(char **ptr, int x, int y)
{
	if (ptr[y][x] == 'E')
		return (1);
	if (ptr[y][x] == '1')
		return (0);
	ptr[y][x] = '1';
	if (floodfill(ptr, x, y - 1))
		return (1);
	if (floodfill(ptr, x, y + 1))
		return (1);
	if (floodfill(ptr, x + 1, y))
		return (1);
	if (floodfill(ptr, x - 1, y))
		return (1);
	return (0);
}

int	colcount(char **ptr)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	fillflood(char **ptr, int x, int y)
{
	int	c;

	c = colcount(ptr);
	if (c == 0)
		return (1);
	if (ptr[y][x] == '1' || ptr[y][x] == 'E')
		return (0);
	ptr[y][x] = '1';
	if (fillflood(ptr, x, y - 1))
		return (1);
	if (fillflood(ptr, x, y + 1))
		return (1);
	if (fillflood(ptr, x + 1, y))
		return (1);
	if (fillflood(ptr, x - 1, y))
		return (1);
	return (0);
}
