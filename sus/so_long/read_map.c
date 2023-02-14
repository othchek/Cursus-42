/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:49:39 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/14 13:40:23 by otchekai         ###   ########.fr       */
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
	int		fd;
	char	*str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nfile error");
	str = get_next_line(fd);
	while (str)
	{
		so_long->map_height++;
		free (str);
		str = get_next_line(fd);
	}
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
	free(str);
	return (ptr);
}

void	xpmlikexpf(t_ping *oth)
{
	int	x;
	int	y;

	oth->background = mlx_xpm_file_to_image(oth->mlx_ptr,
			"./pixels/background.xpm", &x, &y);
	if (!oth->background)
		ft_error("Error");
	oth->wall = mlx_xpm_file_to_image(oth->mlx_ptr,
			"./pixels/wall.xpm", &x, &y);
	if (!oth->wall)
		ft_error("Error");
	oth->exitgate = mlx_xpm_file_to_image(oth->mlx_ptr,
			"./pixels/exitgate.xpm", &x, &y);
	if (!oth->exitgate)
		ft_error("Error");
	oth->collectible = mlx_xpm_file_to_image(oth->mlx_ptr,
			"./pixels/collectible.xpm", &x, &y);
	if (!oth->collectible)
		ft_error("Error");
	oth->frisk = mlx_xpm_file_to_image(oth->mlx_ptr,
			"./pixels/frisk.xpm", &x, &y);
	if (!oth->frisk)
		ft_error("Error");
}

void	copy(t_ping	*oth)
{
	int		i;
	int		j;

	i = 0;
	while (oth->map[i])
	{
		j = 0;
		while (oth->map[i][j] && oth->map[i][j] != '\n')
		{
			what_to_print(oth, j, i);
			what_to_print2(oth, j, i);
			j++;
		}
		i++;
	}
}
