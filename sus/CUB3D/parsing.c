/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/08 16:02:22 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    checkmap(t_cub *cub, char c)
{
    int index;
    int j;
    int count;

    index = 0;
    count = 0;
    while (cub->map[index])
    {
        j = 0;
        while (cub->map[index][j])
        {
            if (cub->map[index][j] == c)
                count++;
            j++;
        }
        index++;
    }
    if (count > 1)
        ft_error("Invalid map");
}
