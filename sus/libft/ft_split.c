/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:29:56 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/28 08:36:10 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int countWords(char *str, char c)
{
    int i;
    int wc;

    wc = 0;
    i = 0;
    while(str[i] != '\0')
    {
        while (str[i] == c && str[i] != '\0')
        	i++;  
        if(str[i] != '\0')
          wc++;
        while(str[i] != '\0' && str[i] != c)
          i++;
    }
    return (wc);
}

char **ft_split(char const *s, char c)
{
	char *s2;
	char **ptr;
	char **ptr2;
	int i;

	i = countWords(s);
	s2 = s;
	ptr2 = ptr;
	ptr = malloc(sizeof(char *)*(wc + 1));
	if (!ptr)
		return (NULL);
	while(*s)
	{
		if(s == c && s != '\0')
			s++;
		else if (s2 != c && s2 != '\0')
			s2++;
	
		ft_substr(*s, 0, s2 - s);
		ptr2++;
	}
	ptr2 = 0;
}

int main(void)
{
    char str[] = "..hhhh....hhhh......hhhh...";
    printf("%d", ft_split(str, '.'));
}
