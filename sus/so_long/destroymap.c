/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroymap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:47:06 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/25 14:15:02 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	destroyleaks(t_ping *oth)
{
	mlx_destroy_image(oth->mlx_ptr, oth->win_ptr);
	mlx_destroy_image(oth->mlx_ptr, oth->img_ptr);
	mlx_destroy_image(oth->mlx_ptr, oth->img_ptr2);
	mlx_destroy_image(oth->mlx_ptr, oth->wall);
	mlx_destroy_image(oth->mlx_ptr, oth->frisk);
	mlx_destroy_image(oth->mlx_ptr, oth->collectible);
	mlx_destroy_image(oth->mlx_ptr, oth->background);
	mlx_destroy_image(oth->mlx_ptr, oth->exitgate);
}
