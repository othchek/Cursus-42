/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:08:23 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/08 16:43:12 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub oth;
    oth.map_height = 0;
    if (ac != 2)
        ft_error("Invalid Arguments");
    checkmapextension(av[1]);
    map_height(&oth, av[1]);
    oth.map = read_map(&oth, av[1]);
    checkmap(&oth, 'F');
    oth.elements = devide_map(&oth);
    for (int i = 0; oth.elements[i]; i++)
        printf("%s\n", oth.elements[i]);
}