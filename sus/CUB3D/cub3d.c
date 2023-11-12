/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:23 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/12 17:22:14 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_elements(t_cub *cub)
{
	checkmap(cub);
	parse_rgb(cub);
	parse_xpmfiles(cub);
	store_it(cub);
}
int	main(int ac, char **av)
{
	t_cub	cub;

	cub.map_height = 0;
	if (ac != 2)
		ft_error("Invalid Arguments");
	checkmapextension(av[1]);
	map_height(&cub, av[1]);
	cub.allmap = read_map(&cub, av[1]);
	parse_elements(&cub);
	cub.map = devide_map(&cub);
	for (int i = 0; cub.map[i]; i++)
		printf("%s\n", cub.map[i]);
}