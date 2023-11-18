/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:23 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/18 17:18:41 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cub *cub, t_data *img)
{
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, 1280, 720, "D3buc");
	img->img = mlx_new_image(cub->mlx_ptr, 1280, 720);
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

	cub.map_height = 0;
	cub.map_width = 0;
	cub.ones_length = 0;
	if (ac != 2)
		ft_error("Invalid Arguments");
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
	loop_zeros(&cub, &img);
	mlx_put_image_to_window(cub.mlx_ptr, cub.win_ptr, img.img, 0, 0);
	mlxat(&cub);
	// for (int i = 0; cub.defmap[i]; i++)
		// printf("%s\n", cub.defmap[i]);
}
