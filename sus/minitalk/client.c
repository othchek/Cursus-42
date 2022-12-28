/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:35 by otchekai          #+#    #+#             */
/*   Updated: 2022/12/28 11:34:59 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char *str, int pid)
{
   int	index;
   int	shifter;

   shifter = 0;
   index = 0;
   while (str[index])
   {
   		while (shifter < 8)
   		{
   			if (str[index] & 0x80 >>shifter)
   				kill(pid, SIGUSR2);
   			else
   				kill(pid, SIGUSR1);
   			usleep(3);
			shifter++;
   		}
   		index++;
   }
   
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		printf("Client: invalid argument");
	}
	pid = atoi(argv[1]);
	send_signal(argv[2], pid);
	return (0);
}