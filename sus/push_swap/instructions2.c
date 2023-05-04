/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:25:46 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 21:59:21 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_rr(t_push **heada, t_push **headb, t_print **headc, int i)
{
	inst_ra(heada, headc, 0);
	inst_rb(headb, headc, 0);
	if (i)
		ft_lstadd_back2(headc, lst_new2("rr\n"));
	return ;
}

void	inst_rra(t_push **lst, t_print **headc, int i)
{
	if (!(*lst))
		return ;
	(*lst) = (*lst)->prev;
	if (i)
		ft_lstadd_back2(headc, lst_new2("rra\n"));
	return ;
}

void	inst_rrb(t_push **lst, t_print **headc, int i)
{
	if (!(*lst))
		return ;
	(*lst) = (*lst)->prev;
	if (i)
		ft_lstadd_back2(headc, lst_new2("rrb\n"));
	return ;
}

void	inst_rrr(t_push **heada, t_push **headb, t_print **headc, int i)
{
	inst_rra(heada, headc, 0);
	inst_rrb(headb, headc, 0);
	if (i)
		ft_lstadd_back2(headc, lst_new2("rrr\n"));
	return ;
}
