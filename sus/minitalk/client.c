/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:35 by otchekai          #+#    #+#             */
/*   Updated: 2023/01/04 08:10:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void receive_message(int sig_id)
{
    (void)sig_id;
}

void send_character(int pid, unsigned char c)
{
	int index;

	index = 8;
	while(index--)
	{
		if (c >> index & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		usleep(100);
	}
}

void	send_message(int pid, char *str)
{
	int index;

	index = 0;
	while(str[index])
	{
		send_character(pid, str[index]);
		index++;
	}
}

int main(int ac, char **av)
{
	int	pid;
	
	if (ac != 3)
	{	ft_putstr_fd("Invalid argument: ./client <pid> (message)\n", 1);
			return (0);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR2, receive_message);
	send_message(pid, av[2]);
	return (0);
}