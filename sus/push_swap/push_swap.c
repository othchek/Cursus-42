/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:25:01 by otchekai          #+#    #+#             */
/*   Updated: 2023/05/05 15:56:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_push **heada, t_push **headb, t_print **headc)
{
	if (ft_lstsize(*heada) <= 100 && ft_lstsize(*heada) > 5)
	{
		cookielolxx(heada);
		khundred_numbers(heada, headb, headc, 19);
		cookielolxx(headb);
		push_it_back(heada, headb, headc);
	}
	else if (ft_lstsize(*heada) >= 101)
	{
		cookielolxx(heada);
		five_khundred_numbers(heada, headb, headc, 55);
		cookielolxx(headb);
		push_it_back(heada, headb, headc);
	}
}

void	sort_stack(t_push **heada, t_push **headb, t_print **headc)
{
	if (ft_lstsize(*heada) != 1)
	{
		if (ft_lstsize(*heada) == 2)
			inst_ra(heada, headc, 1);
		if (ft_lstsize(*heada) == 3)
			three_numbers(heada, headc);
		if (ft_lstsize(*heada) == 4)
			flower_in_the_dawn(heada, headb, headc);
		if (ft_lstsize(*heada) == 5)
			reformed_five(heada, headb, headc);
	}
}

void	norminette(t_push **heada, t_push **headb, t_print **headc)
{
	if (!is_sorted(heada))
	{
		sort_stack(heada, headb, headc);
		sort_big(heada, headb, headc);
	}
	else if (is_sorted(heada) == 1)
		exit(0);
}

void	gg(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	// atexit(gg);
	t_list	oth;
	t_push	*heada;
	t_push	*headb;
	t_print	*print;
	t_print	*print2;

	heada = NULL;
	print2 = NULL;
	oth.i = 1;
	if (ac > 1)
	{
		while (av[oth.i])
			max_or_min(av[oth.i++]);
		oth.split = kill_to_flourish(av);
		oth.i = 0;
		while (oth.split[oth.i])
			ft_lstadd_back(&heada, lst_new(ft_atoi(oth.split[oth.i++])));
		norminette(&heada, &headb, &print);
		normanitte(print, print2);
		allfree(oth.split);
		ft_lstclear(&heada);
		ft_clear_lst(&print);
		ft_clear_lst(&print2);
	}
	else
		exit(1);
}
