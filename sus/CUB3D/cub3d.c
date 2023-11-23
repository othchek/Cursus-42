/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:23 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/23 11:55:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub *cub, t_data *img)
{
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIDTH, HEIGHT, "D3buc");
	img->img = mlx_new_image(cub->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	if (!cub->win_ptr)
		ft_error("Error");
}

void	parse_elements(t_cub *cub)
{
	checkmap(cub);
	parse_rgb(cub);
	parse_xpmfiles(cub);
	store_it(cub);
}

void	map_parse(t_cub *cub)
{
	parse_empty_line(cub);
	parse_map(cub);
	parse_zeros(cub);
	parse_player(cub);
}

void	mlxat(t_cub *cub)
{
	mlx_hook(cub->win_ptr, 2, 1L << 0, key, cub);
	mlx_loop(cub->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_cub	cub;
	t_data	img;

	if (ac != 2)
		ft_error("Invalid Arguments");
	ft_init(&cub);
	checkmapextension(av[1]);
	map_height(&cub, av[1]);
	cub.allmap = read_map(&cub, av[1]);
	parse_elements(&cub);
	cub.map = devide_map(&cub);
	ones_length(&cub);
	width_check(&cub);
	cub.defmap = defmap(&cub);
	map_parse(&cub);
	init(&cub, &img);
	// loop_zeros(&cub, &img);
	// loop_player(&cub, &img);
	// mlx_put_image_to_window(cub.mlx_ptr, cub.win_ptr, img.img, 0, 0);
	// mlxat(&cub);
}
