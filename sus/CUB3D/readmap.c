/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:54:26 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/11 23:51:36 by otchekai         ###   ########.fr       */
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

void	parse_rgb(t_cub *cub)
{
	int index;
	int count;
	int delimiter;
	int value;
	int j;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		j = 0;
		delimiter = 0;
		if (cub->allmap[index][j] == '\0')
		{
			index++;
			continue;
		}
		while (cub->allmap[index][j])
		{
			if (cub->allmap[index][j] == 'F' || cub->allmap[index][j] == 'C')
				j++;
			else if (cub->allmap[index][j] == ' ' || cub->allmap[index][j] == '\t' || cub->allmap[index][j] == '\r')
				j++;
			else if (cub->allmap[index][j] == ',' && ft_isdigit(cub->allmap[index][j + 1]))
			{
				delimiter++;
				j++;
			}
			else if (!ft_isdigit(cub->allmap[index][j]))
				ft_error("Invalid elements");
			else
			{
			    value = 0;
			    while (cub->allmap[index][j] && ft_isdigit(cub->allmap[index][j]))
			    {
			        value = value * 10 + (cub->allmap[index][j] - '0');
			        j++;
			    }
			    while (cub->allmap[index][j] && (cub->allmap[index][j] == ' ' || cub->allmap[index][j] == '\t' || cub->allmap[index][j] == '\r'))
			        j++;
			    if (value < 0 || value > 255)
			        ft_error("Invalid elements: RGB values must be between 0 and 255");
				if (cub->allmap[index][j] && cub->allmap[index][j] != ',')
                    ft_error("Extra number found");
			}
		}
		count++;
		if (count == 2)
		{
			if (delimiter != 2)
				ft_error("Invalid elements:");
			break ;
		}
		index++;
	}
}

// char	**devide_map(t_cub *cub)
// {
// 	char	**ptr;
// 	int		index;
// 	int		i;
// 	int		count;
// 	int		j;

// 	j = 0;
// 	count = 0;
// 	i = 0;
// 	index = 0;
// 	ptr = malloc(sizeof(char *) * 6);
// 	if (!ptr)
// 		return (NULL);
// 	while (cub->allmap[index] && count <= 5)
// 	{
// 		if (cub->allmap[index][j] == '\0')
// 		{
// 			index++;
// 			continue ;
// 		}
// 		if (count == 5)
// 		{
// 			ptr[i++] = cub->allmap[index];
// 			break ;
// 		}
// 		ptr[i++] = cub->allmap[index];
// 		index++;
// 		count++;
// 	}
// 	ptr[i] = NULL;
// 	return (ptr);
// }

// void key_check(char *str, char *key) 
// {
//     char **split;
//     int i;

// 	i = 0;
//     split = ft_split(str, ' ');
//     while (split[i]) 
// 	{
//         if (!ft_strncmp(split[i], key, 1)) 
// 		{
//             if (split[i + 1] == NULL)
//                 printf("Key: %s has no corresponding value.\n", split[i]);
// 			break;
//         }
// 		i++;
//     }
// 	if (split[i] == NULL)
//         printf("Key: %s not found.\n", key);
// }
