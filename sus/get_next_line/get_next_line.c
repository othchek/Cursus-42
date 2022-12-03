/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:34 by otchekai          #+#    #+#             */
/*   Updated: 2022/12/03 13:54:25 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		main;
	char	*ptr;

	main = 1;
	ptr = malloc(BUFFSIZE + 1);
	if (!ptr)
		return (NULL);
	while (main > 0 && !ft_strchr(ptr, '\n'))
	{
		main = read(fd, ptr, BUFFSIZE);
		if (main < 0 || (main == 0 && !buffer)
			|| (main == 0 && buffer[0] == 0))
			return (free(ptr), free(buffer), NULL);
		ptr[main] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	return (buffer);
}

char	*ft_morow(char *str)
{
	int		main;
	char	*ptr;
	int		sec;

	main = 0;
	sec = 0;
	while (str[main] != '\n' && str[main])
		main++;
	ptr = malloc(main + 2);
	if (!ptr)
		return (free(str), NULL);
	if (str[main] == '\n')
		main++;
	while (str[sec] && main > sec)
	{
		ptr[sec] = str[sec];
		sec++;
	}
	ptr[sec] = '\0';
	return (ptr);
}

char	*ft_morew(char *str)
{
	int		main;
	char	*ptr;
	int		size;
	int		sec;

	main = 0;
	sec = 0;
	while (str[main] && str[main] != '\n')
		main++;
	size = ft_strlen(str);
	if (size == main)
		return (free(str), NULL);
	ptr = malloc((size - main) + 1);
	if (!ptr)
		return (free(str), NULL);
	main++;
	while (str[main])
		ptr[sec++] = str[main++];
	ptr[sec] = '\0';
	free(str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*stats;
	char			*notsta;

	if (fd < 0 || BUFFSIZE <= 0)
		return (NULL);
	stats = ft_read(fd, stats);
	if (!stats)
		return (NULL);
	if (!*stats)
		return (free(stats), NULL);
	notsta = ft_morow(stats);
	stats = ft_morew(stats);
	return (notsta);
}

// int main()
// {
// 	int i;

// 	i = 0;
// 	int fd = open("wowo", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	while(s)
// 	{
// 		printf("%s", s);
// 		s = get_next_line(fd);
// 	}
// }