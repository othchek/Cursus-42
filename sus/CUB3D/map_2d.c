/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:23:26 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/18 18:53:49 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if(x > 1920 || y > 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(int x, int y, t_data *img, int size, int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	loop_zeros(t_cub *cub, t_data *img)
{
	int index;
	int j;

	index = 0;
	while (index < cub->ones_length)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (cub->defmap[index][j] == '1')
				draw_square(tile_size * j, tile_size * index, img, tile_size, 0xFFFFF);
			if (cub->defmap[index][j] == '0')
				draw_square(tile_size * j, tile_size * index, img, tile_size, 0x555555);
			if (cub->defmap[index][j] == 'N')
			{
				draw_square(tile_size * j, tile_size * index, img, tile_size, 0x555555);
				draw_square(tile_size * j, tile_size * index, img, tile_size / 2, 0x00FF0000);
			}
			j++;
		}
		index++;
	}
}