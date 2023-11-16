/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:37:12 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/16 16:58:07 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    **defmap(t_cub *cub)
{
	int		index;
	int		j;
	int		k;
	char	**ptr;

	index = -1;
	k = 0;
	ptr = malloc((sizeof(char *) * cub->map_height) + 1);
	if (!ptr)
		return (NULL);
	while (cub->map[++index])
	{
		ptr[index] = malloc((sizeof(char *) * cub->map_width) + 1);
		if (!ptr)
		{
			while (k < index)
			{
				free(ptr[k]);
				k++;
			}
			free(ptr);
			return (NULL);
		}
		j = -1;
		while (++j < cub->map_width)
		{
			if (j < ft_strlen(cub->map[index]))
				ptr[index][j] = cub->map[index][j];
			else
				ptr[index][j] = '*';
		}
		ptr[index][j] = '\0';
	}
	ptr[index] = NULL;
	return (ptr);
}
