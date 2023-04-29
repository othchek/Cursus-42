/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:25:46 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 19:54:00 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_rr(t_push **heada, t_push **headb, int i)
{
	inst_ra(heada, 0);
	inst_rb(headb, 0);
	if (i)
		write(1, "rr\n", 3);
	return ;
}

void	inst_rra(t_push **lst, int i)
{
	if (!(*lst))
		return ;
	(*lst) = (*lst)->prev;
	if (i)
		write(1, "rra\n", 4);
	return ;
}

void	inst_rrb(t_push **lst, int i)
{
	if (!(*lst))
		return ;
	(*lst) = (*lst)->prev;
	if (i)
		write(1, "rrb\n", 4);
	return ;
}

void	inst_rrr(t_push **heada, t_push **headb, int i)
{
	inst_rra(heada, 0);
	inst_rrb(headb, 0);
	if (i)
		write(1, "rrr\n", 1);
	return ;
}
