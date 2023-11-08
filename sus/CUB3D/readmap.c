/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:54:26 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/08 17:54:43 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checkmapextension(char *filename)
{
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".cub", 4) == 0)
		return ;
	else
		ft_error("Error\nextension error");
}

char	**read_map(t_cub *cub, char *av)
{
	char	*str;
	int		index;
	char	**ptr;
	int		fd;

	index = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFile error");
	ptr = (char **)malloc((cub->map_height + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
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

void    map_height(t_cub *cub, char *name)
{
	int		fd;
	char	str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nfile error");
	cub->map_height = 0;
	while (read(fd, &str, 1))
	{
		if (str == '\n')
			cub->map_height++;
	}
	if (cub->map_height == 0)
		ft_error("Error\nEmpty Map");
	cub->map_height++;
	close(fd);
}
char	**devide_map(t_cub *cub)
{
	char **ptr;
	int index;
	int	j;
	int	i;
	
	index = 0;
	i = 0;
	ptr = (char **)malloc(sizeof(char *) * 9);
	while (cub->map[index])
	{
		j = 0;
		while (cub->map[index][j])
		{
			if (cub->map[index][j] == 'E' && cub->map[index][j + 1] == 'A')
			{
				ptr[i++] = cub->map[index];
				return (ptr);
			}
			j++;
		}
		ptr[i++] = cub->map[index];
		index++;
	}
	return (NULL);
}