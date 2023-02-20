/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:32:12 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/20 15:41:33 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft/libft.h"

void	printmove(t_ping *oth, int keycode)
{
	static int	i;

	if ((oth->map[oth->player_y - 1][oth->player_x] != '1'
		|| oth->map[oth->player_y - 1][oth->player_x] != 'E')
		&& keycode == 13)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
	if ((oth->map[oth->player_y + 1][oth->player_x] != '1'
		|| oth->map[oth->player_y + 1][oth->player_x] != 'E')
		&& keycode == 1)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	printmove2(t_ping *oth, int keycode)
{
	static int	i;

	if ((oth->map[oth->player_y][oth->player_x - 1] != '1'
		|| oth->map[oth->player_y][oth->player_x - 1] != 'E')
		&& keycode == 0)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
	if ((oth->map[oth->player_y][oth->player_x + 1] != '1'
		|| oth->map[oth->player_y][oth->player_x + 1] != 'E')
		&& keycode == 2)
	{
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	what_to_print(t_ping *oth, int j, int i)
{
	if (oth->map[i][j] == '0')
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->background,
			j * 64, i * 64);
	else if (oth->map[i][j] == '1')
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->wall,
			j * 64, i * 64);
	else if (oth->map[i][j] == 'E')
	{
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->background,
			j * 64, i * 64);
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->exitgate,
			j * 64, i * 64);
	}
}

void	what_to_print2(t_ping *oth, int j, int i)
{
	if (oth->map[i][j] == 'C')
	{
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->background,
			j * 64, i * 64);
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->collectible,
			j * 64, i * 64);
	}
	else if (oth->map[i][j] == 'P')
	{
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->background,
			j * 64, i * 64);
		mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr, oth->frisk,
			j * 64, i * 64);
	}
}
