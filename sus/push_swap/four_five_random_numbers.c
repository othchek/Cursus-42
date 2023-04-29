/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_random_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:17:30 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 16:59:15 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flower_in_the_dawn(t_push **heada, t_push **headb)
{
	cookielolxx(heada);
	if ((*heada)->index == 0)
		inst_pb(heada, headb, 1);
	else if ((*heada)->next->index == 0)
	{
		inst_ra(heada, 1);
		inst_pb(heada, headb, 1);
	}
	else if ((*heada)->next->next->index == 0)
	{
		inst_rra(heada, 1);
		inst_rra(heada, 1);
		inst_pb(heada, headb, 1);
	}
	else
	{
		inst_rra(heada, 1);
		inst_pb(heada, headb, 1);
	}
	three_numbers(heada);
	inst_pa(heada, headb, 1);
}

void	pd(t_push **heada, t_push **headb)
{
	cookielolxx(heada);
	if ((*heada)->index == 0)
		inst_pb(heada, headb, 1);
	else if ((*heada)->next->index == 0)
	{
		inst_ra(heada, 1);
		inst_pb(heada, headb, 1);
	}
	else if ((*heada)->next->next->index == 0)
	{
		inst_ra(heada, 1);
		inst_ra(heada, 1);
		inst_pb(heada, headb, 1);
	}
	else if ((*heada)->prev->prev->index == 0)
	{
		inst_rra(heada, 1);
		inst_rra(heada, 1);
		inst_pb(heada, headb, 1);
	}
	else
	{
		inst_rra(heada, 1);
		inst_pb(heada, headb, 1);
	}
}

void	reformed_five(t_push **heada, t_push **headb)
{
	pd(heada, headb);
	pd(heada, headb);
	three_numbers(heada);
	inst_pa(heada, headb, 1);
	inst_pa(heada, headb, 1);
}
