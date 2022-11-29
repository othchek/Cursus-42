/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:34 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/29 17:33:01 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		i;
	char	*ptr;

	i = 1;
	ptr = malloc(BUFFSIZE + 1);
	if (!ptr)
		return (NULL);
	while(i > 0 && !ft_strchr(ptr, '\n'))
	{
		i = read(fd, ptr, BUFFSIZE);
		if (i == -1 || (i == 0 && !ptr))
			return (free(ptr), free(buffer), NULL);
		ptr[i] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	return (buffer);
}

char	*ft_morow(char *str)
{
	int i;
	char *ptr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	ptr = malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr[i--] = '\0';
	while (str[i])
	{
		ptr[i] = str[i];
		i--;
	}
	return (ptr);
}

char	*ft_morew(char *buff)
{
	int		i;
	char	*ptr;

	i = 0;
	while (buff[i] && buff != '\n')
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	if (buff[i] == '\n')
		i++;
	while (ptr[i])
	{
		ptr[i] = buff[i]
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *get_next_line(int fd)
{
	char		*str;
	static char	*zeb;

	zeb = ft_read(fd, zeb);
	str = ft_morow(zeb);
	return (str);
}

// int main()
// {
	
// 	int fd = open("wowo", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// }