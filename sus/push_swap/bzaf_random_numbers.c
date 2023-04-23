/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzaf_random_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:09:43 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/23 16:57:11 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_khundred_numbers(t_push **heada, t_push **headb)
{
	int		size;
	int		start;
	int		i;
	int		purpose;

	start = 0;
	size = 55;
	i = 11;
	cookielolxx(heada);
	while (i--)
	{
		purpose = ft_lstsize(*heada);
		while (purpose--)
		{
			if ((*heada)->index >= start && (*heada)->index <= size)
			{
				if ((*heada)->index <= (start + size) / 2)
					inst_pb(heada, headb, 1);
				else
				{
					inst_pb(heada, headb, 1);
					inst_rb(headb, 1);
				}
			}
			else
				inst_ra(heada, 1);
		}
		start += 55;
		size += 55 ;
	}
}

void	 khundred_numbers(t_push **heada, t_push **headb)
{
	int		size;
	int start;
	int i;

	start = 0;
	size = 19;
	i = 5;
	int a ;
	cookielolxx(heada);	
	while (i--)
	{
		a = ft_lstsize(*heada);
		while (a--)
		{
			if ((*heada)->index >= start && (*heada)->index <= size)
			{
				if ((*heada)->index <= (start + size) / 2)
					inst_pb(heada, headb, 1);
				else
				{
					inst_pb(heada, headb, 1);
					inst_rb(headb, 1);
				}
			}
			else
				inst_ra(heada, 1);
		}
		start += 20;
		size += 20 ;
	}
}

void	push_it_back(t_push **heada, t_push **headb)
{
	int	devide;
	int	size;

	size = ft_lstsize(*headb) - 1;
	while (size >= 0)
	{
		devide = ft_lstsize(*headb) / 2;
		if (!max(headb, devide, size))
		{
			while ((*headb)->index != size)
				inst_rb(headb, 1);
			inst_pa(heada, headb, 1);
		}
		else
		{
			while ((*headb)->index != size)
				inst_rrb(headb, 1);
			inst_pa(heada, headb, 1);
		}
		size--;
	}
}
