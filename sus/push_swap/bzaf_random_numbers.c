/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzaf_random_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:09:43 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 22:56:13 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm(t_push **heada, t_push **headb, t_print **headc, int i)
{
	t_push	*head;

	head = (*heada);
	if (i == 1)
		inst_pb(heada, headb, headc, 1);
	else if (i == 2)
	{
		inst_pb(heada, headb, headc, 1);
		inst_rb(headb, headc, 1);
	}
}

void	five_khundred_numbers(t_push **heada, t_push **headb,
		t_print **headc, int size)
{
	int		start;
	int		i;
	int		purpose;

	start = 0;
	i = 11;
	while (i--)
	{
		purpose = ft_lstsize(*heada);
		while (purpose--)
		{
			if ((*heada)->index >= start && (*heada)->index <= size)
			{
				if ((*heada)->index <= (start + size) / 2)
					norm(heada, headb, headc, 1);
				else
					norm(heada, headb, headc, 2);
			}
			else
				inst_ra(heada, headc, 1);
		}
		start += 55;
		size += 55;
	}
}

void	khundred_numbers(t_push **heada, t_push **headb,
		t_print **headc, int size)
{
	int	start;
	int	i;
	int	purpose;

	start = 0;
	i = 5;
	while (i--)
	{
		purpose = ft_lstsize(*heada);
		while (purpose--)
		{
			if ((*heada)->index >= start && (*heada)->index <= size)
			{
				if ((*heada)->index <= (start + size) / 2)
					norm(heada, headb, headc, 1);
				else
					norm(heada, headb, headc, 2);
			}
			else
				inst_ra(heada, headc, 1);
		}
		start += 20;
		size += 20 ;
	}
}

void	push_it_back(t_push **heada, t_push **headb, t_print **headc)
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
				inst_rb(headb, headc, 1);
			inst_pa(heada, headb, headc, 1);
		}
		else
		{
			while ((*headb)->index != size)
				inst_rrb(headb, headc, 1);
			inst_pa(heada, headb, headc, 1);
		}
		size--;
	}
}
