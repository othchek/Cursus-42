/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:49:49 by otchekai          #+#    #+#             */
/*   Updated: 2023/03/17 17:28:52 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_characters(int pid, char c)
{
	int	i;
	int shifter;

	i = 7;
	while (i >= 0)
	{
		shifter = (c >> i & 1);
		if (shifter == 1)
			if (kill(pid, SIGUSR2) == -1)
				exit(0);
		if (shifter == 0)
			if (kill(pid, SIGUSR1) == -1)
				exit(0);
		i--;
		usleep(800);
	}
}

static void write_characters(int pid, char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		send_characters(pid, str[index]);
		index++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		if (pid <= 0)
			exit(0);
		write_characters(pid, av[2]);
	}
	else
		ft_putstr_fd("Argument Error\n", 2);
}