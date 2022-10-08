/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:09:40 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/07 11:11:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strchr(const char *str, int c)
{
    while(*str != '\0')
    {
        if(*str == (char)(c))
        {
            return(char *)(str);
        }
        str++;
    }
    return(0);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
    char needle[] = "";
    printf("%s\n", ft_strchr(needle, ));
    printf("%s", strchr(needle, ));
}*/