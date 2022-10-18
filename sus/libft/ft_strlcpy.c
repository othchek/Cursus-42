/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:04:32 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/18 17:12:36 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t ft_strlcpy(char *dest, const char *src, const size_t len)
{
    size_t i = 0;

    /* Always copy 1 less then the destination to make room for the nul */
    for(i = 0; i < len - 1; i++)
    {
        /* only copy up to the first nul is reached */
        if(*src != '\0') {
            *dest++ = *src++;
        }
        else {
            break;
        }
    }

    /* nul terminate the string */
    *dest = '\0';

    /* Return the number of bytes copied */
    return i;
}