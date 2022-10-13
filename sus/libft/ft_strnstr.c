/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:18:08 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/14 00:28:47 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int *k;
	k = (int *)len;
	

	i = 0;
	j = 0;
	if(needle[j] == '\0')
		return((char *)haystack);
	while(haystack[i] != '\0')
	{
		if(haystack[i] == needle[j])
			return((char *)&haystack[i]);
			i++;
	}
		if(haystack[i] != needle[j])
		return(0);
	return(0);
}
int main()
{
	char haystack[] = "papay";
	char needle[] = "a";
	printf("%s\n", ft_strnstr(haystack, needle, 5));
	printf("%s", strnstr(haystack, needle, 5));	
}