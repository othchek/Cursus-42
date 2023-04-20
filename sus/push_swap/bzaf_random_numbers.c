/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzaf_random_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:09:43 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/20 17:19:54 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
