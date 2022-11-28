/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:34 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/28 13:17:11 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	read(int fd, char *buffer)
{
	int		i;
	char	*ptr;

	i = 1;
	ptr = malloc(BUFFSIZE * sizeof(char));
	if (!ptr)
		return (NULL);
	while(i > 0 && !ft_strchr(buffer, '\n'))
	{
		ptr = read(fd, buffer, BUFFSIZE);
		if (i < 0 || (i == 0 && !buffer))
			return (free(ptr), free(buffer), NULL);
		ptr[i] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	return (buffer);
}

// char *get_next_line(int fd)
// {

// }