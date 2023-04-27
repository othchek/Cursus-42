/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:25:46 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/27 00:32:09 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_rr(t_push **heada, t_push **headb, int i)
{
	if (i)
		write(1, "rr\n", 3);
	inst_ra(heada, 0);
	inst_rb(headb, 0); 
	return ;
}

void	inst_rra(t_push **lst, int i)
{
	if (i)
		write(1, "rra\n", 4);
	(*lst) = (*lst)->prev;
	return ;
}

void	inst_rrb(t_push **lst, int i)
{
	if (i)
		write(1, "rrb\n", 4);
	(*lst) = (*lst)->prev;
	return ;
}

void	inst_rrr(t_push **heada, t_push **headb, int i)
{
	if (i)
		write(1, "rrr\n", 1);
	inst_rra(heada, i);
	inst_rrb(headb, i);
	return ;
}
