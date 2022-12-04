/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:16:52 by otchekai          #+#    #+#             */
/*   Updated: 2022/12/04 17:24:40 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_bonus(int fd, char *buffer)
{
	int		index;
	char	*ptr;

	index = 1;
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while (index > 0 && !ft_strchr(buffer, '\n'))
	{
		index = read(fd, ptr, BUFFER_SIZE);
		if (index < 0 || (index == 0 && !buffer)
			|| (index == 0 && buffer[0] == 0))
			return (free(ptr), free(buffer), NULL);
		ptr[index] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	return (buffer);
}

char	*ft_stash_bonus(char *str)
{
	int		index;
	char	*ptr;
	int		secindex;

	index = 0;
	secindex = 0;
	while (str[index] && str[index] != '\n')
		index++;
	ptr = malloc(index + 2);
	if (!ptr)
		return (free(str), NULL);
	if (str[index] == '\n')
		index++;
	while (str[secindex] && index > secindex)
	{
		ptr[secindex] = str[secindex];
		secindex++;
	}
	ptr[secindex] = '\0';
	return (ptr);
}

char	*ft_beyondthestash_bonus(char *str)
{
	int		index;
	char	*ptr;
	int		size;
	int		secindex;

	index = 0;
	secindex = 0;
	while (str[index] && str[index] != '\n')
		index++;
	size = ft_strlen(str);
	if (size == index)
		return (free(str), NULL);
	ptr = malloc((size - index) + 1);
	if (!ptr)
		return (free(str), NULL);
	index++;
	while (str[index])
		ptr[secindex++] = str[index++];
	ptr[secindex] = '\0';
	free(str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*stats[OPEN_MAX];
	char			*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	stats[fd] = ft_read_bonus(fd, stats[fd]);
	if (!stats[fd])
		return (NULL);
	if (!*stats[fd])
		return (free(stats), NULL);
	stock = ft_stash_bonus(stats[fd]);
	stats[fd] = ft_beyondthestash_bonus(stats[fd]);
	return (stock);
}