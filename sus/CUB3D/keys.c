/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:45:54 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/18 18:41:07 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key(int keycode, t_cub *cub)
{
	(void)cub;
	if (keycode == 53)
		exit (0);
	// if (keycode == 13)
	// 	keyup(cub);
	// if (keycode == 1)
	// 	keydown(cub);
	// if (keycode == 2)
	// 	keyright(cub);
	// if (keycode == 0)
	// 	keyleft(cub);
	return (0);
}

// void	keyup(t_cub *cub)
// {
// 	int index;
	
// }