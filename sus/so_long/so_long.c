/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:37:35 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/09 23:21:07 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	t_ping	oth;
	int		x;
	int		y;

	oth.map_height = 0;
	if (ac == 2)
	{
		checkmapextension(av[1]);
		map_height(&oth, av[1]);
		oth.map = read_map(&oth, av[1]);
		oth.pam = read_map(&oth, av[1]);
		check_walls(&oth);
		check_content(&oth);
		check_content2(&oth);
		butts_ifs_and_maybes(&oth);
		playerposition(&oth);
		if (floodfill(oth.pam, oth.player_x, oth.player_y) == 0)
			ft_error("Error\nexit gate is not reachable!");
		oth.mlx_ptr = mlx_init();
		x = oth.map_height;
		y = oth.map_width;
		oth.win_ptr = mlx_new_window(oth.mlx_ptr, y *= 64, x *= 64, "Morow");
		xpmlikexpf(&oth);
		copy(&oth);
		mlx_hook(oth.win_ptr, 2, 1L << 0, key, &oth);
		mlx_loop(oth.mlx_ptr);
	}
	else
		ft_error("Error\nInvalid argument");
	mlx_destroy_window(oth.mlx_ptr, oth.win_ptr);
	return (0);
}
