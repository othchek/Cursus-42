/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:23 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/16 16:56:08 by otchekai         ###   ########.fr       */
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

void	map_parse(t_cub *cub)
{
	parse_empty_line(cub);
	parse_map(cub);
	parse_zeros(cub);
	parse_player(cub);
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
	ones_length(&cub);
	width_check(&cub);
	cub.defmap = defmap(&cub);
	map_parse(&cub);
	// for (int i = 0; cub.defmap[i]; i++)
		// printf("%s\n", cub.defmap[i]);
}