/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:10:27 by otchekai          #+#    #+#             */
/*   Updated: 2022/10/12 13:13:41 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
 
#define  BUF_SIZE  20
 
int main(void)
{
   char buffer[BUF_SIZE + 1];
   char *string;
 
   memset(buffer, 0, sizeof(buffer));
   string = (char *) memset(buffer,'C', 10);
   printf("\nBuffer contents: %s\n", string);
   memset(buffer+10, 'A', 10);
   printf("\nBuffer contents: %s\n", buffer);
}
