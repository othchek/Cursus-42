/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:50:22 by otchekai          #+#    #+#             */
/*   Updated: 2023/03/20 11:26:31 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	power_to_the_people(int num, siginfo_t *info, void *nothingness)
{
	static char				c;
	static int				i;
	static int				pid;

	(void) nothingness;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		c = 0;
	}
	if (num == SIGUSR2)
		c = c | 0x80 >> i;
	i++;
	if (i == 8)
	{
		if ((int)c == 125)
			kill(info->si_pid, SIGUSR1);
		else
		{
			write(1, &c, 1);
			c = 0;
			i = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	signals;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signals.sa_sigaction = power_to_the_people;
	signals.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	ft_putstr_fd("Waiting for signals...\n", 1);
	while (1)
		pause();
}
