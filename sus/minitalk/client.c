/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:35 by otchekai          #+#    #+#             */
/*   Updated: 2022/12/26 16:50:21 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
   int	pid;

   if (argc != 2)
   {
   	printf("client: invalid arguments\n");
   	exit(EXIT_FAILURE);
   }
   pid = atoi(argv[1]);
   kill(pid, SIGUSR1);
   return (0);
}