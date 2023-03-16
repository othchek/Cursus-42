/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/03/16 11:43:28 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	they_call_me_names(int *tabnaux)
{
	int	fat;
	int	hard_r;
	int	obese;
	int	power;
	int	i;

	i = 0;
	fat = 7;
	hard_r = 0;
	obese = 0;
	while (fat >= 0)
	{
		power = 1;
		while (i < fat)
		{
			power *= 2;
			i++;
		}
		obese += power * tabnaux[hard_r];
		fat--;
		hard_r++;
	}
	return (obese);
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
	if (num == SIGUSR2)
		c = c | 0x80 >> i;
	i++;
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
