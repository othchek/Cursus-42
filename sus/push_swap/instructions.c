/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:40:05 by otchekai          #+#    #+#             */
/*   Updated: 2023/04/29 21:15:23 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_sa(t_push **lst, t_print **headc, int i)
{
	int	index;

	index = 0;
	if (ft_lstsize(*lst) < 2)
		return ;
	index = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = index;
	if (i)
		ft_lstadd_back2(headc, lst_new2("sa\n"));
	return ;
}

void	inst_sb(t_push **lst, t_print **headc, int i)
{
	int	index;
	int	purpose;

	index = 0;
	purpose = ft_lstsize(*lst);
	if (purpose < 2)
		return ;
	index = (*lst)->data;
	(*lst)->data = (*lst)->next->data;
	(*lst)->next->data = index;
	if (i)
		ft_lstadd_back2(headc, lst_new2("sb\n"));
	return ;
}

void	inst_ss(t_push **heada, t_push **headb, t_print **headc, int i)
{
	int	index;

	index = 0;
	inst_sa(heada, headc, i);
	inst_sb(headb, headc, i);
	if (i)
		ft_lstadd_back2(headc, lst_new2("ss\n"));
	return ;
}

void	inst_ra(t_push **lst, t_print **headc, int i)
{
	if (ft_lstsize(*lst) < 2)
		return ;
	(*lst) = (*lst)->next;
	if (i)
		ft_lstadd_back2(headc, lst_new2("ra\n"));
	return ;
}

void	inst_rb(t_push **lst, t_print **headc, int i)
{
	if (ft_lstsize(*lst) < 2)
		return ;
	(*lst) = (*lst)->next;
	if (i)
		ft_lstadd_back2(headc, lst_new2("rb\n"));
	return ;
}
