/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:38 by otchekai          #+#    #+#             */
/*   Updated: 2022/12/28 11:28:26 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr1(int signum)
{
	(void)signum;
	ft_printf("1");
}
void	handler_sigusr2(int signum)
{
	(void)signum;
	ft_printf("0");
}

int	main(void)
{
   pid_t	pid;

   pid = getpid();
   printf("Server PID: %d\n", pid);
   signal(SIGUSR1, handler_sigusr1);
   signal(SIGUSR2, handler_sigusr2);
   while (1)
   	pause();
}