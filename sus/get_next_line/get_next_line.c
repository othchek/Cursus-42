/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:34 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/28 15:45:04 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_read(int fd, char *buffer)
{
	int		i;
	char	*ptr;

	i = 1;
	ptr = malloc(BUFFSIZE * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while(i > 0 && !ft_strchr(buffer, '\n'))
	{
		i = read(fd, ptr, BUFFSIZE);
		if (i < 0 || (i == 0 && !buffer))
			return (free(ptr), free(buffer), NULL);
		ptr[i] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	return (buffer);
}

char ft_read2(char *str)
{
	int i;
	char *ptr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (i > 0)
	{
		ptr[i] = str[i];
		i--;
	}
	ptr[i] = '\0';
	return (ptr);
}

// char *get_next_line(int fd)
// {
// 	char *str;
// 	return (ft_read2(str));
// }
