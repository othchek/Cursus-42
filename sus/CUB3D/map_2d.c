/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:23:26 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/22 15:52:43 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	if((x > WIDTH || y > HEIGHT) || (0 > y || x < 0))
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

void	loop_player(t_cub *cub, t_data *img)
{

	int index;
	int j;

	index = 0;
	while (index < cub->ones_length)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (cub->defmap[index][j] == 'N')
			{
				draw_square(tile_size * j, tile_size * index, img, tile_size, 0x555555);
				draw_square(tile_size * j + 8, tile_size * index + 8, img, tile_size / 2, 0xFF0000);
				draw_line_rotated(img, cub->player_x + 16, cub->player_y + 16, 20, WEST, 0x0000FF);
			}
			j++;
		}
		index++;
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
			j++;
		}
		index++;
	}
}

void calculate_rotated_endpoint(double beginX, double beginY, double length, double angle, double *endX, double *endY)
{
    *endX = beginX + length * cos(angle);
    *endY = beginY + length * sin(angle);
}

int draw_line(t_data *mlx, double beginX, double beginY, double endX, double endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    deltaX /= pixels;
    deltaY /= pixels;
    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        my_mlx_pixel_put(mlx, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return 0;
}

int draw_line_rotated(t_data *mlx, double beginX, double beginY, double length, double angle, int color)
{
    double endX;
	double endY;

    calculate_rotated_endpoint(beginX, beginY, length, angle, &endX, &endY);
    return draw_line(mlx, beginX, beginY, endX, endY, color);
}