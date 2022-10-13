/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:10:27 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/13 02:16:58 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
   int i;
   unsigned char *str;
   str = (unsigned char *)b;
   
   
   i = 0;
   while(i < len)
   {
      str[i] = (unsigned char)c;
      i++;     
   }
   return(str);
}