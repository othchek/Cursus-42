/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:14:47 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/18 17:15:14 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>


size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  lsize;
    size_t  dsize;

    lsize = 0;
    dsize = strlen(dst);
    while (*dst && size > 0 && size--)
    {
        dst++;
        lsize++;
    }
    while (*src && size > 1 && size--)
        *dst++ = *src++;
    if (size == 1)
        *dst = '\0';
    return (dsize + lsize);
}