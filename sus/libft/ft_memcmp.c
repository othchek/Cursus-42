/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:04:47 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/17 14:45:04 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int *ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;
	char *str;
	char *strr;
	
	i = 0;
	str = (char *)s1;
	strr = (char *)s2;		
	while (i < n)
	{
		if(s1[i] - s2[i] < 0)
			return(s1[i] - s2[i]);
		else if(s1[i] - s2[i] > 0)
			return(s1[i] - s2[i]);
	}
}

int main()
{
	char name[] = "papay";
	char eman[] = "papay";
	printf("%d", ft_memcmp(name, eman, 4));
	printf("%d", memcmp(name, eman, 4));
}
