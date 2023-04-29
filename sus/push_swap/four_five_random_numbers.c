/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_random_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:17:30 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 21:32:36 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flower_in_the_dawn(t_push **heada, t_push **headb, t_print **headc)
{
	cookielolxx(heada);
	if ((*heada)->index == 0)
		inst_pb(heada, headb, headc, 1);
	else if ((*heada)->next->index == 0)
	{
		inst_ra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
	else if ((*heada)->next->next->index == 0)
	{
		inst_rra(heada, headc, 1);
		inst_rra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
	else
	{
		inst_rra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
	three_numbers(heada, headc);
	inst_pa(heada, headb, headc, 1);
}

void	pd(t_push **heada, t_push **headb, t_print **headc)
{
	cookielolxx(heada);
	if ((*heada)->index == 0)
		inst_pb(heada, headb, headc, 1);
	else if ((*heada)->next->index == 0)
	{
		inst_ra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
	else if ((*heada)->next->next->index == 0)
	{
		inst_ra(heada, headc, 1);
		inst_ra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
	else if ((*heada)->prev->prev->index == 0)
	{
		inst_rra(heada, headc, 1);
		inst_rra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
	else
	{
		inst_rra(heada, headc, 1);
		inst_pb(heada, headb, headc, 1);
	}
}

void	reformed_five(t_push **heada, t_push **headb, t_print **headc)
{
	pd(heada, headb, headc);
	pd(heada, headb, headc);
	three_numbers(heada, headc);
	inst_pa(heada, headb, headc, 1);
	inst_pa(heada, headb, headc, 1);
}
