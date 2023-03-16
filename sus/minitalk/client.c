/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:35 by otchekai          #+#    #+#             */
/*   Updated: 2023/03/16 11:44:14 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	wladianayawladi(int *bits, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		bits[i] = c % 2;
		c /= 2;
		i--;
	}
}

void	send_characters(int pid, char c)
{
	int	i;
	int	nejma[8];

	i = 7;
	HAHAHA_CHAMBOO(nejma, c);
	while (i >= 0)
	{
		if (nejma[i] == 1)
			kill(pid, SIGUSR2);
		else if (nejma[i] == 0)
			kill(pid, SIGUSR1);
		i--;
	}
	usleep(800);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	(void)ac;
	i = 0;
	pid = atoi(av[1]);
	while (av[2][i])
	{
		send_characters(pid, av[2][i]);
		i++;
	}
}
