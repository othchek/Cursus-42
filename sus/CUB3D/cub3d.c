/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:23 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/11 22:03:29 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	cub.map_height = 0;
	if (ac != 2)
		ft_error("Invalid Arguments");
	checkmapextension(av[1]);
	map_height(&cub, av[1]);
	cub.allmap = read_map(&cub, av[1]);
	parse_rgb(&cub);
	// for (int i = 0; cub.elements[i]; i++)
		// printf("%s\n", cub.elements[i]);
}