/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harkti_playar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:17:54 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/18 18:00:27 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "get_next_line.h"

void	keyup(t_ping *oth)
{
	if (oth->map[oth->player_y - 1][oth->player_x] == 'C')
		oth->collectibles--;
	if (oth->map[oth->player_y - 1][oth->player_x] == 'E'
		&& oth->collectibles == 0)
		ft_error("HOORAY!");
	if (oth->map[oth->player_y - 1][oth->player_x] != 'E' &&
			oth->map[oth->player_y - 1][oth->player_x] != '1')
	{
		oth->map[oth->player_y][oth->player_x] = '0';
		oth->map[--oth->player_y][oth->player_x] = 'P';
	}
}

void	keydown(t_ping *oth)
{
	if (oth->map[oth->player_y + 1][oth->player_x] == 'C')
		oth->collectibles--;
	if (oth->map[oth->player_y + 1][oth->player_x] == 'E'
		&& oth->collectibles == 0)
		ft_error("HOORAY!");
	if (oth->map[oth->player_y + 1][oth->player_x] != 'E' &&
			oth->map[oth->player_y + 1][oth->player_x] != '1')
	{
		oth->map[oth->player_y][oth->player_x] = '0';
		oth->map[++oth->player_y][oth->player_x] = 'P';
	}
}

void	keyright(t_ping *oth)
{
	if (oth->map[oth->player_y][oth->player_x + 1] == 'C')
		oth->collectibles--;
	if (oth->map[oth->player_y][oth->player_x + 1] == 'E'
		&& oth->collectibles == 0)
		ft_error("HOORAY!");
	if (oth->map[oth->player_y][oth->player_x + 1] != 'E' &&
			oth->map[oth->player_y][oth->player_x + 1] != '1')
	{
		oth->map[oth->player_y][oth->player_x] = '0';
		oth->map[oth->player_y][++oth->player_x] = 'P';
	}
}

void	keyleft(t_ping *oth)
{
	if (oth->map[oth->player_y][oth->player_x - 1] == 'C')
		oth->collectibles--;
	if (oth->map[oth->player_y][oth->player_x - 1] == 'E'
		&& oth->collectibles == 0)
		ft_error("HOORAY!");
	if (oth->map[oth->player_y][oth->player_x - 1] != 'E' &&
			oth->map[oth->player_y][oth->player_x - 1] != '1')
	{
		oth->map[oth->player_y][oth->player_x] = '0';
		oth->map[oth->player_y][--oth->player_x] = 'P';
	}
}

int	key(int keycode, t_ping *oth)
{
	printmove(oth, keycode);
	printmove2(oth, keycode);
	if (keycode == 53)
		exit (0);
	if (keycode == 13)
		keyup(oth);
	if (keycode == 1)
		keydown(oth);
	if (keycode == 2)
		keyright(oth);
	if (keycode == 0)
		keyleft(oth);
	copy(oth);
	return (0);
}
