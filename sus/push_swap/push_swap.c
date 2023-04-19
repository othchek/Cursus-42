/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:25:01 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/19 16:53:41 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_push **heada, t_push **headb)
{
	if (ft_lstsize(*heada) == 2 && (*heada)->data > (*heada)->next->data)
		inst_ra(heada, 1);
	if (ft_lstsize(*heada) == 3)
	{		
		sorted(heada);
		three_numbers(heada);
	}
	if (ft_lstsize(*heada) == 4)
		flower_in_the_dawn(heada, headb);
	else
		return ;
}

int	main(int ac, char **av)
{
	int		i;
	char	**split;
	t_push	*heada;
	t_push	*headb;

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
		sort_stack(&heada, &headb);
	}
	else
		ft_error("Error\nArgument Error!");
}
