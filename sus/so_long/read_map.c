/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:49:39 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/01 11:07:22 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line.h"
#include <mlx.h>

void	checkmapextension(char *filename)
{
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".ber", 4) == 0)
		return ;
	else
		ft_error("Error\nextension error");
}

void	map_height(t_ping *so_long, char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nfile error");
	while (get_next_line(fd))
		so_long->map_height++;
	close(fd);
}

char	**read_map(t_ping *so_long, char *av)
{
	char	*str;
	int		index;
	char	**ptr;
	int		fd;

	index = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFile error");
	ptr = (char **)malloc((so_long->map_height + 1) * sizeof(char *));
	str = get_next_line(fd);
	while (str)
	{
		ptr[index++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	ptr[index] = NULL;
	return (ptr);
}

// void    copy(t_ping *oth)
// {
//     int     i;
//     int     x;
//     int     y;
//     int     j;

//     i = 0;
//     y = 0;
//     while (oth->map[i])
//     {
//         j = 0;
//         x = 0;
//         while (oth->map[i][j] && oth->map[i][j] != '\n')
//         {
//             if (oth->map[i][j] == '0')
//                 mlx_put_image_to_window(oth->mlx_ptr, oth->win_ptr,
//							 oth->img_ptr, x, y);
// 			x += 32;
// 			j++;
// 		}
// 		y += 32;
//         i++;
// 	}
// }
