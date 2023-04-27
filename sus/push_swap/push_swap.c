/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:25:01 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/27 01:14:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_push **heada, t_push **headb)
{
	if (ft_lstsize(*heada) == 100)
	{
		cookielolxx(heada);
		khundred_numbers(heada, headb, 19);
		cookielolxx(headb);
		push_it_back(heada, headb);
	}
	if (ft_lstsize(*heada) == 500)
	{
		cookielolxx(heada);
		five_khundred_numbers(heada, headb, 55);
		cookielolxx(headb);
		push_it_back(heada, headb);
	}
}

void	sort_stack(t_push **heada, t_push **headb)
{
	if (ft_lstsize(*heada) == 2)
		inst_ra(heada, 1);
	if (ft_lstsize(*heada) == 3)
		three_numbers(heada);
	if (ft_lstsize(*heada) == 4)
		flower_in_the_dawn(heada, headb);
	if (ft_lstsize(*heada) == 5)
		reformed_five(heada, headb);
}

void	allfree(char **str)
{
	int		k;

	k = 0;
	while (str[k])
	{
		free(str[k]);
		k++;
	}
	free(str);
}

void	funn(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	// atexit(funn);
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
		sort_big(&heada, &headb);
		allfree(split);
		ft_lstclear(&heada);
	}
	else
		ft_error("Error\nArgument Error!");
}
