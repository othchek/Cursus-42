/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:46:33 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/04 11:53:58 by otchekai         ###   ########.fr       */
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
	j = 0;
	while (oth->map[index])
	{	
		j = 0;
		while (oth->map[index][j])
		{
			j++;
			if (oth->map[index][j] == 'P')
			{
				oth->playerY = index;
				oth->playerX = j;
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
