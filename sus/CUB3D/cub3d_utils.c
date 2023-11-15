/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/11/15 18:40:06 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] > s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static    int    words_counter(char *s, char *c)
{
    int        i;
    int        words;

    i = 0;
    words = 0;
    while (s[i] != '\0')
    {
        if (ft_strchr(c, s[i]))
            i++;
        else
        {
            words++;
            while (s[i] != '\0' && !ft_strchr(c, s[i]))
                i++;
        }
    }
    return (words);
}

static char    **free_mem2(char **mem)
{
    int    i;

    i = 0;
    while (mem[i])
    {
        free(mem[i]);
        i++;
    }
    free(mem);
    return (NULL);
}

char    **ft_split2(char *s, char *c)
{
    size_t        word_len;
    char        **split;
    size_t        i;

    i = 0;
    if (!s || !c)
        return (NULL);
    split = (char **)malloc((words_counter(s, c) + 1) * sizeof(*split));
    if (!split)
        return (free(split), NULL);
    while (*s != '\0')
    {
        while (*s && ft_strchr(c, *s))
            s++;
        word_len = 0;
        while (s[word_len] && !ft_strchr(c, s[word_len]))
            word_len++;
        if (word_len != 0)
            split[i++] = ft_substr(s, 0, word_len);
        if (word_len != 0 && split[i - 1] == 0)
            return (free_mem2(split));
        s += word_len;
    }
    split[i] = NULL;
    return (split);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (s)
	{
		i = ft_strlen(s);
		j = 0;
		if (len > i)
			len = i;
		ptr = malloc(len + 1);
		if (!ptr)
			return (NULL);
		while (j < len && start < i)
		{
			ptr[j] = s[start];
			start++;
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
