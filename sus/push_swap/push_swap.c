/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:25:01 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 22:55:09 by otchekai         ###   ########.fr       */
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
	if (ft_lstsize(*heada) <= 500 && ft_lstsize(*heada) > 100)
	{
		cookielolxx(heada);
		five_khundred_numbers(heada, headb, headc, 55);
		cookielolxx(headb);
		push_it_back(heada, headb, headc);
	}
}

void	sort_stack(t_push **heada, t_push **headb, t_print **headc)
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

int	main(int ac, char **av)
{
	int		i;
	char	**split;
	t_push	*heada;
	t_push	*headb;
	t_print	*print;
	t_print	*oldprint;

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
		norminette(&heada, &headb, &print);
		allfree(split);
		ft_lstclear(&heada);
		oldprint = print;
		while (oldprint)
		{
			if ((!ft_strncmp("ra\n", oldprint->data, 3) && \
				oldprint->next && !ft_strncmp("rb\n", oldprint->next->data, 3))
				|| (!ft_strncmp("rb\n", oldprint->data, 3)
					&& oldprint->next
					&& !ft_strncmp("ra\n", oldprint->next->data, 3)))
			{
				printf("rr\n");
				oldprint = oldprint->next;
			}
			else
				printf("%s", oldprint->data);
			oldprint = oldprint->next;
		}
	}
	else
		ft_error("Error\nArgument Error!");
}
