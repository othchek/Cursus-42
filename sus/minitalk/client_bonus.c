/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:49:49 by otchekai          #+#    #+#             */
/*   Updated: 2023/01/04 18:06:22 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	receive_message(int signal)
{
	(void)signal;
}

void	send_character(int pid, unsigned char c)
{
	int	shifter;

	shifter = 0x80;
	while (shifter)
	{
		if (c & shifter)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		usleep(200);
		shifter >>= 1;
	}
}

static void	send_message(int pid, char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		send_character(pid, str[index]);
		index++;
	}
	send_character(pid, '\n');
	send_character(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{	
		ft_putstr_fd("Arguments error: ./client <pid> (message)\n", 1);
		exit(0);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR2, receive_message);
	send_message(pid, av[2]);
	return (0);
}
