/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:25:01 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/16 15:32:46 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**split;
	t_push	*heada;
	t_push	*headb;
	t_push	*head;

	head = NULL;
	i = 1;
	heada = NULL;
	headb = NULL;
	if (ac > 1)
	{
		while (av[i])
			max_or_min(av[i++]);
		split = kill_to_flourish(av);
		i = 0;
		while (split[i])
		{
			ft_lstadd_back(&heada, lst_new(ft_atoi(split[i])));
			i++;
		}
		three_numbers(&heada);
		head = heada;
		while (head)
		{
			printf("Data = %d\n", head->data);
			head = head->next;
			if (head == heada)
				break ;
		}
	}
	else
		ft_error("Error\nArgument Error!");
}
