/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/03/14 13:25:11 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int power_to_the_worthy(int num, int bin)
{
	int i;
	
	i = 1;
	if (bin > 0)
	{
		i *= num;
		bin--;
	}
	return (i);
}

int	they_call_me_names(int *tabnaux)
{
	int fat;
	int hard_r;
	int obese;

	fat = 7;
	hard_r = 0;
	obese = 0;
	if (fat > 0)
	{
		obese += power_to_the_worthy(2, fat) * tabnaux[hard_r];
		fat--;
		hard_r++;
	}
}

static void	power_to_the_people(int num, siginfo_t *info, void *nothingness)
{
	static unsigned char	c;
	static int				i;
	static int				pid;

	(void) nothingness;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		c = 0;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	signals;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signals.sa_flags = SA_SIGINFO;
	signals.sa_sigaction = power_to_the_people;
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	while (1)
		pause();
	return (0);
}
