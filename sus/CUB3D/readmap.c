/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:54:26 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/23 11:31:37 by otchekai         ###   ########.fr       */
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
	ptr = malloc((cub->map_height + 1) * sizeof(char *));
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

void	map_height(t_cub *cub, char *name)
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

void	store_it(t_cub *cub)
{
	int index;

	index = 0;
	while (cub->allmap[index])
	{
		if (strstr(cub->allmap[index], "F"))
			cub->f = cub->allmap[index];
		else if (strstr(cub->allmap[index], "C"))
			cub->c = cub->allmap[index];
		else if (strstr(cub->allmap[index], "NO"))
			cub->no = cub->allmap[index];
		else if (strstr(cub->allmap[index], "SO"))
			cub->so = cub->allmap[index];
		else if (strstr(cub->allmap[index], "WE"))
			cub->we = cub->allmap[index];
		else if (strstr(cub->allmap[index], "EA"))
			cub->ea = cub->allmap[index];
		index++;
	}
}

char	**devide_map(t_cub *cub)
{
	char	**ptr;
	int		index;
	int		j;

	j = 0;
	index = 0;
	ptr = malloc(sizeof(char *) * cub->map_height);
	if (!ptr)
		return (NULL);
	while (cub->allmap[index])
	{
		if (cub->allmap[index][j] == '\0')
		{
			index++;
			continue ;
		}
		if (cub->allmap[index][j] == '1' && cub->allmap[index][j + 1] == '1'
			&& cub->allmap[index][j + 2] == '1')
		{
			ptr = &cub->allmap[index];
			return (ptr);
		}
		index++;
	}
	return (NULL);
}

void	ones_length(t_cub *cub)
{
	int index;

	index = 0;
	while (cub->map && cub->map[index])
		index++;
	cub->ones_length = index;
}