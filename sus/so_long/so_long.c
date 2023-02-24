/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:37:35 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/24 18:37:54 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line.h"

void	check(t_ping *oth)
{
	check_walls(oth);
	check_content(oth);
	check_content2(oth);
	butts_ifs_and_maybes(oth);
	playerposition(oth);
}

void	ini(t_ping *oth)
{
	int	x;
	int	y;

	oth->mlx_ptr = mlx_init();
	x = oth->map_height;
	y = oth->map_width;
	oth->win_ptr = mlx_new_window(oth->mlx_ptr, y *= 64, x *= 64, "Morow");
	if (!oth->win_ptr)
		ft_error("Error");
}

void	mlxat(t_ping *oth)
{
	mlx_hook(oth->win_ptr, 2, 1L << 0, key, oth);
	mlx_hook(oth->win_ptr, 17, 1L << 0, fireexit, oth);
	mlx_loop(oth->mlx_ptr);
}

int	fireexit(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_ping	oth;

	oth.var = 0;
	oth.map_height = 0;
	if (ac == 2)
	{
		checkmapextension(av[1]);
		map_height(&oth, av[1]);
		oth.map = read_map(&oth, av[1]);
		oth.pam = read_map(&oth, av[1]);
		check(&oth);
		if (floodfill(oth.pam, oth.player_x, oth.player_y) == 0)
			ft_error("Error\nexit gate is not reachable!");
		oth.pam = NULL;
		oth.pam = read_map(&oth, av[1]);
		if (fillflood(oth.pam, oth.player_x, oth.player_y) == 0)
			ft_error("Error\nplayer can't win!");
		ini(&oth);
		xpmlikexpf(&oth);
		copy(&oth);
		mlxat(&oth);
		destroyleaks(&oth);
	}
	else
		ft_error("Error\nInvalid argument");
}
