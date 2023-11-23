/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:14:24 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/22 16:14:59 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init(t_cub *cub)
{
    cub->map_height = 0;
	cub->map_width = 0;
	cub->ones_length = 0;
	cub->player_x = 0;
	cub->player_y = 0;
	cub->walkDirection = 0;
	cub->turnDirection = 0;
	cub->rotationAngle = M_PI / 2;
	cub->rotationSpeed = 2 * (M_PI / 180);
}